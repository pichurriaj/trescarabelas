# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pichurria/dev-pichurria/cocos2d-pichurriajuegos/projects/trescarabelas

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pichurria/dev-pichurria/cocos2d-pichurriajuegos/projects/trescarabelas

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/pichurria/dev-pichurria/cocos2d-pichurriajuegos/projects/trescarabelas/CMakeFiles /home/pichurria/dev-pichurria/cocos2d-pichurriajuegos/projects/trescarabelas/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/pichurria/dev-pichurria/cocos2d-pichurriajuegos/projects/trescarabelas/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named trescarabelas

# Build rule for target.
trescarabelas: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 trescarabelas
.PHONY : trescarabelas

# fast build rule for target.
trescarabelas/fast:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/build
.PHONY : trescarabelas/fast

#=============================================================================
# Target rules for targets named trescarabelas_CORE_PRE_BUILD

# Build rule for target.
trescarabelas_CORE_PRE_BUILD: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 trescarabelas_CORE_PRE_BUILD
.PHONY : trescarabelas_CORE_PRE_BUILD

# fast build rule for target.
trescarabelas_CORE_PRE_BUILD/fast:
	$(MAKE) -f CMakeFiles/trescarabelas_CORE_PRE_BUILD.dir/build.make CMakeFiles/trescarabelas_CORE_PRE_BUILD.dir/build
.PHONY : trescarabelas_CORE_PRE_BUILD/fast

#=============================================================================
# Target rules for targets named trescarabelas_PRE_BUILD

# Build rule for target.
trescarabelas_PRE_BUILD: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 trescarabelas_PRE_BUILD
.PHONY : trescarabelas_PRE_BUILD

# fast build rule for target.
trescarabelas_PRE_BUILD/fast:
	$(MAKE) -f CMakeFiles/trescarabelas_PRE_BUILD.dir/build.make CMakeFiles/trescarabelas_PRE_BUILD.dir/build
.PHONY : trescarabelas_PRE_BUILD/fast

Classes/AppDelegate.o: Classes/AppDelegate.cpp.o
.PHONY : Classes/AppDelegate.o

# target to build an object file
Classes/AppDelegate.cpp.o:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/AppDelegate.cpp.o
.PHONY : Classes/AppDelegate.cpp.o

Classes/AppDelegate.i: Classes/AppDelegate.cpp.i
.PHONY : Classes/AppDelegate.i

# target to preprocess a source file
Classes/AppDelegate.cpp.i:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/AppDelegate.cpp.i
.PHONY : Classes/AppDelegate.cpp.i

Classes/AppDelegate.s: Classes/AppDelegate.cpp.s
.PHONY : Classes/AppDelegate.s

# target to generate assembly for a file
Classes/AppDelegate.cpp.s:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/AppDelegate.cpp.s
.PHONY : Classes/AppDelegate.cpp.s

Classes/Board.o: Classes/Board.cpp.o
.PHONY : Classes/Board.o

# target to build an object file
Classes/Board.cpp.o:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/Board.cpp.o
.PHONY : Classes/Board.cpp.o

Classes/Board.i: Classes/Board.cpp.i
.PHONY : Classes/Board.i

# target to preprocess a source file
Classes/Board.cpp.i:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/Board.cpp.i
.PHONY : Classes/Board.cpp.i

Classes/Board.s: Classes/Board.cpp.s
.PHONY : Classes/Board.s

# target to generate assembly for a file
Classes/Board.cpp.s:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/Board.cpp.s
.PHONY : Classes/Board.cpp.s

Classes/BoardPopulaterRandom.o: Classes/BoardPopulaterRandom.cpp.o
.PHONY : Classes/BoardPopulaterRandom.o

# target to build an object file
Classes/BoardPopulaterRandom.cpp.o:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/BoardPopulaterRandom.cpp.o
.PHONY : Classes/BoardPopulaterRandom.cpp.o

Classes/BoardPopulaterRandom.i: Classes/BoardPopulaterRandom.cpp.i
.PHONY : Classes/BoardPopulaterRandom.i

# target to preprocess a source file
Classes/BoardPopulaterRandom.cpp.i:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/BoardPopulaterRandom.cpp.i
.PHONY : Classes/BoardPopulaterRandom.cpp.i

Classes/BoardPopulaterRandom.s: Classes/BoardPopulaterRandom.cpp.s
.PHONY : Classes/BoardPopulaterRandom.s

# target to generate assembly for a file
Classes/BoardPopulaterRandom.cpp.s:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/BoardPopulaterRandom.cpp.s
.PHONY : Classes/BoardPopulaterRandom.cpp.s

Classes/GameTestArcadeScene.o: Classes/GameTestArcadeScene.cpp.o
.PHONY : Classes/GameTestArcadeScene.o

# target to build an object file
Classes/GameTestArcadeScene.cpp.o:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/GameTestArcadeScene.cpp.o
.PHONY : Classes/GameTestArcadeScene.cpp.o

Classes/GameTestArcadeScene.i: Classes/GameTestArcadeScene.cpp.i
.PHONY : Classes/GameTestArcadeScene.i

# target to preprocess a source file
Classes/GameTestArcadeScene.cpp.i:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/GameTestArcadeScene.cpp.i
.PHONY : Classes/GameTestArcadeScene.cpp.i

Classes/GameTestArcadeScene.s: Classes/GameTestArcadeScene.cpp.s
.PHONY : Classes/GameTestArcadeScene.s

# target to generate assembly for a file
Classes/GameTestArcadeScene.cpp.s:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/GameTestArcadeScene.cpp.s
.PHONY : Classes/GameTestArcadeScene.cpp.s

Classes/Grid.o: Classes/Grid.cpp.o
.PHONY : Classes/Grid.o

# target to build an object file
Classes/Grid.cpp.o:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/Grid.cpp.o
.PHONY : Classes/Grid.cpp.o

Classes/Grid.i: Classes/Grid.cpp.i
.PHONY : Classes/Grid.i

# target to preprocess a source file
Classes/Grid.cpp.i:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/Grid.cpp.i
.PHONY : Classes/Grid.cpp.i

Classes/Grid.s: Classes/Grid.cpp.s
.PHONY : Classes/Grid.s

# target to generate assembly for a file
Classes/Grid.cpp.s:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/Grid.cpp.s
.PHONY : Classes/Grid.cpp.s

Classes/PointGrid.o: Classes/PointGrid.cpp.o
.PHONY : Classes/PointGrid.o

# target to build an object file
Classes/PointGrid.cpp.o:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/PointGrid.cpp.o
.PHONY : Classes/PointGrid.cpp.o

Classes/PointGrid.i: Classes/PointGrid.cpp.i
.PHONY : Classes/PointGrid.i

# target to preprocess a source file
Classes/PointGrid.cpp.i:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/PointGrid.cpp.i
.PHONY : Classes/PointGrid.cpp.i

Classes/PointGrid.s: Classes/PointGrid.cpp.s
.PHONY : Classes/PointGrid.s

# target to generate assembly for a file
Classes/PointGrid.cpp.s:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/PointGrid.cpp.s
.PHONY : Classes/PointGrid.cpp.s

Classes/Sphere.o: Classes/Sphere.cpp.o
.PHONY : Classes/Sphere.o

# target to build an object file
Classes/Sphere.cpp.o:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/Sphere.cpp.o
.PHONY : Classes/Sphere.cpp.o

Classes/Sphere.i: Classes/Sphere.cpp.i
.PHONY : Classes/Sphere.i

# target to preprocess a source file
Classes/Sphere.cpp.i:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/Sphere.cpp.i
.PHONY : Classes/Sphere.cpp.i

Classes/Sphere.s: Classes/Sphere.cpp.s
.PHONY : Classes/Sphere.s

# target to generate assembly for a file
Classes/Sphere.cpp.s:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/Sphere.cpp.s
.PHONY : Classes/Sphere.cpp.s

proj.linux/main.o: proj.linux/main.cpp.o
.PHONY : proj.linux/main.o

# target to build an object file
proj.linux/main.cpp.o:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/proj.linux/main.cpp.o
.PHONY : proj.linux/main.cpp.o

proj.linux/main.i: proj.linux/main.cpp.i
.PHONY : proj.linux/main.i

# target to preprocess a source file
proj.linux/main.cpp.i:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/proj.linux/main.cpp.i
.PHONY : proj.linux/main.cpp.i

proj.linux/main.s: proj.linux/main.cpp.s
.PHONY : proj.linux/main.s

# target to generate assembly for a file
proj.linux/main.cpp.s:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/proj.linux/main.cpp.s
.PHONY : proj.linux/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... trescarabelas"
	@echo "... trescarabelas_CORE_PRE_BUILD"
	@echo "... trescarabelas_PRE_BUILD"
	@echo "... Classes/AppDelegate.o"
	@echo "... Classes/AppDelegate.i"
	@echo "... Classes/AppDelegate.s"
	@echo "... Classes/Board.o"
	@echo "... Classes/Board.i"
	@echo "... Classes/Board.s"
	@echo "... Classes/BoardPopulaterRandom.o"
	@echo "... Classes/BoardPopulaterRandom.i"
	@echo "... Classes/BoardPopulaterRandom.s"
	@echo "... Classes/GameTestArcadeScene.o"
	@echo "... Classes/GameTestArcadeScene.i"
	@echo "... Classes/GameTestArcadeScene.s"
	@echo "... Classes/Grid.o"
	@echo "... Classes/Grid.i"
	@echo "... Classes/Grid.s"
	@echo "... Classes/PointGrid.o"
	@echo "... Classes/PointGrid.i"
	@echo "... Classes/PointGrid.s"
	@echo "... Classes/Sphere.o"
	@echo "... Classes/Sphere.i"
	@echo "... Classes/Sphere.s"
	@echo "... proj.linux/main.o"
	@echo "... proj.linux/main.i"
	@echo "... proj.linux/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

