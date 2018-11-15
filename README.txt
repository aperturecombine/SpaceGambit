**PREREQUISITES**

- CMAKE (www.cmake.org)
- SFML 2.4.2 (www.sfml-dev.org)



**COMPILE**

Make a subdirectory 'Debug'. In 'Debug' type 'cmake ..' to generate a makefile.  If SFML is not installed in standard location, you will need to set the LIB and INCLUDE environment variables. For example if SFML is installed in ~/SFML, then you can adjust the environment variables (assuming linux and a BASH-shell) by:

export LIB=$LIB:~/SFML/lib
export INCLUDE=$INCLUDE:~/SFML/include

These environment variables are only valid in your current terminal. To make them permanent, add the above two lines to your '~/.profile' file.

If SFML is installed, and the environment variables are correctly set, then running 'cmake ..' from 'Debug' will produce something like:

-- The C compiler identification is GNU 4.8.5
-- The CXX compiler identification is GNU 4.8.5
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found SFML .. in /home/f85/username/SFML/include
-- Out-source building. Build type set to: DEBUG
-- Adding executable: helloworld
-- Configuring done
-- Generating done
-- Build files have been written to: /home/f85/username/pong/Debug

Now that the Makefile has been succesfully generated, you can compile with 'make'. This will produce a 'helloworld' executable that will open a blue window.


**ADDING FILES**

- If you want to add an executable, just add the corresponding .cpp file in the 'bin' subdirectory, and _rerun_ 'cmake .' to update the Makefiles.
- If you want to add a source file, just add the corresponding .cpp file in the 'src' subdirectory, and _rerun_ 'cmake .' to update the Makefile.
- If you want to add a header file, just add the corresponding .h file to the 'include' subdirectory. You do not need to update the Makefile.


**ADVANCED COMPILING**

The above instructions will compile your executable with all debug information embedded and compiler optimizations minimized.  To compile a 'release' version, just create a subdirectory 'Release' instead of 'Debug' and follow the same instructions as above. Note: in release mode certain safety checks are disabled and 'assert' statement are ignored. Hence, it is recommended to test your code in 'Debug' mode, and only when everything works, compile it in the 'Release' mode.\

If you want to use additional external libraries, you will need to add them to 'CMakeLists.txt' (line 39). Please refer to the CMake documentation for more information on how to include libraries to your project with CMake.
