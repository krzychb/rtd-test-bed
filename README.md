# rtd-test-bed

[![Documentation Status](https://readthedocs.org/projects/rtd-test-bed/badge/?version=latest)](http://rtd-test-bed.readthedocs.io/en/latest/?badge=latest)

This site has been established to isolate and test various issues with documentation build using the following components:

1. Doxygen - http://www.stack.nl/~dimitri/doxygen/
2. Sphinx - https://github.com/sphinx-doc/sphinx/#readme-for-sphinx
3. Docment theme "sphinx_rtd_theme" - https://github.com/rtfd/sphinx_rtd_theme
4. Breathe - https://github.com/michaeljones/breathe#breathe


## Purpose

Doxygen, Sphinx, Breathe and Read the Docs are all great tools. When put together, for some versions, sometimes, for some code they produce some errors or warnings. As there are four tools, in some cases it is difficult to find out where the problems is.

The purpose of this repository is to provide minimalistic code samples to test and present particular configuration that is causing issues. 


## How to test it?

You can fork this repository on GitHub, set up an account on Read the Docs and publish forked documentation like http://rtd-test-bed.readthedocs.io.

A quicker way to check how documentation renders is to setup environment to build documentation locally on your PC by installing all the packages discussed above. 

You can do it on Linux, Windows running [MSYS2](http://www.msys2.org/) and MacOS following steps below:


1.  Install Doxygen (this is the only OS dependent step):

    **Linux**

    ```bash
    sudo apt-get install doxygen
    ```

    **Windows** - install in [MSYS2](http://www.msys2.org/) console

    ```bash
    pacman -S doxygen
    ```

    **MacOS**

    ```bash
    brew install doxygen
    ```

2.  Clone your forked repository:

    ```bash
    cd ~/some-path
    git clone https://github.com/your-user-name/rtd-test-bed
    ```

3.  All remaining applications (Sphinx, sphinx_rtd_theme and Breathe) are [Python](https://www.python.org/) packages and you can install them in one step as follows:

    ```bash
    cd ~/some-path/rtd-test-bed/docs
    pip install -r requirements.txt
    ```
    You can use specific releases of packages anytime. To do so, change the release numbers inside file 'requirements.txt' and redo step above.

4.  Now you should be ready to build documentation by invoking:

    ```
    cd en
    make html
    ```

After completion, documentation will be placed in `~/some-path/rtd-test-bed/docs/_buld/html` folder. To see it, open `index.html` in a web browser.  


## Contribute

Feel free to contribute to the project in any way you like!


## License

[Apache License Version 2.0, January 2004](LICENSE)
