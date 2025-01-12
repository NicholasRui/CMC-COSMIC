.. _inifile:

###########################
Configuration files for CMC
###########################

How to write a configuration file
=================================

The `cmc` command-line executable cannot run without a configuration file.

Here is a link to the most recent stable release version of the default
inifile for CMC: `Stable Version INIFILE <https://github.com/COSMIC-PopSynth/COSMIC/blob/master/examples/Params.ini>`_

Here is a link to the unstable development version of the default inifile for CMC: `Development Version INIFILE <https://github.com/COSMIC-PopSynth/COSMIC/blob/develop/examples/Params.ini>`_

[cmc]
-----

.. note::

    Although this is all one section, we have grouped the
    flags/parameters which get passed to the binary stellar evolution
    code into types. Each group will start with a note to indicate
    the type of parameter or flag.


.. _snapshotting:

.. note::

    SNAPSHOT FLAGS

===============================  =====================================================
``SNAPSHOTTING``                 Turn snapshotting on or of (doesn't control black hole snapshots below)

``SNAPSHOT_DELTACOUNT``          How many timesteps to write a snapshot

``BH_SNAPSHOTTING``              Turn on snapshots for just the black holes

``BH_SNAPSHOT_DELTACOUNT``       write the black hole snapshots every X timesteps

``SNAPSHOT_CORE_COLLAPSE``       write additional snapshots around core collapse (in the mains snapshot file)

``SNAPSHOT_WINDOWS``             2

``SNAPSHOT_WINDOW_UNITS``        3
===============================  =====================================================

.. code-block:: ini

    ;;;;;;;;;;;;;;;;;;;;;;
    ;;; SNAPSHOT FLAGS ;;;
    ;;;;;;;;;;;;;;;;;;;;;;

    ; Turn snapshotting on or of (doesn't control black hole snapshots below)
    ; Default = 1 (on)
    SNAPSHOTTING = 1

    ; How many timesteps to write a snapshot
    ; default = 1000
    SNAPSHOT_DELTACOUNT = 1000

    ; Turn on snapshots for just the black holes
    ; default = 0 (off)
    BH_SNAPSHOTTING = 0

    ; write the black hole snapshots every X timesteps
    ; default = 500
    BH_SNAPSHOT_DELTACOUNT = 500

    ; write additional snapshots around core collapse (in the mains snapshot file)
    ; default = 0 (off)
    SNAPSHOT_CORE_COLLAPSE = 0

    ; write snapshots every X units of time
    ; The format is start_w0,step_w0,end_w0;start_w1,step_w1,stop_w1 ... etc
    ; note that SNAPSHOTTING must be on
    ; default = "0,0.1,13.8" (will write one snapshot to snapshot.h5 every 100 Myr) 
    SNAPSHOT_WINDOWS = 0,0.1,13.8

    ; units for snapshot windows
    ; options are:
    ; 	Gyr -- gigayears (default)
    ; 	Trel -- relaxation times
    ;	Tcr -- crossing times 
    SNAPSHOT_WINDOW_UNITS = Gyr

.. note::

    RELAXATION FLAGS

===============================  =====================================================
``CMC_GAMMA``                    Value of the Coulomb Logarithm (lambda = log(gamma*N))
                                 default = 0.01 (though use 0.1 for equal-mass clusters)

``THETASEMAX``                   Maximum value of theta during two-body encounters
===============================  =====================================================

.. code-block:: ini

    ;;;;;;;;;;;;;;;;;;;;;;;;
    ;;; RELAXATION FLAGS ;;;
    ;;;;;;;;;;;;;;;;;;;;;;;;

    ; Value of the Coulomb Logarithm (lambda = log(gamma*N))
    ; default = 0.01 (though use 0.1 for equal-mass clusters)
    CMC_GAMMA = 0.01

    ; Maximum value of theta during two-body encounters
    ; default = sqrt(2)
    THETASEMAX = 1.4142

.. note::

    DYNAMICS FLAGS

==================================  =====================================================
``BINBIN``                          Turn on Fewbody encounters between two binaries

``BINSINGLE``                       Turn on Fewbody encounters between binaries and single objects

``BH_CAPTURE``                      Turn on GW capture between single black holes

``THREEBODYBINARIES``               Turn on three-body binary formation  
                                    semi-analytic treatment from Morscher et al., 2013
                                    default = 1 (on)

``ONLY_FORM_BH_THREEBODYBINARIES``  1

``MIN_BINARY_HARDNESS``             2

``BINARY_BREAKING_MIN``             3

``SS_COLLISION``                    4

``TIDAL_CAPTURE``                   5

``BHNS_TDE``                        6
==================================  =====================================================

.. code-block:: ini

    ;;;;;;;;;;;;;;;;;;;;;;
    ;;; DYNAMICS FLAGS ;;;
    ;;;;;;;;;;;;;;;;;;;;;;

    ; Turn on Fewbody encoutners between two binaries  
    ; default = 1 (on)
    BINBIN = 1

    ; between binaries and single objects 
    ; default = 1 (on)
    BINSINGLE = 1

    ; Turn on GW capture between single black holes
    ; default = 1 (on)
    BH_CAPTURE = 1

    ; Turn on three-body binary formation  
    ; semi-analytic treatment from Morscher et al., 2013
    ; default = 1 (on)
    THREEBODYBINARIES = 1

    ; Only form three-body binaries with 3 black holes 
    ; default = 1 (on)
    ONLY_FORM_BH_THREEBODYBINARIES = 1

    ; Minimum hardness ratio for forming three-body binaries
    ; (or breaking wide binaries if BINARY_BREAKING_MIN = 1) 
    ; default = 1 (on)
    MIN_BINARY_HARDNESS = 5.0

    ; whether to use 10% of the interparticle seperation (0, default) 
    ; or MIN_BINARY_HARDNESS (1) as the criterion for breaking wide binaries
    BINARY_BREAKING_MIN = 0

    ; Enable two-body collisions between individual stars
    ; default = 1 (on)
    SS_COLLISION = 1

    ; Enable tidal captures bewteen individual stars
    ; Uses cross sections from Kim & Lee 1999 and Lombardi et al., 2006
    ; Only activated if SS_COLLISION = 1
    ; default = 0 (off)
    TIDAL_CAPTURE = 0

    ; Treat BH(NS)--MS TDEs in TDE vs direct collision limit (1=TDE, 0=coll)
    ; Follows prescription in Kremer et al., 2020
    ; default = 0 (coll)
    BHNS_TDE = 0


.. note::

    INPUT OPTIONS

===============================  =====================================================
``INPUT_FILE``                   the input hdf5 file for our intial conditions
                                 generated using COSMIC
===============================  =====================================================

.. code-block:: ini

    ;;;;;;;;;;;;;;;;;;;;;;
    ;;; INPUT OPTIONS  ;;;
    ;;;;;;;;;;;;;;;;;;;;;;

    ; the input hdf5 file for our intial conditions
    ; generated using COSMIC
    ; default = input.hdf5
    INPUT_FILE = input.hdf5

.. note::

    TIDAL FIELD OPTIONS

===============================  =====================================================
``TIDALLY_STRIP_STARS``          1

``TIDAL_TREATMENT``              2

``USE_TT_FILE``                  3

``TT_FILE``                      4
===============================  =====================================================

.. code-block:: ini

    ;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ;;; TIDAL FIELD OPTIONS ;;;
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;

    ; Tidally strip stars that pass the tidal boundary
    ; 0 = off, 1 = on (default)
    TIDALLY_STRIP_STARS = 1

    ; choose the tidal cut-off criteria 
    ; 0 = radial criteria
    ; 1=Giersz energy criteria (default)
    TIDAL_TREATMENT = 1

    ; whether to take the tidal boundary from a file (i.e. a tidal tensory)
    ; default = 0 (off)
    USE_TT_FILE=0

    ; name of tidal tensor file to take tidal bondary from
    ; should be formatted as Time [Myr] T_xx T_yy T_zz T_xy T_xz T_yz [1/Myr^2]
    TT_FILE = NULL

.. note::

    TERMINATION OPTIONS

================================  =====================================================
``T_MAX_PHYS``                    0

``T_MAX``                         1

``T_MAX_COUNT``                   3

``MAX_WCLOCK_TIME``               3

``CHECKPOINT_INTERVAL``           3

``CHECKPOINTS_TO_KEEP``           3

``TERMINAL_ENERGY_DISPLACEMENT``  3

``STOPATCORECOLLAPSE``            3

``USE_DF_CUTOFF``                 3

``DF_FILE``                       3

``DF_INTEGRATED_CRITERION``       3
================================  =====================================================

.. code-block:: ini

    ;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ;;; TERMINATION OPTIONS ;;;
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;

    ; maximum integration time (Gyr)
    ; default = 13.8 Gyr
    T_MAX_PHYS = 13.8

    ; maximum integration time (relaxation time)
    ; default = 100
    T_MAX = 100

    ; maximum number of timesteps
    ; default = 10000000
    T_MAX_COUNT = 10000000

    ; maximum amount of wallclock time to integrate for
    ; default = 604800 (seconds, i.e. 1 week)
    MAX_WCLOCK_TIME = 604800

    ; how often to save checkpoint files (seconds)
    ; default = 7200 (seconds, i.e. 2 hours)
    CHECKPOINT_INTERVAL = 7200

    ; how many previous checkpoints to keep at once
    ; default = 2
    CHECKPOINTS_TO_KEEP = 2

    ; energy change calculation stopping criterion (i.e. if e/e0 changes by this much, stop calculation)
    ; default = 10
    TERMINAL_ENERGY_DISPLACEMENT = 10

    ; stop once the cluster reaches core collapse (< 100 stars in core)
    ; default = 0 (off)
    STOPATCORECOLLAPSE = 0

    ; whether to compute a lifetime according to dynamical friction criterion
    ; this controls whether an external file is used
    ; default = 0 (off)
    USE_DF_CUTOFF=0

    ; name of dynamical friction file to use as potential termination criterion
    ; should be formatted as Time[Myr] Radius[Kpc] V_circ[km/s] M_enc[solMass] sigma[km/s] J[Kpc*km/s] 
    DF_FILE = NULL

    ; dynamical friction criterion to use for terminating the simulation
    ; when integral(dt/t_df) > 1 ( = 1) or when t_df > TotalTime ( = 0)
    DF_INTEGRATED_CRITERION = 1

.. note::

    OUTPUT OPTIONS

===============================  =====================================================
``MASS_PC``                      2

``MASS_BINS``                    3

``WRITE_EXTRA_CORE_INFO``        4

``WRITE_BH_INFO``                5

``WRITE_PULSAR_INFO``            6

``WRITE_MOREPULSAR_INFO``        7

``PULSAR_DELTACOUNT``            8

``WRITE_STELLAR_INFO``           9
===============================  =====================================================

.. code-block:: ini

    ;;;;;;;;;;;;;;;;;;;;;;
    ;;; OUTPUT OPTIONS ;;;
    ;;;;;;;;;;;;;;;;;;;;;;

    ; mass fractions for Lagrange radii
    MASS_PC = 0.0001,0.0003,0.0005,0.0007,0.0009,0.001,0.003,0.005,0.007,0.009,0.01,0.03,0.05,0.07,0.09,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,0.99

    ; mass ranges for calculating derived quantities 
    MASS_BINS = 0.1,1.0,10.0,100.0,1000.0

    ; Write out information about cores that are defined differently from the standard 
    ; default = 0 (off) 
    WRITE_EXTRA_CORE_INFO = 0

    ; Write out information about BHs each timestep, (0=off, 1=on)
    ; default = 0 (off)
    WRITE_BH_INFO = 0

    ; Write out information about pulsars (0=off, 1=on)
    ; default = 0 (off)
    WRITE_PULSAR_INFO = 0

    ; Write out information about neutron stars (0=off, 1=on)"
    ; default = 0 (off)
    WRITE_MOREPULSAR_INFO = 0;

    ; Pulsar output interval in time steps
    ; default = 1000
    PULSAR_DELTACOUNT = 1000

    ; Write out information about stellar evolution for each single and binary star, (0=off, 1=on)
    ; note this creates a HUGE amount of output
    ; default = 0 (off)
    WRITE_STELLAR_INFO = 0

.. note::

    CMC Parameters

===============================  =====================================================

===============================  =====================================================

.. code-block:: ini

    ;;;;;;;;;;;;;;;;;;;;;;
    ;;; CMC Parameters ;;;
    ;;;;;;;;;;;;;;;;;;;;;;
    ; don't touch these unless you know what you're doing

    ; one half the number of stars over which to average certain quantities
    ; default = 20
    AVEKERNEL = 20

    ; same as AVEKERNEL, but specifically for black holes (used for THREEBODYBINARIES)
    ; default = 3
    BH_AVEKERNEL = 3

    ; minimum size of chunks that get partitioned across processors in the parallel code
    ; default = 40
    MIN_CHUNK_SIZE = 40

    ; random number generator seed
    ; note this is different from the BSE random number seed
    IDUM = 1234 

    ; the random number seed used by kick.f and setting initial pulsar spin period and magnetic field.
    ; this is used specifically for BSE
    BSE_IDUM = 1234

    ; enable or disable timers 
    ; This returns a detailed profiling of the code, but uses barriers, so might slow down the code a bit.
    ; default = 0
    TIMER = 0

    ; force a relaxation step (useful when RELAXATION=0) (0=off, 1=on)
    ; default = 0
    FORCE_RLX_STEP = 0 

    ; calculate the binary interaction time steps by only considering hard binaries (0=off, 1=on)"
    ; default = 0
    DT_HARD_BINARIES = 0  

    ; The minimum binary binding energy (in units of kT) for a binary to be considered 'hard' for the time step calculation."
    HARD_BINARY_KT = 0.7

[bse]
-----

.. note::

    Although this is all one section, we have grouped the
    flags/parameters which get passed to the binary stellar evolution
    code into types. Each group will start with a note to indicate
    the type of parameter or flag.

.. note::

    SAMPLING FLAGS

=======================  =====================================================
``pts1``                 determines the timesteps chosen in each evolution phase as
                         decimal fractions of the time taken in that phase for
                         Main Sequence (MS) stars

                         **pts1 = 0.001** following `Bannerjee+2019 <https://ui.adsabs.harvard.edu/abs/2019arXiv190207718B/abstract>`_

``pts2``                 determines the timesteps chosen in each evolution phase as
                         decimal fractions of the time taken in that phase for
                         Giant Branch (GB, CHeB, AGB, HeGB) stars

                         **pts2 = 0.01** following `Hurley+2000 <https://ui.adsabs.harvard.edu/abs/2000MNRAS.315..543H/abstract>`_

``pts3``                 determines the timesteps chosen in each evolution phase as
                         decimal fractions of the time taken in that phase for
                         HG, HeMS stars

                         **pts3 = 0.02** following `Hurley+2000 <https://ui.adsabs.harvard.edu/abs/2000MNRAS.315..543H/abstract>`_
=======================  =====================================================

.. code-block:: ini

    ;;;;;;;;;;;;;;;;;;;;;;
    ;;; SAMPLING FLAGS ;;;
    ;;;;;;;;;;;;;;;;;;;;;;

    ; pts1,pts2,pts3 determine the timesteps chosen in each
    ;                 pts1 - MS                  (default=0.001, see Banerjee+ 2019)
    pts1=0.001
    ;                 pts2 - GB, CHeB, AGB, HeGB (default=0.01)
    pts2=0.01
    ;                 pts3 - HG, HeMS            (default=0.02)
    pts3=0.02

.. note::

    METALLICITY FLAGS

=======================  =====================================================
``zsun``                 Sets the metallicity of the Sun which primarily affects
                         stellar winds.

                         **zsun = 0.014** following `Asplund 2009 <https://ui.adsabs.harvard.edu/abs/2009ARA%26A..47..481A/abstract>`_
=======================  =====================================================

.. code-block:: ini

    ;;;;;;;;;;;;;;;;;;;;;;;;;
    ;;; METALLICITY FLAGS ;;;
    ;;;;;;;;;;;;;;;;;;;;;;;;;
    ; specify the value for Solar metallicity, which primarily affects
    ; winds in BSE
    ; default = 0.014 (Asplund 2009)
    zsun = 0.014


.. note::

    WIND FLAGS

=======================  =====================================================
``windflag``             Selects the model for wind mass loss for each star

                            ``0`` : Standard SSE/BSE (`Hurley+2000 <https://ui.adsabs.harvard.edu/abs/2000MNRAS.315..543H/abstract>`_)

                            ``1`` : StarTrack (`Belczynski+2008 <https://ui.adsabs.harvard.edu/abs/2008ApJS..174..223B/abstract>`_)

                            ``2`` : Metallicity dependence for O/B stars and Wolf Rayet stars (`Vink+2001 <http://adsabs.harvard.edu/abs/2001A&amp;A...369..574V>`_, `Vink+2005 <https://ui.adsabs.harvard.edu/abs/2005A%26A...442..587V/abstract>`_)

                            ``3`` : Same as 2, but LBV-like mass loss for giants
                            and non-degenerate stars beyond the
                            Humphreys-Davidson limit

                         **windflag = 3**

``eddlimflag``           Limits the mass-loss rate of low-metallicity stars near
                         the Eddington limit
                         (see `Grafener+2011 <https://ui.adsabs.harvard.edu/abs/2011A%26A...535A..56G/abstract>`_, `Giacobbo+2018 <https://ui.adsabs.harvard.edu/abs/2018MNRAS.474.2959G/abstract>`_).

                            ``0`` : does not apply Eddington limit

                            ``1`` : applies Eddington limit

                         **eddlimflag = 0**

``neta``                 Reimers mass-loss coefficent (`Equation 106 SSE <http://adsabs.harvard.edu/cgi-bin/nph-data_query?bibcode=2000MNRAS.315..543H&link_type=ARTICLE&db_key=AST&high=#page=19>`_).
                         Note: this equation has a typo. There is an extra
                         :math:`{\eta}` out front; the correct rate is directly proportional
                         to :math:`{\eta}`.
                         See also `Kurdritzki+1978, Section Vb <http://adsabs.harvard.edu/cgi-bin/nph-data_query?bibcode=1978A%26A....70..227K&link_type=ARTICLE&db_key=AST&high=#page=12>`_ for discussion.

                            ``positive value`` : supplies :math:`{\eta}` to `Equation 106 SSE <http://adsabs.harvard.edu/cgi-bin/nph-data_query?bibcode=2000MNRAS.315..543H&link_type=ARTICLE&db_key=AST&high=#page=19>`_

                         **neta = 0.5**

``bwind``                Binary enhanced mass loss parameter.
                         See `Equation 12 BSE <http://adsabs.harvard.edu/cgi-bin/nph-data_query?bibcode=2002MNRAS.329..897H&link_type=ARTICLE&db_key=AST&high=#page=3>`_.

                            ``positive value`` : supplies B\ :sub:`w` to `Equation 12 BSE <http://adsabs.harvard.edu/cgi-bin/nph-data_query?bibcode=2002MNRAS.329..897H&link_type=ARTICLE&db_key=AST&high=#page=3>`_

                         **bwind = 0, inactive for single**

``hewind``               Helium star mass loss parameter: 10\ :sup:`-13` *hewind* L\ :sup:`2/3` gives He star mass-loss. Equivalent to 1 - :math:`{\mu}` in the last equation on `page 19 of SSE <http://adsabs.harvard.edu/cgi-bin/nph-data_query?bibcode=2000MNRAS.315..543H&link_type=ARTICLE&db_key=AST&high=#page=19>`_.

                         **hewind = 0.5**

``beta``                 Wind velocity factor: v\ :sub:`wind` :sup:`2` goes like *beta*. See `Equation 9 of Hurley+2002 <http://adsabs.harvard.edu/cgi-bin/nph-data_query?bibcode=2002MNRAS.329..897H&link_type=ARTICLE&db_key=AST&high=#page=3>`_.

                            ``negative value`` : StarTrack (`Belczynski+2008 <https://ui.adsabs.harvard.edu/abs/2008ApJS..174..223B/abstract>`_)

                            ``positive value`` : supplies :math:`{\beta}`\ :sub:`w` to `Equation 9 of Hurley+2002 <http://adsabs.harvard.edu/cgi-bin/nph-data_query?bibcode=2002MNRAS.329..897H&link_type=ARTICLE&db_key=AST&high=#page=3>`_

                         **beta = -1.0**

``xi``                   Wind accretion efficiency factor, which gives the fraction
                         of angular momentum lost via winds from the primary that
                         transfers to the spin angular momentum of the companion.
                         Corresponds to :math:`{\mu}`\ :sub:`w` in `Equation 11 of Hurley+2002 <http://adsabs.harvard.edu/cgi-bin/nph-data_query?bibcode=2002MNRAS.329..897H&link_type=ARTICLE&db_key=AST&high=#page=3>`_.

                            ``positive value`` : supplies :math:`{\mu}`\ :sub:`w` in `Equation 11 of Hurley+2002 <http://adsabs.harvard.edu/cgi-bin/nph-data_query?bibcode=2002MNRAS.329..897H&link_type=ARTICLE&db_key=AST&high=#page=3>`_

                         **xi = 0.5**

``acc2``                 Bondi-Hoyle wind accretion factor where the mean wind accretion rate onto the secondary is proportional to *acc2*. See `Equation 6 in Hurley+2002 <http://adsabs.harvard.edu/cgi-bin/nph-data_query?bibcode=2002MNRAS.329..897H&link_type=ARTICLE&db_key=AST&high=#page=2>`_.

                            ``positive value`` : supplies :math:`{\alpha}`\ :sub:`w` in `Equation 6 in Hurley+2002 <http://adsabs.harvard.edu/cgi-bin/nph-data_query?bibcode=2002MNRAS.329..897H&link_type=ARTICLE&db_key=AST&high=#page=2>`_

                         **acc2 = 1.5**
=======================  =====================================================

.. code-block:: ini

    ;;;;;;;;;;;;;;;;;;
    ;;; WIND FLAGS ;;;
    ;;;;;;;;;;;;;;;;;;

    ; windflag sets the wind prescription
    ; windflag=0: stock BSE; windflag=1: StarTrack 2008
    ; windflag=2: Vink+2001; windflag=3: Vink+2005 (Vink plus LBV winds)
    ; default=3
    windflag=3

    ; neta is the Reimers mass-loss coefficent
    ; for more information, see Kudritzki & Reimers 1978, A&A 70, 227
    ; default=0.5
    neta = 0.5

    ; bwind is the binary enhanced mass loss parameter
    ; bwind it is always inactive for single stars
    ; default=0.0
    bwind = 0.0

    ; hewind is a helium star mass loss factor, between 0 and 1
    ; only applies if windflag=0, otherwise it is overwritten
    ; default=0.5
    hewind = 0.5

    ; beta is wind velocity factor: proportional to vwind^2
    ; beta<0: follows StarTrack 2008; beta=0.125: stock BSE
    ; default=0.125
    beta=0.125

    ; xi is the wind accretion efficiency factor, which gives the fraction of angular momentum lost via winds from the primary that transfers to the spin angular momentum of the companion
    ; default=1.0
    xi=1.0

    ; acc2 sets the Bondi-Hoyle wind accretion factor onto companion
    ; default=1.5
    acc2=1.5

.. note::

    COMMON ENVELOPE FLAGS

**Note:** there are cases where a common envelope is forced regardless of the
critical mass ratio for unstable mass transfer. In the following cases, a
common envelope occurs regardless of the choices below:

**contact** : the stellar radii go into contact (common for similar ZAMS systems)

**periapse contact** : the periapse distance is smaller than either of the stellar radii (common for highly eccentric systems)

**core Roche overflow** : either of the stellar radii overflow their component's Roche radius (in this case, mass transfer from the convective core is always dynamically unstable)

=======================  =====================================================
``alpha1``               Common-envelope efficiency parameter which scales the
                         efficiency of transferring orbital energy to the
                         envelope. See `Equation 71 in Hurley+2002 <http://adsabs.harvard.edu/cgi-bin/nph-data_query?bibcode=2002MNRAS.329..897H&link_type=ARTICLE&db_key=AST&high=#page=11>`_.

                            ``positive values`` : supplies :math:`{\alpha}` to `Equation 71 in Hurley+2002 <http://adsabs.harvard.edu/cgi-bin/nph-data_query?bibcode=2002MNRAS.329..897H&link_type=ARTICLE&db_key=AST&high=#page=11>`_

                         **alpha1 = 1.0**

``lambdaf``              Binding energy factor for common envelope evolution.
                         The initial binding energy of the stellar envelope
                         goes like 1 / :math:`{\lambda}`. See `Equation 69 in Hurley+2002 <http://adsabs.harvard.edu/cgi-bin/nph-data_query?bibcode=2002MNRAS.329..897H&link_type=ARTICLE&db_key=AST&high=#page=11>`_.

                            ``positive values`` : uses variable lambda prescription detailed
                            in appendix of `Claeys+2014 <https://ui.adsabs.harvard.edu/abs/2014A%26A...563A..83C/abstract>`_
                            where lambdaf is the fraction of the ionization energy that can go into ejecting
                            the envelope; to use this prescription without extra ionization energy, set lambdaf=0

                            ``negative values`` : fixes :math:`{\lambda}` to a value of -1.0* *lambdaf*

                         **lambdaf = 0.0**

``ceflag``               Selects the `de Kool 1990 <https://ui.adsabs.harvard.edu/abs/1990ApJ...358..189D/abstract>`_
                         model to set the initial orbital energy using the
                         total mass of the stars instead of the core masses as
                         in `Equation 70 of Hurley+2002 <https://ui.adsabs.harvard.edu/abs/2002MNRAS.329..897H/abstract>`_.

                            ``0`` : Uses the core mass to calculate initial
                            orbital energy as
                            in `Equation 70 of Hurley+2002 <https://ui.adsabs.harvard.edu/abs/2002MNRAS.329..897H/abstract>`_

                            ``1`` : Uses the `de Kool 1990 <https://ui.adsabs.harvard.edu/abs/1990ApJ...358..189D/abstract>`_
                            model

                         **ceflag = 0**

``cekickflag``           Selects which mass and separation values to use when
                         a supernova occurs during the CE and a kick
                         needs to be applied.

                            ``0`` : uses pre-CE mass and post-CE sep (BSE default)

                            ``1`` : uses pre-CE mass and sep values

                            ``2`` : uses post-CE mass and sep

                         **cekickflag = 2**

``cemergeflag``          Determines whether stars that begin a CE
                         without a core-envelope boundary automatically lead to
                         merger in CE. These systems include:
                         kstars = [0,1,2,7,8,10,11,12].

                            ``0`` : allows the CE to proceed

                            ``1`` : causes these systems to merge in the CE

                         **cemergeflag = 0**

``cehestarflag``         Uses fitting formulae from `Tauris+2015 <https://ui.adsabs.harvard.edu/abs/2015MNRAS.451.2123T/abstract>`_
                         for evolving RLO systems with a helium star donor
                         and compact object accretor.
                         NOTE: this flag will override choice made by
                         cekickflag if set

                            ``0`` : does NOT use Tauris+2015 at all

                            ``1`` : uses Tauris+2015 fits for final period only

                            ``2`` : uses Tauris+2015 fits for both final mass and final period

                         **cehestarflag = 0**

``qcflag``               Selects model to determine critical mass ratios for the
                         onset of unstable mass transfer and/or a common envelope
                         during RLO.
                         NOTE: this is overridden by qcrit_array if any of the
                         values are non-zero.

                            ``0`` : follows `Section 2.6 of Hurley+2002 <https://ui.adsabs.harvard.edu/abs/2002MNRAS.329..897H/abstract>`_
                            (Default BSE)

                            ``1`` : same as 0 but with `Hjellming & Webbink 1987 <https://ui.adsabs.harvard.edu/abs/1987ApJ...318..794H/abstract>`_
                            for GB/AGB stars

                            ``2`` : follows `Table 2 of Claeys+2014 <https://ui.adsabs.harvard.edu/abs/2014A%26A...563A..83C/abstract>`_

                            ``3`` : same as 2 but with `Hjellming & Webbink 1987 <https://ui.adsabs.harvard.edu/abs/1987ApJ...318..794H/abstract>`_
                            for GB/AGB stars

                            ``4`` : follows `Section 5.1 of Belcyznski+2008 <https://ui.adsabs.harvard.edu/abs/2008ApJS..174..223B/abstract>`_ except for WD donors which follow BSE

                            ``5`` : follows `Section 2.3 of Neijssel+2020 <https://ui.adsabs.harvard.edu/abs/2019MNRAS.490.3740N/abstract>`_ Mass transfer from stripped stars is always assumed to be dynamically stable

                         **qcflag = 1**

                         .. csv-table:: Comparison of Q Crit Values (Donor Mass/Accretor Mass) For Each Donor Kstar Type Across Flag Options
                            :file: qcrit_table.csv
                            :header-rows: 1


                         Eq.1: ``qc = 0.362 + 1.0/(3.0*(1.0 - massc(j1)/mass(j1)))``, which is from Hjellming & Webbink 1983

                         Eq.2: ``qc = (1.67d0-zpars(7)+2.d0*(massc(j1)/mass(j1))**5)/2.13d0``, which is from Claeys+ 2014

``qcrit_array``          Array with length: 16 for user-input values for the
                         critical mass ratios that govern the onset of unstable
                         mass transfer and a common envelope. Each item is set
                         individually for its associated kstar, and a value of
                         0.0 will apply prescription of the qcflag for that kstar.

                         **Note:** there are cases where a common envelope is forced
                         regardless of the critical mass ratio for unstable mass
                         transfer; in the following cases, a common envelope occurs
                         regardless of the qcrit or qcflag

                         **qcrit_array = [0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0]**

=======================  =====================================================

.. code-block:: ini

    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ;;; COMMON ENVELOPE FLAGS ;;;
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    ; alpha1 is the common-envelope efficiency parameter
    ; default=1.0
    alpha1 = 1.0

    ; lambdaf is the binding energy factor for common envelope evolution
    ; lambdaf>0.0 uses variable lambda prescription in appendix of Claeys+2014
    ; lambdaf<0 uses fixes lambda to a value of -1.0*lambdaf
    ; default=0.5
    lambdaf = 0.5

    ; ceflag=1 used the method from de Kool 1990 for setting the initial orbital energy
    ; ceflag=0 does not use this method (uses the core mass to calculate initial orbital energy)
    ; default=0
    ceflag=0

    ; cekickflag determined the prescription for calling kick.f in comenv.f
    ; 0: default BSE
    ; 1: uses pre-CE mass and sep values
    ; 2: uses post-CE mass and sep
    ; default=0
    cekickflag=0

    ; cemergeflag determines whether stars without a core-envelope boundary automatically lead to merger in CE
    ; cemergeflag=1 turns this on (causes these systems to merge)
    ; default=0
    cemergeflag=0

    ; cehestarflag uses fitting formulae from TLP, 2015, MNRAS, 451 for evolving RLO systems with a helium star donor and compact object accretor
    ; this flag will override choice made by cekickflag if set
    ; 0: off
    ; 1: fits for final period only
    ; 2: fits for both final mass and final period
    ; default=0
    cehestarflag=0

    ; qcflag is an integer flag that sets the model to determine which critical mass ratios to use for the onset of unstable mass transfer and/or a common envelope. NOTE: this is overridden by qcrit_array if any of the values are non-zero.
    ; 0: standard BSE
    ; 1: BSE but with Hjellming & Webbink, 1987, ApJ, 318, 794 GB/AGB stars
    ; 2: following binary_c from Claeys+2014 Table 2
    ; 3: following binary_c from Claeys+2014 Table 2 but with Hjellming & Webbink, 1987, ApJ, 318, 794 GB/AGB stars
    ; 4: following StarTrack from Belczynski+2008 Section 5.1. WD donors follow standard BSE
    ; 5: following COMPAS from Neijssel+2020 Section 2.3. Stripped stars are always dynamically stable
    ; default=3
    qcflag=3

    ; qcrit_array is a 16-length array for user-input values for the critical mass ratios that govern the onset of unstable mass transfer and a common envelope
    ; each item is set individually for its associated kstar, and a value of 0.0 will apply prescription of the qcflag for that kstar
    ; default: [0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0]
    qcrit_array=[0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0]

.. note::

    KICK FLAGS

=======================  =====================================================
``kickflag``             Sets the particular natal kick prescription to use
                         Note that ``sigmadiv``, ``bhflag``, ``bhsigmafrac``,
                         ``aic``, and ``ussn``, which are described below, are
                         only used when ``kickflag=0``

                            ``0`` : The standard COSMIC kick prescription, where
                            kicks are drawn from a bimodal distribution with
                            standard FeCCSN getting a kick drawn from a Maxwellian
                            distribution with dispersion parameter ``sigma`` and ECSN
                            are drawn according to ``sigmadiv``. This setting has
                            additional possible options for ``bhflag``, ``bhsigmafrac``,
                            ``aic`` and ``ussn``.

                            ``-1`` : Natal kicks are drawn according to ``sigma`` and
                            scaled by the ejecta mass and remnant mass following Eq. 1 of
                            `Giacobbo & Mapelli 2020 <https://ui.adsabs.harvard.edu/abs/2020ApJ...891..141G/abstract>`_

                            ``-2`` : Natal kicks are drawn according to ``sigma`` and
                            scaled by just the ejecta mass following Eq. 2 of
                            `Giacobbo & Mapelli 2020 <https://ui.adsabs.harvard.edu/abs/2020ApJ...891..141G/abstract>`_

                            ``-3`` : Natal kicks are drawn according to Eq. 1 of
                            `Bray & Eldridge 2016 <https://ui.adsabs.harvard.edu/abs/2016MNRAS.461.3747B/abstract>`_

                         **default=0**

``sigma``                Sets the dispersion in the Maxwellian for the
                         SN kick velocity in km/s

                            ``positive value`` : sets Maxwellian dispersion

                         **default=265.0**

``bhflag``               Sets the model for how SN kicks are applied to BHs
                         where bhflag != 0 allows velocity kick at BH formation

                            ``0`` : no BH kicks

                            ``1`` : fallback-modulated kicks following
                            `Fryer+2012 <https://ui.adsabs.harvard.edu/abs/2012ApJ...749...91F/abstract>`_

                            ``2`` : kicks decreased by ratio of BH mass to NS mass
                            (1.44 Msun); conserves linear momentum

                            ``3`` : full strength kick drawn from Maxwellian
                            with dispersion = *sigma* selected above

                         **bhflag = 1**

``ecsn``                 Allows for electron capture SN and sets the
                         maximum ECSN mass range at the time of SN

                            ``0`` : turns off ECSN

                            ``positive values`` : `BSE (Hurley+2002) <https://ui.adsabs.harvard.edu/abs/2002MNRAS.329..897H/abstract>`_
                            and `StarTrack (Belczynski+2008) <https://ui.adsabs.harvard.edu/abs/2008ApJS..174..223B/abstract>`_
                            use ecsn = 2.25, while `Podsiadlowksi+2004 <https://ui.adsabs.harvard.edu/abs/2004ApJ...612.1044P/abstract>`_
                            use ecsn = 2.5

                         **ecsn = 2.5**

``ecsn_mlow``            Sets the low end of the ECSN mass range

                            ``positive values`` : `BSE (Hurley+2002) <https://ui.adsabs.harvard.edu/abs/2002MNRAS.329..897H/abstract>`_
                            use ecsn_mlow = 1.6, while `StarTrack (Belczynski+2008) <https://ui.adsabs.harvard.edu/abs/2008ApJS..174..223B/abstract>`_
                            use ecsn_mlow = 1.85, while `Podsiadlowksi+2004 <https://ui.adsabs.harvard.edu/abs/2004ApJ...612.1044P/abstract>`_
                            use ecsn_mlow = 1.4

                         **ecsn_mlow = 1.4**

``sigmadiv``             Sets the modified ECSN kick strength

                         ``positive values`` : divide *sigma* above by *sigmadiv*

                         ``negative values`` : sets the ECSN *sigma* value

                         **sigmadiv = -20.0**

``aic``                  reduces kick strengths for accretion induced collapse SN
                         according to *sigmadiv*

                            ``0`` : AIC SN receive kicks drawn from Maxwellian
                            with dispersion = *sigma* above

                            ``1`` : sets kick strength according to *sigmadiv*
                            NOTE: this will applies even if ecsn = 0.0

                         **aic = 1**

``ussn``                 Reduces kicks according to the *sigmadiv* selection
                         for ultra-stripped supernovae which happen whenever
                         a He-star undergoes a CE with a compact companion

                            ``0`` : USSN receive kicks drawn from Maxwellian
                            with dispersion = *sigma* above

                            ``1`` : sets kick strength according to *sigmadiv*

                         **ussn = 0**

``pisn``                 Allows for (pulsational) pair instability supernovae
                         and sets either the model to use or the maximum mass
                         of the remnant.

                            ``0`` : no pulsational pair instability SN

                            ``-1`` : uses the formulae from `Spera & Mapelli 2017 <https://ui.adsabs.harvard.edu/abs/2017MNRAS.470.4739S/abstract>`_

                            ``-2`` : uses a polynomial fit to `Table 1 in Marchant+2018 <https://ui.adsabs.harvard.edu/abs/2018arXiv181013412M/abstract>`_

                            ``-3`` : uses a polynomial fit to `Table 5 in Woosley 2019 <https://ui.adsabs.harvard.edu/abs/2019ApJ...878...49W/abstract>`_

                            ``positive values`` : turns on pulsational pair
                            instability SN and sets the maximum mass of the allowed
                            remnant

                         **pisn = 45.0**

``bhsigmafrac``          Sets a fractional modification which scales down *sigma*
                         for BHs. This works in addition to whatever is chosen for
                         *bhflag*, and is applied to *sigma* **before** the *bhflag*
                         prescriptions are applied

                            ``values between [0, 1]`` : reduces *sigma* by *bhsigmafrac*

                         **bhsigmafrac = 1.0**

``polar_kick_angle``     Sets the opening angle of the SN kick relative to the
                         pole of the exploding star, where 0 gives strictly polar
                         kicks and 90 gives fully isotropic kicks

                            ``values between [0, 90]`` : sets opening angle for SN kick

                         **polar_kick_angle = 90.0**

``natal_kick_array``     Array of dimensions: (2,5) which takes user input values
                         for the SN natal kick, where the first row corresponds to the
                         first star and the second row corresponds to the second star and
                         columns are: [vk, phi, theta, mean_anomaly, rand_seed].
                         NOTE: any numbers outside these ranges will be sampled
                         in the standard ways detailed above.

                            ``vk`` : valid on the range [0, inf]

                            ``phi`` : co-lateral polar angle in degrees, valid from
                            [-90, 90]

                            ``theta`` : azimuthal angle in degrees, valid from
                            [0, 360]

                            ``mean_anomaly`` : mean anomaly in degrees,
                            valid from [0, 360]

                            ``rand_seed`` : supplied if restarting evolution after
                            a supernova has already occurred

                         **natal_kick_array = [[-100.0,-100.0,-100.0,-100.0,0.0][-100.0,-100.0,-100.0,-100.0,0.0]]**
=======================  =====================================================

.. code-block:: ini

    ;;;;;;;;;;;;;;;;;;
    ;;; KICK FLAGS ;;;
    ;;;;;;;;;;;;;;;;;;

    ; kickflag sets the particular kick prescription to use
    ; kickflag=0 uses the standard kick prescription, where kicks are drawn from a bimodal
    ; distribution based on whether they go through FeCCSN or ECSN/USSN
    ; kickflag=-1 uses the prescription from Giacobbo & Mapelli 2020 (Eq. 1)
    ; with their default parameters (<m_ns>=1.2 Msun, <m_ej>=9 Msun)
    ; kickflag=-2 uses the prescription from Giacobbo & Mapelli 2020 (Eq. 2),
    ; which does not scale the kick by <m_ns>
    ; kickflag=-3 uses the prescription from Bray & Eldridge 2016 (Eq. 1)
    ; with their default parameters (alpha=70 km/s, beta=120 km/s)
    ; Note: sigmadiv, bhflag, bhsigmafrac, aic, and ussn are only used when kickflag=0
    ; default = 0
    kickflag = 0

    ; sigma sets is the dispersion in the Maxwellian for the SN kick velocity in km/s
    ; default=265.0
    sigma=265.0

    ; bhflag != 0 allows velocity kick at BH formation
    ; bhflag=0: no BH kicks; bhflag=1: fallback-modulated kicks
    ; bhflag=2: mass-weighted (proportional) kicks; bhflag=3: full NS kicks
    ; default=1
    bhflag=1

    ; ecsn>0 turns on ECSN and also sets the maximum ECSN mass range (at the time of the SN)
    ; stock BSE and StarTrack: ecsn=2.25; Podsiadlowski+2004: ecsn=2.5)
    ; default=2.5
    ecsn=2.5

    ; ecsn_mlow sets the low end of the ECSN mass range
    ; stock BSE:1.6; StarTrack:1.85; Podsiadlowski+2004:1.4)
    ; default=1.4
    ecsn_mlow=1.4

    ; sigmadiv sets the modified ECSN kick
    ; negative values sets the ECSN sigma value, positive values divide sigma above by sigmadiv
    ; default=-20.0
    sigmadiv=-20.0

    ; aic=1 turns on low kicks for accretion induced collapse
    ; works even if ecsn=0
    ; default=1
    aic=1

    ; ussn=1 uses reduced kicks (drawn from the sigmadiv distritbuion) for ultra-stripped supernovae
    ; these happen whenever a He-star undergoes a CE with a compact companion
    ; default=0
    ussn=1

    ; pisn>0 allows for (pulsational) pair instability supernovae
    ; and sets the maximum mass of the remnant
    ; pisn=-1 uses the formulae from Spera+Mapelli 2017 for the mass
    ; pisn=0 turns off (pulsational) pair instability supernovae
    ; default=45
    pisn=45.0

    ; bhsigmafrac sets the fractional modification used for scaling down the sigma for BHs
    ; this works in addition to whatever is chosen for bhflag, and is applied to the sigma beforehand these prescriptions are implemented
    ; default=1.0
    bhsigmafrac = 1.0

    ; polar_kick_angle sets the opening angle of the kick relative to the pole of the exploding star
    ; this can range from 0 (strictly polar kicks) to 90 (fully isotropic kicks)
    ; default=90.0
    polar_kick_angle = 90.0

    ; natal_kick_array is a (2,5) array for user-input values for the SN natal kick
    ; The first and second row specify the natal kick information for the first and second star, and columns are formatted as: (vk, phi, theta, eccentric anomaly, rand_seed)
    ; vk is valid on the range [0, inf], phi are the co-lateral polar angles (in degrees) valid from [-90.0, 90.0], theta are azimuthal angles (in degrees) valid from [0, 360], and eccentric anomaly are the eccentric anomaly of the orbit at the time of SN (in degrees) valid from [0, 360]
    ; any number outside of these ranges will be sampled in the standard way in kick.f
    ; rand_seed is for reproducing a supernova if the the system is started mid-evolution, set to 0 if starting binary from the beginning
    ; default=[[-100.0,-100.0,-100.0,-100.0,0],[-100.0,-100.0,-100.0,-100.0,0.0]]
    natal_kick_array=[[-100.0,-100.0,-100.0,-100.0,0],[-100.0,-100.0,-100.0,-100.0,0.0]]

.. note::

    REMNANT MASS FLAGS

===================  =====================================================
``remnantflag``      Determines the remnant mass prescription used for NSs and BHs.

                            ``0`` : follows `Section 6 of Hurley+2000 <https://ui.adsabs.harvard.edu/abs/2000MNRAS.315..543H/abstract>`_
                            (default BSE)

                            ``1`` : follows `Belczynski+2002 <https://ui.adsabs.harvard.edu/abs/2002ApJ...572..407B/abstract>`_

                            ``2`` : follows `Belczynski+2008 <https://ui.adsabs.harvard.edu/abs/2008ApJS..174..223B/abstract>`_

                            ``3`` : follows the rapid prescription from `Fryer+2012 <https://ui.adsabs.harvard.edu/abs/2012ApJ...749...91F/abstract>`_, with updated proto-core mass from `Giacobbo & Mapelli 2020 <https://ui.adsabs.harvard.edu/abs/2020ApJ...891..141G/abstract>`_

                            ``4`` : delayed prescription from `Fryer+2012 <https://ui.adsabs.harvard.edu/abs/2012ApJ...749...91F/abstract>`_

                     **remnantflag = 3**

``mxns``             Sets the boundary between the maximum NS mass
                     and the minimum BH mass

                            ``positive values`` : sets the NS/BH mass bounary

                     **mxns = 3.0**

``rembar_massloss``  Determines the prescriptions for mass conversion from
                     baryonic to gravitational mass during the collapse of
                     the proto-compact object

                            ``positive values`` : sets the maximum amount of mass loss, which should be about 10% of the maximum mass of an iron core (:math:`{\sim 5 \mathrm{M}_\odot}` Fryer, private communication)

                            ``-1 < *rembar_massloss* < 0`` : assumes that proto-compact objects lose a constant fraction of their baryonic mass when collapsing to a black hole (e.g., *rembar_massloss* = -0.1 gives the black hole a gravitational mass that is 90% of the proto-compact object's baryonic mass)

                     **rembar_massloss = 0.5**
===================  =====================================================

.. code-block:: ini

    ;;;;;;;;;;;;;;;;;;;;;;;;;;
    ;;; REMNANT MASS FLAGS ;;;
    ;;;;;;;;;;;;;;;;;;;;;;;;;;

    ; remnantflag determines the remnant mass prescription used
    ; remnantflag=0: default BSE
    ; remnantflag=1: Belczynski et al. 2002, ApJ, 572, 407
    ; remnantflag=2: Belczynski et al. 2008
    ; remnantflag=3: rapid prescription (Fryer+ 2012), updated as in Giacobbo & Mapelli 2020
    ; remnantflag=4: delayed prescription (Fryer+ 2012)
    ; default=3
    remnantflag=3

    ; mxns sets the maximum NS mass
    ; default=2.5
    mxns=2.5

    ; rembar_massloss determines the mass conversion from baryonic to
    ; gravitational mass
    ; rembar_massloss >= 0: sets the maximum amount of mass loss
    ; -1 < rembar_massloss < 0: uses the prescription from Fryer et al. 2012,
    ; assuming for BHs Mrem = (1+rembar_massloss)*Mrem,bar for negative rembar_massloss
    ; default=0.5
    rembar_massloss=0.5

.. note::

    REMNANT SPIN FLAGS

=======================  ===============================================================
``bhspinflag``           Uses different prescriptions for BH spin after formation

                            ``0`` : sets all BH spins to *bhspinmag*

                            ``1`` : draws a random BH spin between 0 and bhspinmag for every BH

                            ``2`` : core-mass dependent BH spin (based on `Belczynski+2017 v1 <https://arxiv.org/abs/1706.07053v1>`_)

                         **bhspinflag = 0**

``bhspinmag``            Sets either the spin of all BHs or the upper limit of the uniform distribution for BH spins

                            ``values >= 0.0`` : spin or upper limit value

                         **bhspinmag = 0.0**
=======================  ===============================================================

.. code-block:: ini

    ;;;;;;;;;;;;;;;;;;;;;;;;;;
    ;;; REMNANT SPIN FLAGS ;;;
    ;;;;;;;;;;;;;;;;;;;;;;;;;;

    ; bhspinflag uses different prescriptions for BH spin after formation
    ; bhspinflag=0; sets all BH spins to bhspinmag
    ; bhspinflag=1; draws a random BH spin between 0 and bhspinmag for every BH
    ; bhspinflag=2; core-mass dependent BH spin (based on Belczynski+2017; 1706.07053, v1)
    ; default=0
    bhspinflag = 0

    ; bhspinmag sets either the spin of all BHs or the upper limit of the uniform
    ; distribution for BH spins
    ; default=0.0
    bhspinmag=0.0

.. note::

    GR ORBITAL DECAY FLAG

=======================  ===============================================================
``grflag``               Turns on or off orbital decay due to gravitational wave radiation

                            ``0`` : No orbital decay due to GR

                            ``1`` : Orbital decay due to GR is included

                         **grflag = 1**
=======================  ===============================================================

.. code-block:: ini

    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ;;; GR ORBITAL DECAY FLAG ;;;
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ; grflag turns on or off orbital decay due to gravitational wave radiation
    ; grflag=0; no orbital decay due to GR
    ; grflag=1; orbital decay due to GR is included
    grflag = 1

.. note::

    MASS TRANSFER FLAGS

=======================  =====================================================
``eddfac``               Eddington limit factor for mass transfer.

                            ``1`` : mass transfer rate is limited by the
                            Eddington rate following Equation 67 in
                            `Hurley+2002 <https://ui.adsabs.harvard.edu/abs/2002MNRAS.329..897H/abstract>`_

                            ``values >1`` : permit super-Eddington accretion
                            up to value of *eddfac*

                         **eddfac = 1.0**

``gamma``                Angular momentum prescriptions for mass lost during RLO
                         at super-Eddington mass transfer rates

                            ``-1`` : assumes the lost material carries away the
                            specific angular momentum of the primary

                            ``-2`` : assumes material is lost from the system as
                            if it is a wind from the secondary

                            ``>0`` : assumes that the lost material takes away a
                            fraction *gamma* of the orbital angular momentum

                         **gamma = -2.0**

``don_lim``              Calculates the rate of thermal mass loss through Roche
                         overflow mass transfer from the donor star

                            ``-1`` : donor mass loss rate is calculated following
                            `Hurley+2002 <https://ui.adsabs.harvard.edu/abs/2002MNRAS.329..897H/abstract>`_

                            ``-2`` : donor mass loss rate is calculated following
                             `Claeys+2014 <https://ui.adsabs.harvard.edu/abs/2014A%26A...563A..83C/abstract>`_

``acc_lim``              Limits the amount of mass accreted during Roche overflow

                            ``-1`` : limited to 10x's the thermal rate of the accretor
                            for MS/HG/CHeB and unlimited for GB/EAGB/AGB stars

                            ``-2`` : limited to 1x's the thermal rate of the accretor
                            for MS/HG/CHeB and unlimited for GB/EAGB/AGB stars

                            ``-3`` : limited to 10x's the thermal rate of the accretor
                            for all stars

                            ``-4`` : limited to 1x's the thermal rate of the accretor
                            for all stars

                            ``>=0`` : sets overall accretion fraction of donor mass
                            as in Belcyznski+2008 w/ acc_lim = 0.5

=======================  =====================================================

.. code-block:: ini

    ;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ;;; MASS TRANSFER FLAGS ;;;
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;

    ; eddfac is Eddington limit factor for mass transfer
    ; default=1.0
    eddfac=1.0

    ; gamma is the angular momentum factor for mass lost during RLO
    ; gamma=-2: assumes material is lost from the system as if it is a wind from the secondary (for super-Eddington mass transfer rates)
    ; gamma=-1: assumes the lost material carries with is the specific angular momentum of the primary
    ; gamma>0: assumes that the lost material take away a fraction (gamma) of the orbital angular momentum
    ; default=-1
    gamma=-1.0

    ; don_lim is a flag which determines how much mass is lost during thermal timescale MT
    ; don_lim = 0: assumes standard BSE choice as outlined in Hurley+2002
    ; don_lim = -1: Follows Claeys+2014
    don_lim = 0

    ; acc_lim is a flag which determines how much mass is accreted from the donor
    ; if acc_lim > 0: this provides the fraction of mass accreted
    ; acc_lim = 0: assumes standard BSE choice as outlined in Hurley+2002 which limits to 10*tkh_acc for MS/CHeB
    ; acc_lim = -1: assumes the accretion is limited to tkh_acc for MS/CHeB
    ; acc_lim = -2: assumes the accretion is limited by 10*tkh_acc for all fusing stars
    ; acc_lim = -3: assumes the accretion is limited by tkh_for all fusing stars
    acc_lim = 0

.. note::

    TIDES FLAGS

=======================  =====================================================
``tflag``                Activates tidal circularisation following
                         `Hurley+2002 <https://ui.adsabs.harvard.edu/abs/2002MNRAS.329..897H/abstract>`_

                            ``0`` : no tidal circularization

                            ``1`` : activates tidal circularization

                         **tflag = 1**

``ST_tide``              Activates StarTrack setup for tides following
                         `Belczynski+2008 <https://ui.adsabs.harvard.edu/abs/2008ApJS..174..223B/abstract>`_

                            ``0`` : follows `BSE <https://ui.adsabs.harvard.edu/abs/2002MNRAS.329..897H/abstract>`_

                            ``1`` : follows `StarTrack <https://ui.adsabs.harvard.edu/abs/2008ApJS..174..223B/abstract>`_

                         **ST_tide = 1**

``fprimc_array``         controls the scaling factor for convective tides
                         each item is set individually for its associated kstar
                         The releveant equation is `Equation 21 of Hurley+2002 <https://watermark.silverchair.com/329-4-897.pdf?token=AQECAHi208BE49Ooan9kkhW_Ercy7Dm3ZL_9Cf3qfKAc485ysgAAAnAwggJsBgkqhkiG9w0BBwagggJdMIICWQIBADCCAlIGCSqGSIb3DQEHATAeBglghkgBZQMEAS4wEQQMYUoYtydpxVKmZePqAgEQgIICI1b5IZldHg9_rX6JacIe-IR042LnNi-4F9DMp-2lm3djjQ8xehKOv5I0VBjSNJfa6n-FErAH7ed1llADY7tMDTvqo1GHKBMDslNku5XDGfmae0sF-Zp5ndeGoZsyqISABLHEbdY4VFl8Uz_6jzAuBjGztnuxVmUh9bKIOaxuDpfB3Mn2xOfP9lcCVkjzQ0JWzr98nQNmVwDkI9bPv98Ab46BjBdGdcBKajCC-sqASjtmAQS2h6SGTTBqyRAyigqXcPtWf3Ye1SbxtL3zag6_Lf01rgCoUCK9eT_pavb5F8vVkUTMWbZQ79DWxn5pfZYi72C7_BtlPoUnS8Gs3wvw18BTIaHTKblwh225DcXuTEh_ngMmRvPEVctvG8tjlr9md-eFK0cEsq0734eGYtnwxeqvFxcWsW6mRbXrFHFsInQK16j6n36XuCimY665l_-HPAuu-lTTlwpMTUR7K1eYMBsco_tp_TdxEipRNvBpaWZX3J0FxPMzi84Y01UvWiW69pxb-LLTpf8aG4YCm9asRFyfDZ9nbSdgrIlCiuzy7QSmkvsHOaTEecmwRimFRycDuIuWLvA_tILmYCIM2KzvqYJSVCQPJH39xEHZG8LbMqImwAVYO3H90qh-90gNrtZn4ofSskcgqxeqfZly9CPfmEevX5s-SlLHMh1N6gdZwenvMC0kTWg_rskbvGiANtuGngD-kKDbunGpYJU_nI7uDnhGtdY#page=5>`_

                            ``positive values`` : sets scaling factor of
                            Equation 21 referenced above

                         **fprimc_array = [2.0/21.0,2.0/21.0,2.0/21.0,2.0/21.0,2.0/21.0,2.0/21.0,
                         2.0/21.0,2.0/21.0,2.0/21.0,2.0/21.0,2.0/21.0,2.0/21.0,2.0/21.0,2.0/21.0,
                         2.0/21.0,2.0/21.0]**
=======================  =====================================================

.. code-block:: ini

    ;;;;;;;;;;;;;;;;;;;
    ;;; TIDES FLAGS ;;;
    ;;;;;;;;;;;;;;;;;;;

    ; tflag=1 activates tidal circularisation
    ; default=1
    tflag=1

    ; ST_tide sets which tidal method to use. 0=Hurley+2002, 1=StarTrack: Belczynski+2008
    ; Note, here startrack method does not use a better integration scheme (yet) but simply
    ; follows similar set up to startrack (including initial vrot, using roche-lobe check
    ; at periastron, and circularisation and synchronisation at start of MT).
    ; default=1
    ST_tide=1

    ; fprimc_array controls the scaling factor for convective tides
    ; each item is set individually for its associated kstar
    ; The releveant equation is Equation 21 from the BSE paper
    ; The default is to send the same coefficient (2/21) as is in the equation
    ; for every kstar
    fprimc_array=[2.0/21.0,2.0/21.0,2.0/21.0,2.0/21.0,2.0/21.0,2.0/21.0,2.0/21.0,2.0/21.0,2.0/21.0,2.0/21.0,2.0/21.0,2.0/21.0,2.0/21.0,2.0/21.0,2.0/21.0,2.0/21.0]

.. note::

    WHITE DWARF FLAGS

=======================  =====================================================
``ifflag``               Activates the initial-final white dwarf mass relation
                         from Han+1995 `Equations 3, 4, and 5 <http://adsabs.harvard.edu/cgi-bin/nph-data_query?bibcode=1995MNRAS.272..800H&link_type=ARTICLE&db_key=AST&high=#page=4>`_.

                            ``0`` : no modifications to BSE

                            ``1`` : activates initial-final WD mass relation

                         **ifflag = 0**

``wdflag``               Activates an alternate cooling law found in the description
                         immediately following `Equation 1 <http://iopscience.iop.org/article/10.1086/374637/pdf#page=3>`_
                         in Hurley & Shara 2003.
                         Equation 1 gives the BSE default Mestel cooling law.

                            ``0`` : no modifications to BSE

                            ``1`` : activates modified cooling law

                         **wdflag = 1**

``epsnov``               Fraction of accreted matter retained in a nova eruption.
                         This is relevant for accretion onto degenerate objects;
                         see Section 2.6.6.2 in `Hurley+2002 <https://ui.adsabs.harvard.edu/abs/2002MNRAS.329..897H/abstract>`_.

                            ``positive values between [0, 1]`` : retains *epsnov*
                            fraction of accreted matter

                         **epsnov = 0.001**
=======================  =====================================================

.. code-block:: ini

    ;;;;;;;;;;;;;;;;;;;;;;;;;
    ;;; WHITE DWARF FLAGS ;;;
    ;;;;;;;;;;;;;;;;;;;;;;;;;

    ; ifflag > 0 uses WD IFMR of HPE, 1995, MNRAS, 272, 800
    ; default=0
    ifflag=0

    ; wdflag > 0 uses modified-Mestel cooling for WDs
    ; default=1
    wdflag=1

    ; epsnov is the fraction of accreted matter retained in nova eruptions
    ; default=0.001
    epsnov=0.001

.. note::

    PULSAR FLAGS

=======================  =====================================================
``bdecayfac``            Activates different models for accretion induced field decay; see
                         `Kiel+2008 <https://academic.oup.com/mnras/article/388/1/393/1013977>`_.

                            ``0`` : uses an exponential decay

                            ``1`` : uses an inverse decay

                         **bdecayfac = 1**

``bconst``               Sets the magnetic field decay time-scale for pulsars following
                         Section 3 of `Kiel+2008 <https://academic.oup.com/mnras/article/388/1/393/1013977>`_.

                            ``negative values`` : sets k in Myr from Equation 8 to
                            -1 * *bconst*

                         **bconst = -3000**

``ck``                   Sets the magnetic field decay time-scale for pulsars following
                         Section 3 of `Kiel+2008 <https://academic.oup.com/mnras/article/388/1/393/1013977>`_.

                            ``negative values`` : sets :math:`{\tau}`\ :sub:`b` in Myr
                            from Equation 2 to  -1 * *ck*

                         **ck = -1000**
=======================  =====================================================

.. code-block:: ini

    ;;;;;;;;;;;;;;;;;;;
    ;; PULSAR FLAGS ;;;
    ;;;;;;;;;;;;;;;;;;;

    ; bdecayfac determines which accretion induced field decay method to
    ; use from Kiel+2008: 0=exp, 1=inverse
    ; default=1
    bdecayfac=1

    ; bconst is related to magnetic field evolution of pulsars, see Kiel+2008
    ; default=-3000
    bconst=-3000

    ; ck is related to magnetic field evolution of pulsars, see Kiel+2008
    ; default=-1000
    ck=-1000

.. note::

    MIXING VARIABLES

=======================  =====================================================

``rejuv_fac``            Sets the mixing factor in main sequence star collisions.
                         This is hard coded to 0.1 in the original BSE release
                         and in Equation 80 of `Hurley+2002 <https://ui.adsabs.harvard.edu/abs/2002MNRAS.329..897H/abstract>`_
                         but can lead to extended main sequence lifetimes in some cases.

                             ``positive values`` : sets the mixing factor

                         **rejuv_fac = 1.0**

``rejuvflag``            Sets whether to use the orginal prescription for mixing
                         of main-sequence stars (based on equation 80 of `Hurley+2002 <https://ui.adsabs.harvard.edu/abs/2002MNRAS.329..897H/abstract>`_)
                         or whether to use the ratio of the pre-merger He core
                         mass at the base of the giant branch to the merger product's
                         He core mass at the base of the giant branch


                            ``0`` : no modifications to BSE

                            ``1`` : modified mixing times

                         **rejuvflag = 0**

``bhms_coll_flag``       If set to 1 then if BH+star collision and if Mstar > Mbh, do not destroy the star

                         **default = 0**

=======================  =====================================================

.. code-block:: ini

    ;;;;;;;;;;;;;;;;;;;;;;;
    ;; MIXING VARIABLES ;;;
    ;;;;;;;;;;;;;;;;;;;;;;;

    ; rejuv_fac allows different mixing factors in Equation 80 from the BSE
    ; paper. This was originally hard coded to 0.1, which leads massive
    ; stars to potentially have extended main sequence lifetimes.
    rejuv_fac=1.0

    ; rejuvflag toggles between the original BSE prescription for MS mixing and
    ; lifetimes of stars based on the mass of the MS stars (equation 80) or a
    ; prescription that uses the ratio of helium core mass of the pre-merger stars
    ; at the base of the first ascent of the giant branch to determine relative to the
    ; helium core mass of the merger product at the base of the giant branch
    ; default=0
    rejuvflag=0

    ; bhms_coll_flag 
    ; If set to 1 then if BH+star collision and if Mstar > Mbh, do not destroy the star
    ; default = 0
    bhms_coll_flag=0

.. note::

    MAGNETIC BRAKING FLAGS

=======================  =====================================================
``htpmb``                Activates different models for magnetic braking

                            ``0`` : no modifications to BSE

                            ``1`` : follows `Ivanona and Taam 2003 <https://ui.adsabs.harvard.edu/abs/2003ApJ...599..516I/abstract>`_

                         **htpmb = 1**
=======================  =====================================================

.. code-block:: ini

    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ;; MAGNETIC BRAKING FLAGS ;;;
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    ; htpmb allows for different magnetic braking models.
    ; 0=follows BSE paper Section 2.4
    ; 1=follows Ivanova & Taam 2003 method which kicks in later than the standard
    ; default=1
    htpmb=1


.. note::

    MISC FLAGS

=======================  =====================================================
``ST_cr``                Activates different convective vs radiative boundaries

                            ``0`` : no modifications to BSE

                            ``1`` : follows `StarTrack <https://ui.adsabs.harvard.edu/abs/2008ApJS..174..223B/abstract>`_

                         **ST_cr = 1**
=======================  =====================================================

.. code-block:: ini

    ;;;;;;;;;;;;;;;;;
    ;; MISC FLAGS ;;;
    ;;;;;;;;;;;;;;;;;

    ; ST_cr sets which convective/radiative boundary to use
    ; 0=follows BSE paper
    ; 1=follows StarTrack (Belcyznski+2008)
    ; default=1
    ST_cr=1
