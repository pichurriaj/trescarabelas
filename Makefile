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

Classes/ArcadeMenu/EasyMenu.o: Classes/ArcadeMenu/EasyMenu.cpp.o
.PHONY : Classes/ArcadeMenu/EasyMenu.o

# target to build an object file
Classes/ArcadeMenu/EasyMenu.cpp.o:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/ArcadeMenu/EasyMenu.cpp.o
.PHONY : Classes/ArcadeMenu/EasyMenu.cpp.o

Classes/ArcadeMenu/EasyMenu.i: Classes/ArcadeMenu/EasyMenu.cpp.i
.PHONY : Classes/ArcadeMenu/EasyMenu.i

# target to preprocess a source file
Classes/ArcadeMenu/EasyMenu.cpp.i:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/ArcadeMenu/EasyMenu.cpp.i
.PHONY : Classes/ArcadeMenu/EasyMenu.cpp.i

Classes/ArcadeMenu/EasyMenu.s: Classes/ArcadeMenu/EasyMenu.cpp.s
.PHONY : Classes/ArcadeMenu/EasyMenu.s

# target to generate assembly for a file
Classes/ArcadeMenu/EasyMenu.cpp.s:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/ArcadeMenu/EasyMenu.cpp.s
.PHONY : Classes/ArcadeMenu/EasyMenu.cpp.s

Classes/ArcadeMenu/EndGameMenu.o: Classes/ArcadeMenu/EndGameMenu.cpp.o
.PHONY : Classes/ArcadeMenu/EndGameMenu.o

# target to build an object file
Classes/ArcadeMenu/EndGameMenu.cpp.o:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/ArcadeMenu/EndGameMenu.cpp.o
.PHONY : Classes/ArcadeMenu/EndGameMenu.cpp.o

Classes/ArcadeMenu/EndGameMenu.i: Classes/ArcadeMenu/EndGameMenu.cpp.i
.PHONY : Classes/ArcadeMenu/EndGameMenu.i

# target to preprocess a source file
Classes/ArcadeMenu/EndGameMenu.cpp.i:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/ArcadeMenu/EndGameMenu.cpp.i
.PHONY : Classes/ArcadeMenu/EndGameMenu.cpp.i

Classes/ArcadeMenu/EndGameMenu.s: Classes/ArcadeMenu/EndGameMenu.cpp.s
.PHONY : Classes/ArcadeMenu/EndGameMenu.s

# target to generate assembly for a file
Classes/ArcadeMenu/EndGameMenu.cpp.s:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/ArcadeMenu/EndGameMenu.cpp.s
.PHONY : Classes/ArcadeMenu/EndGameMenu.cpp.s

Classes/ArcadeMenu/MediumMenu.o: Classes/ArcadeMenu/MediumMenu.cpp.o
.PHONY : Classes/ArcadeMenu/MediumMenu.o

# target to build an object file
Classes/ArcadeMenu/MediumMenu.cpp.o:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/ArcadeMenu/MediumMenu.cpp.o
.PHONY : Classes/ArcadeMenu/MediumMenu.cpp.o

Classes/ArcadeMenu/MediumMenu.i: Classes/ArcadeMenu/MediumMenu.cpp.i
.PHONY : Classes/ArcadeMenu/MediumMenu.i

# target to preprocess a source file
Classes/ArcadeMenu/MediumMenu.cpp.i:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/ArcadeMenu/MediumMenu.cpp.i
.PHONY : Classes/ArcadeMenu/MediumMenu.cpp.i

Classes/ArcadeMenu/MediumMenu.s: Classes/ArcadeMenu/MediumMenu.cpp.s
.PHONY : Classes/ArcadeMenu/MediumMenu.s

# target to generate assembly for a file
Classes/ArcadeMenu/MediumMenu.cpp.s:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/ArcadeMenu/MediumMenu.cpp.s
.PHONY : Classes/ArcadeMenu/MediumMenu.cpp.s

Classes/ArcadeMenuScene.o: Classes/ArcadeMenuScene.cpp.o
.PHONY : Classes/ArcadeMenuScene.o

# target to build an object file
Classes/ArcadeMenuScene.cpp.o:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/ArcadeMenuScene.cpp.o
.PHONY : Classes/ArcadeMenuScene.cpp.o

Classes/ArcadeMenuScene.i: Classes/ArcadeMenuScene.cpp.i
.PHONY : Classes/ArcadeMenuScene.i

# target to preprocess a source file
Classes/ArcadeMenuScene.cpp.i:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/ArcadeMenuScene.cpp.i
.PHONY : Classes/ArcadeMenuScene.cpp.i

Classes/ArcadeMenuScene.s: Classes/ArcadeMenuScene.cpp.s
.PHONY : Classes/ArcadeMenuScene.s

# target to generate assembly for a file
Classes/ArcadeMenuScene.cpp.s:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/ArcadeMenuScene.cpp.s
.PHONY : Classes/ArcadeMenuScene.cpp.s

Classes/ArcadeScene.o: Classes/ArcadeScene.cpp.o
.PHONY : Classes/ArcadeScene.o

# target to build an object file
Classes/ArcadeScene.cpp.o:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/ArcadeScene.cpp.o
.PHONY : Classes/ArcadeScene.cpp.o

Classes/ArcadeScene.i: Classes/ArcadeScene.cpp.i
.PHONY : Classes/ArcadeScene.i

# target to preprocess a source file
Classes/ArcadeScene.cpp.i:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/ArcadeScene.cpp.i
.PHONY : Classes/ArcadeScene.cpp.i

Classes/ArcadeScene.s: Classes/ArcadeScene.cpp.s
.PHONY : Classes/ArcadeScene.s

# target to generate assembly for a file
Classes/ArcadeScene.cpp.s:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/ArcadeScene.cpp.s
.PHONY : Classes/ArcadeScene.cpp.s

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

Classes/BoardPopulaterTester.o: Classes/BoardPopulaterTester.cpp.o
.PHONY : Classes/BoardPopulaterTester.o

# target to build an object file
Classes/BoardPopulaterTester.cpp.o:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/BoardPopulaterTester.cpp.o
.PHONY : Classes/BoardPopulaterTester.cpp.o

Classes/BoardPopulaterTester.i: Classes/BoardPopulaterTester.cpp.i
.PHONY : Classes/BoardPopulaterTester.i

# target to preprocess a source file
Classes/BoardPopulaterTester.cpp.i:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/BoardPopulaterTester.cpp.i
.PHONY : Classes/BoardPopulaterTester.cpp.i

Classes/BoardPopulaterTester.s: Classes/BoardPopulaterTester.cpp.s
.PHONY : Classes/BoardPopulaterTester.s

# target to generate assembly for a file
Classes/BoardPopulaterTester.cpp.s:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/BoardPopulaterTester.cpp.s
.PHONY : Classes/BoardPopulaterTester.cpp.s

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

Classes/Indian.o: Classes/Indian.cpp.o
.PHONY : Classes/Indian.o

# target to build an object file
Classes/Indian.cpp.o:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/Indian.cpp.o
.PHONY : Classes/Indian.cpp.o

Classes/Indian.i: Classes/Indian.cpp.i
.PHONY : Classes/Indian.i

# target to preprocess a source file
Classes/Indian.cpp.i:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/Indian.cpp.i
.PHONY : Classes/Indian.cpp.i

Classes/Indian.s: Classes/Indian.cpp.s
.PHONY : Classes/Indian.s

# target to generate assembly for a file
Classes/Indian.cpp.s:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/Indian.cpp.s
.PHONY : Classes/Indian.cpp.s

Classes/LevelManager.o: Classes/LevelManager.cpp.o
.PHONY : Classes/LevelManager.o

# target to build an object file
Classes/LevelManager.cpp.o:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/LevelManager.cpp.o
.PHONY : Classes/LevelManager.cpp.o

Classes/LevelManager.i: Classes/LevelManager.cpp.i
.PHONY : Classes/LevelManager.i

# target to preprocess a source file
Classes/LevelManager.cpp.i:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/LevelManager.cpp.i
.PHONY : Classes/LevelManager.cpp.i

Classes/LevelManager.s: Classes/LevelManager.cpp.s
.PHONY : Classes/LevelManager.s

# target to generate assembly for a file
Classes/LevelManager.cpp.s:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/LevelManager.cpp.s
.PHONY : Classes/LevelManager.cpp.s

Classes/MenuScene.o: Classes/MenuScene.cpp.o
.PHONY : Classes/MenuScene.o

# target to build an object file
Classes/MenuScene.cpp.o:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/MenuScene.cpp.o
.PHONY : Classes/MenuScene.cpp.o

Classes/MenuScene.i: Classes/MenuScene.cpp.i
.PHONY : Classes/MenuScene.i

# target to preprocess a source file
Classes/MenuScene.cpp.i:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/MenuScene.cpp.i
.PHONY : Classes/MenuScene.cpp.i

Classes/MenuScene.s: Classes/MenuScene.cpp.s
.PHONY : Classes/MenuScene.s

# target to generate assembly for a file
Classes/MenuScene.cpp.s:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/MenuScene.cpp.s
.PHONY : Classes/MenuScene.cpp.s

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

Classes/PresentationScene.o: Classes/PresentationScene.cpp.o
.PHONY : Classes/PresentationScene.o

# target to build an object file
Classes/PresentationScene.cpp.o:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/PresentationScene.cpp.o
.PHONY : Classes/PresentationScene.cpp.o

Classes/PresentationScene.i: Classes/PresentationScene.cpp.i
.PHONY : Classes/PresentationScene.i

# target to preprocess a source file
Classes/PresentationScene.cpp.i:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/PresentationScene.cpp.i
.PHONY : Classes/PresentationScene.cpp.i

Classes/PresentationScene.s: Classes/PresentationScene.cpp.s
.PHONY : Classes/PresentationScene.s

# target to generate assembly for a file
Classes/PresentationScene.cpp.s:
	$(MAKE) -f CMakeFiles/trescarabelas.dir/build.make CMakeFiles/trescarabelas.dir/Classes/PresentationScene.cpp.s
.PHONY : Classes/PresentationScene.cpp.s

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
	@echo "... Classes/ArcadeMenu/EasyMenu.o"
	@echo "... Classes/ArcadeMenu/EasyMenu.i"
	@echo "... Classes/ArcadeMenu/EasyMenu.s"
	@echo "... Classes/ArcadeMenu/EndGameMenu.o"
	@echo "... Classes/ArcadeMenu/EndGameMenu.i"
	@echo "... Classes/ArcadeMenu/EndGameMenu.s"
	@echo "... Classes/ArcadeMenu/MediumMenu.o"
	@echo "... Classes/ArcadeMenu/MediumMenu.i"
	@echo "... Classes/ArcadeMenu/MediumMenu.s"
	@echo "... Classes/ArcadeMenuScene.o"
	@echo "... Classes/ArcadeMenuScene.i"
	@echo "... Classes/ArcadeMenuScene.s"
	@echo "... Classes/ArcadeScene.o"
	@echo "... Classes/ArcadeScene.i"
	@echo "... Classes/ArcadeScene.s"
	@echo "... Classes/Board.o"
	@echo "... Classes/Board.i"
	@echo "... Classes/Board.s"
	@echo "... Classes/BoardPopulaterRandom.o"
	@echo "... Classes/BoardPopulaterRandom.i"
	@echo "... Classes/BoardPopulaterRandom.s"
	@echo "... Classes/BoardPopulaterTester.o"
	@echo "... Classes/BoardPopulaterTester.i"
	@echo "... Classes/BoardPopulaterTester.s"
	@echo "... Classes/GameTestArcadeScene.o"
	@echo "... Classes/GameTestArcadeScene.i"
	@echo "... Classes/GameTestArcadeScene.s"
	@echo "... Classes/Grid.o"
	@echo "... Classes/Grid.i"
	@echo "... Classes/Grid.s"
	@echo "... Classes/Indian.o"
	@echo "... Classes/Indian.i"
	@echo "... Classes/Indian.s"
	@echo "... Classes/LevelManager.o"
	@echo "... Classes/LevelManager.i"
	@echo "... Classes/LevelManager.s"
	@echo "... Classes/MenuScene.o"
	@echo "... Classes/MenuScene.i"
	@echo "... Classes/MenuScene.s"
	@echo "... Classes/PointGrid.o"
	@echo "... Classes/PointGrid.i"
	@echo "... Classes/PointGrid.s"
	@echo "... Classes/PresentationScene.o"
	@echo "... Classes/PresentationScene.i"
	@echo "... Classes/PresentationScene.s"
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

