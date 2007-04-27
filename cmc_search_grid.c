/* -*- linux-c -*- */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <gsl/gsl_integration.h>
#include "cmc.h"
#include "cmc_vars.h"


struct Search_Grid *
search_grid_initialize(double power_law_exponent, double fraction, long starsPerBin, double part_frac) {
  /* This is somewhat trivial at the moment but makes the usage of the 
   * Search_Grid structure clearer. */
  struct Search_Grid *grid;
  
  grid= (struct Search_Grid *) malloc(sizeof(struct Search_Grid));

  grid->radius=NULL;
  grid->length=0;
  grid->max_length= 1000000;
  grid->power_law_exponent= power_law_exponent;
  grid->starsPerBin= starsPerBin;
  grid->fraction= fraction;
  grid->particle_fraction= part_frac;

  return(grid);
};

/* This function is mainly used internally, but may be useful for the user */
double search_grid_estimate_prop_const(struct Search_Grid *grid) {
  long i, r_index;
  double coeff, r_1, r_min;
  
  /* determine interpol_coeff using the radius of the particle 
   * with index clus.N_MAX* fraction */
  i= clus.N_MAX*grid->fraction;
  r_1= star[i].r;
  r_min= star[1].r;
  r_index= clus.N_MAX/grid->starsPerBin*grid->fraction;
  coeff= (r_1-r_min)/pow(r_index, grid->power_law_exponent);

  return(coeff);
};

/* This function is only used internally (i.e. private) and does not 
 * belong to the public API */
void search_grid_allocate(struct Search_Grid *grid) {
  long prev_grid_length, max_part_index;

  /* save the previous grid length to determine if we later need to allocate 
   * more space */
  prev_grid_length= grid->length;

  /* calculate the required length of the search grid so that almost all star radii are within it*/
  max_part_index= (long) (clus.N_MAX* grid->particle_fraction);
  grid->length= search_grid_get_grid_index(grid, star[max_part_index].r);
  if (grid->length< grid->min_length) 
    grid->length= grid->min_length;

  if (grid->length> grid->max_length) {
    printf("Warning: For the given parameters we cannot construct a search grid that contains all\n");
    printf("Warning: stars, so the last search bin contains significantly more particles than\n");
    printf("Warning: anticipated in the variable starsPerBin (%li).\n",
        grid->starsPerBin);
    grid->length= grid->max_length;
  }

  /* allocate the search grid */
  if (prev_grid_length< grid->length) {
    if (grid->radius) {
      free(grid->radius);
      grid->radius= NULL;
    };

    grid->radius= (long *) calloc((size_t)(grid->length), sizeof(long));
  };
};
  
void search_grid_update(struct Search_Grid *grid) {
  long i, r_index, star_index;
  
  grid->interpol_coeff= search_grid_estimate_prop_const(grid);
  search_grid_allocate(grid);

  printf("# grid length is %li\n", grid->length);

  r_index=0;
  for (i=2; i<=clus.N_MAX; i++) {
    star_index= search_grid_get_grid_index(grid, star[i].r);
    if (star_index<grid->length) {
      grid->radius[star_index]= i;
      for (;r_index<star_index; r_index++) {
        grid->radius[r_index+1]= i;
      }
    } else {
      for (;r_index<grid->length-1; r_index++)
        grid->radius[r_index+1]= i;
    };
  };
};

/* This function gives only the approximate radius of the search grid
 * at index "index" and cannot be used to infer the right search interval,
 * due to round-off errors.*/
double search_grid_get_r(struct Search_Grid *grid, long index) {
  if (index> grid->length-1) {
    index=grid->length-1;
  };
  return(star[1].r+ grid->interpol_coeff*pow(index+1., grid->power_law_exponent));
};

/* Returns the interval of particle indices such that star[min].r>r>star[max].r*/
struct Interval
search_grid_get_interval(struct Search_Grid *grid, double r) {
  long grid_index;
  struct Interval sindex;

  grid_index= search_grid_get_grid_index(grid, r);
  if (grid_index>= grid->length) {
    sindex.min= grid->radius[grid->length-1];
    if (r> star[clus.N_MAX].r) {
      sindex.max= clus.N_MAX;
    } else {
      sindex.max= clus.N_MAX-1;
    };
  } else if (grid_index==0) {
    sindex.min= 2;
    sindex.max= grid->radius[0];
  } else {
    sindex.min= grid->radius[grid_index-1];
    sindex.max= grid->radius[grid_index];
  };

  /* Sometimes r can be in between the grid boundary and the radius of the 
   * largest or smallest particle radius*/ 
  sindex.max++;
  sindex.min--;

  return(sindex);
};

long search_grid_get_grid_index(struct Search_Grid *grid, double r) {
  double r_to_n, n, ind_double;
  const double long_max= LONG_MAX;
  long ind;

  n= grid->power_law_exponent;
  r_to_n= (r-star[1].r)/grid->interpol_coeff;
  //ind_double= floor(exp(log(r_to_n)/n));
  ind_double= floor(r_to_n*r_to_n);
  if (ind_double> long_max) {
    ind= LONG_MAX;
  } else {
    ind= (long) ind_double;
  };
  return (ind);
};

double search_grid_get_grid_indexf(struct Search_Grid *grid, double r) {
  double r_to_n, n, ind;

  n= grid->power_law_exponent;
  r_to_n= (r-star[1].r)/grid->interpol_coeff;
  ind= (pow(r_to_n, 1./n));
  return (ind);
}

void search_grid_free(struct Search_Grid *grid) {
  if (grid && grid->radius) {
    free(grid->radius);
    grid->radius= NULL;
  }
  if (grid) {
    free(grid);
    grid= NULL;
  }
};
