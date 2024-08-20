This is an attempt to link qpid-proton-cpp to a project, without installing it globally on the machine.

Steps to reproduce (Linux):

1. Initialize the qpid proton submodule, if this has not already been done. `git submodule update --init --recursive`

2. Build and install qpid proton, follow the guide in the project **BUT** when generating cmake files, ensure to set the variable CMAKE_INSTALL_PREFIX to local_install in the root of this folder instead. (e.g. when generating from qpid-proton/build, use `cmake -DCMAKE_INSTALL_PREFIX=../../local_install ..`)

3. Build qpid_test:
    ```
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make all
    ```

4. Attempt to run the program from the build folder `./main`. It crashes since it does not know where the library files `libqpid-proton-proactor.so.1` and `libqpid-proton-core.so.10` are located.