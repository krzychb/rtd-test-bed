
'WARNING: cpp:typeOrConcept targets a member' for a structure with same variable name used also in function definition
======================================================================================================================

- Reported in: 

    - https://github.com/sphinx-doc/sphinx/issues/4041
    - https://github.com/sphinx-doc/sphinx/pull/3894 (similar warning)



Issue description
^^^^^^^^^^^^^^^^^

When documenting a structure with variable definition, e.g. ``sample_integer``, that is also used as a function parameter declared within the same structure, for example:

.. code-block:: c

    /**
     * Description of sample_structure
     *
     */
    typedef struct {
        int sample_integer;  /*!< Description of sample_integer */
        void (*sample_function)(int sample_integer); /*!< Description of sample_function */
    } sample_structure;

The following warning is shown during documentation build::

    WARNING: cpp:typeOrConcept targets a member (sample_structure::sample_integer).

There are no issues with rendering of this structure:

.. doxygenstruct:: sample_structure
    :members:


Header file that contains code causing this failure
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

https://github.com/krzychb/rtd-test-bed/blob/master/headers/sdmmc_types.h


Details of packages that cause failure
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Sphinx 1.6.3::

    $ pip show sphinx
    Name: Sphinx
    Version: 1.6.3
    Summary: Python documentation generator
    Home-page: http://sphinx-doc.org/
    Author: Georg Brandl
    Author-email: georg@python.org
    License: BSD
    Location: /usr/local/lib/python2.7/dist-packages
    Requires: sphinxcontrib-websupport, six, requests, docutils, typing, Pygments, setuptools, imagesize, babel, snowballstemmer, Jinja2, alabaster

Sphinx-rtd-theme - seems to does not matter::

    $ pip show sphinx-rtd-theme
    Version: 0.1.9
    Summary: ReadTheDocs.org theme for Sphinx, 2013 version.
    Home-page: https://github.com/snide/sphinx_rtd_theme/
    Author: Dave Snider
    Author-email: dave.snider@gmail.com
    License: MIT
    Location: /usr/lib/python2.7/dist-packages
    Requires: 

Breathe 4.7.0::

    $ pip show breathe
    Name: breathe
    Version: 4.7.0
    Summary: Sphinx Doxygen renderer
    Home-page: https://github.com/michaeljones/breathe
    Author: Michael Jones
    Author-email: m.pricejones@gmail.com
    License: BSD
    Location: /usr/local/lib/python2.7/dist-packages
    Requires: docutils, Sphinx, six


Possible workarounds
^^^^^^^^^^^^^^^^^^^^

- Use different names of variable in variable definition and in function delaration.
- Do not use ``:members:`` in ``.. doxygenstruct::`` directive

Use Case
^^^^^^^^

The following code shows an actual structure that exhibits this issue. Issue concerns the integer varaible ``slot``.

.. code-block:: c

    typedef struct {
        uint32_t flags;             /*!< flags defining host properties */
    #define SDMMC_HOST_FLAG_1BIT    BIT(0)      /*!< host supports 1-line SD and MMC protocol */
    #define SDMMC_HOST_FLAG_4BIT    BIT(1)      /*!< host supports 4-line SD and MMC protocol */
    #define SDMMC_HOST_FLAG_8BIT    BIT(2)      /*!< host supports 8-line MMC protocol */
    #define SDMMC_HOST_FLAG_SPI     BIT(3)      /*!< host supports SPI protocol */
        int slot;                   /*!< slot number, to be passed to host functions */
        int max_freq_khz;           /*!< max frequency supported by the host */
    #define SDMMC_FREQ_DEFAULT      20000       /*!< SD/MMC Default speed (limited by clock divider) */
    #define SDMMC_FREQ_HIGHSPEED    40000       /*!< SD High speed (limited by clock divider) */
    #define SDMMC_FREQ_PROBING      400         /*!< SD/MMC probing speed */
        float io_voltage;           /*!< I/O voltage used by the controller (voltage switching is not supported) */
        esp_err_t (*init)(void);    /*!< Host function to initialize the driver */
        esp_err_t (*set_bus_width)(int slot, size_t width);    /*!< host function to set bus width */
        esp_err_t (*set_card_clk)(int slot, uint32_t freq_khz); /*!< host function to set card clock frequency */
        esp_err_t (*do_transaction)(int slot, sdmmc_command_t* cmdinfo);    /*!< host function to do a transaction */
        esp_err_t (*deinit)(void);  /*!< host function to deinitialize the driver */
    } sdmmc_host_t;

The following warnings are shown during documentation build (one per each function that is using ``slot``)::

    WARNING: cpp:typeOrConcept targets a member (sdmmc_host_t::slot).
    WARNING: cpp:typeOrConcept targets a member (sdmmc_host_t::slot).
    WARNING: cpp:typeOrConcept targets a member (sdmmc_host_t::slot).

There are no issues with rendering of this structure:

.. doxygenstruct:: sdmmc_host_t
    :members:

