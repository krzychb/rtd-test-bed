Code snippets inside Doxygen comments cause failure of Breathe 4.7.0
====================================================================

- Reported in https://github.com/michaeljones/breathe/issues/344
- Resolved in https://github.com/michaeljones/breathe/pull/345


Issue description
^^^^^^^^^^^^^^^^^

If code snippets are included inside Doxygen's comments, then Breathe fails with the following message::

    Exception occurred:
      File "C:/msys32/mingw32/lib/python2.7/site-packages/breathe/renderer/sphinxrenderer.py", line 206, in get_domain
        if isinstance(node, six.text_type) or node.node_type == "enumvalue":
    AttributeError: 'str' object has no attribute 'node_type'
    The full traceback has been saved in c:/users/user-name/appdata/local/temp/sphinx-err-3z4ilr.log, if you want to report the issue to the developers.
    Please also report this if it was a user error, so that a better error message can be provided next time.
    A bug report can be filed in the tracker at <https://github.com/sphinx-doc/sphinx/issues>. Thanks!
    make: *** [Makefile:20: html] Error 1

This issue does not show up, if previus version of Breathe 4.6.0 together with Sphinx 1.5.6 are used.


Doxygen directive that fails
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. doxygenfunction:: nvs_get_str


Header file that contains code causing failure
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

https://github.com/krzychb/rtd-test-bed/blob/master/headers/nvs.h


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
    Location: c:/msys32/mingw32/lib/python2.7/site-packages
    Requires: alabaster, Jinja2, snowballstemmer, babel, imagesize, setuptools, Pygments, typing, colorama, docutils, requests, six, sphinxcontrib-websupport

Sphinx-rtd-theme::

    $ pip show sphinx-rtd-theme
    Name: sphinx-rtd-theme
    Version: 0.2.4
    Summary: Read the Docs theme for Sphinx
    Home-page: https://github.com/rtfd/sphinx_rtd_theme/
    Author: Dave Snider
    Author-email: dave.snider@gmail.com
    License: MIT
    Location: c:/msys32/mingw32/lib/python2.7/site-packages
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
    Location: c:/msys32/mingw32/lib/python2.7/site-packages
    Requires: six, Sphinx, docutils


This issue does not show up with the following packages
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Sphinx 1.5.6::

    $ pip show sphinx
    Name: Sphinx
    Version: 1.5.6
    Summary: Python documentation generator
    Home-page: http://sphinx-doc.org/
    Author: Georg Brandl
    Author-email: georg@python.org
    License: BSD
    Location: c:/msys32/mingw32/lib/python2.7/site-packages
    Requires: alabaster, Jinja2, snowballstemmer, babel, imagesize, Pygments, colorama, docutils, requests, six


Sphinx-rtd-theme - seems to does not matter::

    $ pip show sphinx-rtd-theme
    Name: sphinx-rtd-theme
    Version: 0.2.4
    Summary: Read the Docs theme for Sphinx
    Home-page: https://github.com/rtfd/sphinx_rtd_theme/
    Author: Dave Snider
    Author-email: dave.snider@gmail.com
    License: MIT
    Location: c:/msys32/mingw32/lib/python2.7/site-packages
    Requires:

Breathe 4.6.0::

    $ pip show breathe
    Name: breathe
    Version: 4.6.0
    Summary: Sphinx Doxygen renderer
    Home-page: https://github.com/michaeljones/breathe
    Author: Michael Jones
    Author-email: m.pricejones@gmail.com
    License: BSD
    Location: c:/msys32/mingw32/lib/python2.7/site-packages
    Requires: six, Sphinx, docutils


Other possible workaround
^^^^^^^^^^^^^^^^^^^^^^^^^

Remove code snippets from inside Doxygen's comments.
