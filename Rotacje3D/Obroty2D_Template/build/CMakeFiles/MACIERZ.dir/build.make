# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rafal/Pulpit/PO_2021/po_2021/Rotacje3D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rafal/Pulpit/PO_2021/po_2021/Rotacje3D/build

# Include any dependencies generated for this target.
include CMakeFiles/MACIERZ.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MACIERZ.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MACIERZ.dir/flags.make

CMakeFiles/MACIERZ.dir/src/empty.cpp.o: CMakeFiles/MACIERZ.dir/flags.make
CMakeFiles/MACIERZ.dir/src/empty.cpp.o: ../src/empty.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rafal/Pulpit/PO_2021/po_2021/Rotacje3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MACIERZ.dir/src/empty.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MACIERZ.dir/src/empty.cpp.o -c /home/rafal/Pulpit/PO_2021/po_2021/Rotacje3D/src/empty.cpp

CMakeFiles/MACIERZ.dir/src/empty.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MACIERZ.dir/src/empty.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rafal/Pulpit/PO_2021/po_2021/Rotacje3D/src/empty.cpp > CMakeFiles/MACIERZ.dir/src/empty.cpp.i

CMakeFiles/MACIERZ.dir/src/empty.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MACIERZ.dir/src/empty.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rafal/Pulpit/PO_2021/po_2021/Rotacje3D/src/empty.cpp -o CMakeFiles/MACIERZ.dir/src/empty.cpp.s

# Object files for target MACIERZ
MACIERZ_OBJECTS = \
"CMakeFiles/MACIERZ.dir/src/empty.cpp.o"

# External object files for target MACIERZ
MACIERZ_EXTERNAL_OBJECTS =

libMACIERZ.a: CMakeFiles/MACIERZ.dir/src/empty.cpp.o
libMACIERZ.a: CMakeFiles/MACIERZ.dir/build.make
libMACIERZ.a: CMakeFiles/MACIERZ.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rafal/Pulpit/PO_2021/po_2021/Rotacje3D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libMACIERZ.a"
	$(CMAKE_COMMAND) -P CMakeFiles/MACIERZ.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MACIERZ.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MACIERZ.dir/build: libMACIERZ.a

.PHONY : CMakeFiles/MACIERZ.dir/build

CMakeFiles/MACIERZ.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MACIERZ.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MACIERZ.dir/clean

CMakeFiles/MACIERZ.dir/depend:
	cd /home/rafal/Pulpit/PO_2021/po_2021/Rotacje3D/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rafal/Pulpit/PO_2021/po_2021/Rotacje3D /home/rafal/Pulpit/PO_2021/po_2021/Rotacje3D /home/rafal/Pulpit/PO_2021/po_2021/Rotacje3D/build /home/rafal/Pulpit/PO_2021/po_2021/Rotacje3D/build /home/rafal/Pulpit/PO_2021/po_2021/Rotacje3D/build/CMakeFiles/MACIERZ.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MACIERZ.dir/depend
