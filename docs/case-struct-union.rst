Incorrect rendering of a struct with union - 'Expected identifier in nested name'
=================================================================================

- Reported in https://github.com/michaeljones/breathe/issues/346


Issue description
^^^^^^^^^^^^^^^^^

When a header file contains definition of a structure with union as follows:

.. code-block:: c

    typedef struct {
        esp_a2d_mct_t type;                        /*!< A2DP media codec type */
    #define ESP_A2D_CIE_LEN_SBC          (4)
    #define ESP_A2D_CIE_LEN_M12          (4)
    #define ESP_A2D_CIE_LEN_M24          (6)
    #define ESP_A2D_CIE_LEN_ATRAC        (7)
        union {
            uint8_t sbc[ESP_A2D_CIE_LEN_SBC];
            uint8_t m12[ESP_A2D_CIE_LEN_M12];
            uint8_t m24[ESP_A2D_CIE_LEN_M24];
            uint8_t atrac[ESP_A2D_CIE_LEN_ATRAC];
        } cie;                                     /*!< A2DP codec information element */
    } __attribute__((packed)) esp_a2d_mcc_t;

Then rendering of union member of this structure is faulty.

.. doxygenstruct:: esp_a2d_mcc_t
    :members:

The following warning is shown during documentation build::

    (WARNING/2) Invalid definition: Expected identifier in nested name. [error at 21]
    union esp_a2d_mcc_t::@0  esp_a2d_mcc_t::cie
    ---------------------^


Header file that contains code causing this failure
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

https://github.com/krzychb/rtd-test-bed/blob/master/headers/esp_a2dp_api.h


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

This problem exists with previous versions of Sphinx / Breathe, e.g. Sphinx 1.5.6 and Breathe 4.6.0.


Possible, kind of a workaround
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Do not use ``:members:`` in ``.. doxygenstruct::`` directive.
