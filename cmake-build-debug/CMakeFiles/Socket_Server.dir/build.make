# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/x64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/riccardo/Documents/GitHub/Socket_Server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/riccardo/Documents/GitHub/Socket_Server/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Socket_Server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Socket_Server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Socket_Server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Socket_Server.dir/flags.make

CMakeFiles/Socket_Server.dir/main.cpp.o: CMakeFiles/Socket_Server.dir/flags.make
CMakeFiles/Socket_Server.dir/main.cpp.o: /Users/riccardo/Documents/GitHub/Socket_Server/main.cpp
CMakeFiles/Socket_Server.dir/main.cpp.o: CMakeFiles/Socket_Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/riccardo/Documents/GitHub/Socket_Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Socket_Server.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Socket_Server.dir/main.cpp.o -MF CMakeFiles/Socket_Server.dir/main.cpp.o.d -o CMakeFiles/Socket_Server.dir/main.cpp.o -c /Users/riccardo/Documents/GitHub/Socket_Server/main.cpp

CMakeFiles/Socket_Server.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Socket_Server.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/riccardo/Documents/GitHub/Socket_Server/main.cpp > CMakeFiles/Socket_Server.dir/main.cpp.i

CMakeFiles/Socket_Server.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Socket_Server.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/riccardo/Documents/GitHub/Socket_Server/main.cpp -o CMakeFiles/Socket_Server.dir/main.cpp.s

# Object files for target Socket_Server
Socket_Server_OBJECTS = \
"CMakeFiles/Socket_Server.dir/main.cpp.o"

# External object files for target Socket_Server
Socket_Server_EXTERNAL_OBJECTS =

Socket_Server: CMakeFiles/Socket_Server.dir/main.cpp.o
Socket_Server: CMakeFiles/Socket_Server.dir/build.make
Socket_Server: CMakeFiles/Socket_Server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/riccardo/Documents/GitHub/Socket_Server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Socket_Server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Socket_Server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Socket_Server.dir/build: Socket_Server
.PHONY : CMakeFiles/Socket_Server.dir/build

CMakeFiles/Socket_Server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Socket_Server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Socket_Server.dir/clean

CMakeFiles/Socket_Server.dir/depend:
	cd /Users/riccardo/Documents/GitHub/Socket_Server/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/riccardo/Documents/GitHub/Socket_Server /Users/riccardo/Documents/GitHub/Socket_Server /Users/riccardo/Documents/GitHub/Socket_Server/cmake-build-debug /Users/riccardo/Documents/GitHub/Socket_Server/cmake-build-debug /Users/riccardo/Documents/GitHub/Socket_Server/cmake-build-debug/CMakeFiles/Socket_Server.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Socket_Server.dir/depend

