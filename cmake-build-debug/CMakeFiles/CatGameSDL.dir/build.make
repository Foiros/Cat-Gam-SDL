# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\JetBrains\CLion 2021.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\JetBrains\CLion 2021.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\CatGameSDL.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\CatGameSDL.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\CatGameSDL.dir\flags.make

CMakeFiles\CatGameSDL.dir\SDL\main.cpp.obj: CMakeFiles\CatGameSDL.dir\flags.make
CMakeFiles\CatGameSDL.dir\SDL\main.cpp.obj: ..\SDL\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CatGameSDL.dir/SDL/main.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\CatGameSDL.dir\SDL\main.cpp.obj /FdCMakeFiles\CatGameSDL.dir\ /FS -c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\main.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CatGameSDL.dir/SDL/main.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\CatGameSDL.dir\SDL\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\main.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CatGameSDL.dir/SDL/main.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CatGameSDL.dir\SDL\main.cpp.s /c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\main.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\AnimatedTexture.cpp.obj: CMakeFiles\CatGameSDL.dir\flags.make
CMakeFiles\CatGameSDL.dir\SDL\AnimatedTexture.cpp.obj: ..\SDL\AnimatedTexture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CatGameSDL.dir/SDL/AnimatedTexture.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\CatGameSDL.dir\SDL\AnimatedTexture.cpp.obj /FdCMakeFiles\CatGameSDL.dir\ /FS -c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\AnimatedTexture.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\AnimatedTexture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CatGameSDL.dir/SDL/AnimatedTexture.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\CatGameSDL.dir\SDL\AnimatedTexture.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\AnimatedTexture.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\AnimatedTexture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CatGameSDL.dir/SDL/AnimatedTexture.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CatGameSDL.dir\SDL\AnimatedTexture.cpp.s /c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\AnimatedTexture.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\AssetManager.cpp.obj: CMakeFiles\CatGameSDL.dir\flags.make
CMakeFiles\CatGameSDL.dir\SDL\AssetManager.cpp.obj: ..\SDL\AssetManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CatGameSDL.dir/SDL/AssetManager.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\CatGameSDL.dir\SDL\AssetManager.cpp.obj /FdCMakeFiles\CatGameSDL.dir\ /FS -c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\AssetManager.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\AssetManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CatGameSDL.dir/SDL/AssetManager.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\CatGameSDL.dir\SDL\AssetManager.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\AssetManager.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\AssetManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CatGameSDL.dir/SDL/AssetManager.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CatGameSDL.dir\SDL\AssetManager.cpp.s /c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\AssetManager.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\AudioManager.cpp.obj: CMakeFiles\CatGameSDL.dir\flags.make
CMakeFiles\CatGameSDL.dir\SDL\AudioManager.cpp.obj: ..\SDL\AudioManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CatGameSDL.dir/SDL/AudioManager.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\CatGameSDL.dir\SDL\AudioManager.cpp.obj /FdCMakeFiles\CatGameSDL.dir\ /FS -c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\AudioManager.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\AudioManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CatGameSDL.dir/SDL/AudioManager.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\CatGameSDL.dir\SDL\AudioManager.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\AudioManager.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\AudioManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CatGameSDL.dir/SDL/AudioManager.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CatGameSDL.dir\SDL\AudioManager.cpp.s /c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\AudioManager.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\GameEntity.cpp.obj: CMakeFiles\CatGameSDL.dir\flags.make
CMakeFiles\CatGameSDL.dir\SDL\GameEntity.cpp.obj: ..\SDL\GameEntity.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CatGameSDL.dir/SDL/GameEntity.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\CatGameSDL.dir\SDL\GameEntity.cpp.obj /FdCMakeFiles\CatGameSDL.dir\ /FS -c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\GameEntity.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\GameEntity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CatGameSDL.dir/SDL/GameEntity.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\CatGameSDL.dir\SDL\GameEntity.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\GameEntity.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\GameEntity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CatGameSDL.dir/SDL/GameEntity.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CatGameSDL.dir\SDL\GameEntity.cpp.s /c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\GameEntity.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\GameManager.cpp.obj: CMakeFiles\CatGameSDL.dir\flags.make
CMakeFiles\CatGameSDL.dir\SDL\GameManager.cpp.obj: ..\SDL\GameManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/CatGameSDL.dir/SDL/GameManager.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\CatGameSDL.dir\SDL\GameManager.cpp.obj /FdCMakeFiles\CatGameSDL.dir\ /FS -c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\GameManager.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\GameManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CatGameSDL.dir/SDL/GameManager.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\CatGameSDL.dir\SDL\GameManager.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\GameManager.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\GameManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CatGameSDL.dir/SDL/GameManager.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CatGameSDL.dir\SDL\GameManager.cpp.s /c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\GameManager.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\Graphics.cpp.obj: CMakeFiles\CatGameSDL.dir\flags.make
CMakeFiles\CatGameSDL.dir\SDL\Graphics.cpp.obj: ..\SDL\Graphics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/CatGameSDL.dir/SDL/Graphics.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\CatGameSDL.dir\SDL\Graphics.cpp.obj /FdCMakeFiles\CatGameSDL.dir\ /FS -c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\Graphics.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\Graphics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CatGameSDL.dir/SDL/Graphics.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\CatGameSDL.dir\SDL\Graphics.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\Graphics.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\Graphics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CatGameSDL.dir/SDL/Graphics.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CatGameSDL.dir\SDL\Graphics.cpp.s /c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\Graphics.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\InputManager.cpp.obj: CMakeFiles\CatGameSDL.dir\flags.make
CMakeFiles\CatGameSDL.dir\SDL\InputManager.cpp.obj: ..\SDL\InputManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/CatGameSDL.dir/SDL/InputManager.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\CatGameSDL.dir\SDL\InputManager.cpp.obj /FdCMakeFiles\CatGameSDL.dir\ /FS -c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\InputManager.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\InputManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CatGameSDL.dir/SDL/InputManager.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\CatGameSDL.dir\SDL\InputManager.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\InputManager.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\InputManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CatGameSDL.dir/SDL/InputManager.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CatGameSDL.dir\SDL\InputManager.cpp.s /c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\InputManager.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\Texture.cpp.obj: CMakeFiles\CatGameSDL.dir\flags.make
CMakeFiles\CatGameSDL.dir\SDL\Texture.cpp.obj: ..\SDL\Texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/CatGameSDL.dir/SDL/Texture.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\CatGameSDL.dir\SDL\Texture.cpp.obj /FdCMakeFiles\CatGameSDL.dir\ /FS -c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\Texture.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CatGameSDL.dir/SDL/Texture.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\CatGameSDL.dir\SDL\Texture.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\Texture.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CatGameSDL.dir/SDL/Texture.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CatGameSDL.dir\SDL\Texture.cpp.s /c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\Texture.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\Timer.cpp.obj: CMakeFiles\CatGameSDL.dir\flags.make
CMakeFiles\CatGameSDL.dir\SDL\Timer.cpp.obj: ..\SDL\Timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/CatGameSDL.dir/SDL/Timer.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\CatGameSDL.dir\SDL\Timer.cpp.obj /FdCMakeFiles\CatGameSDL.dir\ /FS -c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\Timer.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\Timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CatGameSDL.dir/SDL/Timer.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\CatGameSDL.dir\SDL\Timer.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\Timer.cpp"
<<

CMakeFiles\CatGameSDL.dir\SDL\Timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CatGameSDL.dir/SDL/Timer.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CatGameSDL.dir\SDL\Timer.cpp.s /c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\SDL\Timer.cpp"
<<

CMakeFiles\CatGameSDL.dir\Pathfinding\PathfindingClosedList.cpp.obj: CMakeFiles\CatGameSDL.dir\flags.make
CMakeFiles\CatGameSDL.dir\Pathfinding\PathfindingClosedList.cpp.obj: ..\Pathfinding\PathfindingClosedList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/CatGameSDL.dir/Pathfinding/PathfindingClosedList.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\CatGameSDL.dir\Pathfinding\PathfindingClosedList.cpp.obj /FdCMakeFiles\CatGameSDL.dir\ /FS -c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\Pathfinding\PathfindingClosedList.cpp"
<<

CMakeFiles\CatGameSDL.dir\Pathfinding\PathfindingClosedList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CatGameSDL.dir/Pathfinding/PathfindingClosedList.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\CatGameSDL.dir\Pathfinding\PathfindingClosedList.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\Pathfinding\PathfindingClosedList.cpp"
<<

CMakeFiles\CatGameSDL.dir\Pathfinding\PathfindingClosedList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CatGameSDL.dir/Pathfinding/PathfindingClosedList.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CatGameSDL.dir\Pathfinding\PathfindingClosedList.cpp.s /c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\Pathfinding\PathfindingClosedList.cpp"
<<

CMakeFiles\CatGameSDL.dir\Pathfinding\PathfindingOpenList.cpp.obj: CMakeFiles\CatGameSDL.dir\flags.make
CMakeFiles\CatGameSDL.dir\Pathfinding\PathfindingOpenList.cpp.obj: ..\Pathfinding\PathfindingOpenList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/CatGameSDL.dir/Pathfinding/PathfindingOpenList.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\CatGameSDL.dir\Pathfinding\PathfindingOpenList.cpp.obj /FdCMakeFiles\CatGameSDL.dir\ /FS -c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\Pathfinding\PathfindingOpenList.cpp"
<<

CMakeFiles\CatGameSDL.dir\Pathfinding\PathfindingOpenList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CatGameSDL.dir/Pathfinding/PathfindingOpenList.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\CatGameSDL.dir\Pathfinding\PathfindingOpenList.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\Pathfinding\PathfindingOpenList.cpp"
<<

CMakeFiles\CatGameSDL.dir\Pathfinding\PathfindingOpenList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CatGameSDL.dir/Pathfinding/PathfindingOpenList.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CatGameSDL.dir\Pathfinding\PathfindingOpenList.cpp.s /c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\Pathfinding\PathfindingOpenList.cpp"
<<

CMakeFiles\CatGameSDL.dir\Pathfinding\Pathfinding.cpp.obj: CMakeFiles\CatGameSDL.dir\flags.make
CMakeFiles\CatGameSDL.dir\Pathfinding\Pathfinding.cpp.obj: ..\Pathfinding\Pathfinding.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/CatGameSDL.dir/Pathfinding/Pathfinding.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\CatGameSDL.dir\Pathfinding\Pathfinding.cpp.obj /FdCMakeFiles\CatGameSDL.dir\ /FS -c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\Pathfinding\Pathfinding.cpp"
<<

CMakeFiles\CatGameSDL.dir\Pathfinding\Pathfinding.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CatGameSDL.dir/Pathfinding/Pathfinding.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\CatGameSDL.dir\Pathfinding\Pathfinding.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\Pathfinding\Pathfinding.cpp"
<<

CMakeFiles\CatGameSDL.dir\Pathfinding\Pathfinding.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CatGameSDL.dir/Pathfinding/Pathfinding.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CatGameSDL.dir\Pathfinding\Pathfinding.cpp.s /c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\Pathfinding\Pathfinding.cpp"
<<

CMakeFiles\CatGameSDL.dir\Pathfinding\SearchLevel.cpp.obj: CMakeFiles\CatGameSDL.dir\flags.make
CMakeFiles\CatGameSDL.dir\Pathfinding\SearchLevel.cpp.obj: ..\Pathfinding\SearchLevel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/CatGameSDL.dir/Pathfinding/SearchLevel.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\CatGameSDL.dir\Pathfinding\SearchLevel.cpp.obj /FdCMakeFiles\CatGameSDL.dir\ /FS -c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\Pathfinding\SearchLevel.cpp"
<<

CMakeFiles\CatGameSDL.dir\Pathfinding\SearchLevel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CatGameSDL.dir/Pathfinding/SearchLevel.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\CatGameSDL.dir\Pathfinding\SearchLevel.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\Pathfinding\SearchLevel.cpp"
<<

CMakeFiles\CatGameSDL.dir\Pathfinding\SearchLevel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CatGameSDL.dir/Pathfinding/SearchLevel.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CatGameSDL.dir\Pathfinding\SearchLevel.cpp.s /c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\Pathfinding\SearchLevel.cpp"
<<

CMakeFiles\CatGameSDL.dir\Pathfinding\SearchNode.cpp.obj: CMakeFiles\CatGameSDL.dir\flags.make
CMakeFiles\CatGameSDL.dir\Pathfinding\SearchNode.cpp.obj: ..\Pathfinding\SearchNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/CatGameSDL.dir/Pathfinding/SearchNode.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\CatGameSDL.dir\Pathfinding\SearchNode.cpp.obj /FdCMakeFiles\CatGameSDL.dir\ /FS -c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\Pathfinding\SearchNode.cpp"
<<

CMakeFiles\CatGameSDL.dir\Pathfinding\SearchNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CatGameSDL.dir/Pathfinding/SearchNode.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\CatGameSDL.dir\Pathfinding\SearchNode.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\Pathfinding\SearchNode.cpp"
<<

CMakeFiles\CatGameSDL.dir\Pathfinding\SearchNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CatGameSDL.dir/Pathfinding/SearchNode.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CatGameSDL.dir\Pathfinding\SearchNode.cpp.s /c "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\Pathfinding\SearchNode.cpp"
<<

# Object files for target CatGameSDL
CatGameSDL_OBJECTS = \
"CMakeFiles\CatGameSDL.dir\SDL\main.cpp.obj" \
"CMakeFiles\CatGameSDL.dir\SDL\AnimatedTexture.cpp.obj" \
"CMakeFiles\CatGameSDL.dir\SDL\AssetManager.cpp.obj" \
"CMakeFiles\CatGameSDL.dir\SDL\AudioManager.cpp.obj" \
"CMakeFiles\CatGameSDL.dir\SDL\GameEntity.cpp.obj" \
"CMakeFiles\CatGameSDL.dir\SDL\GameManager.cpp.obj" \
"CMakeFiles\CatGameSDL.dir\SDL\Graphics.cpp.obj" \
"CMakeFiles\CatGameSDL.dir\SDL\InputManager.cpp.obj" \
"CMakeFiles\CatGameSDL.dir\SDL\Texture.cpp.obj" \
"CMakeFiles\CatGameSDL.dir\SDL\Timer.cpp.obj" \
"CMakeFiles\CatGameSDL.dir\Pathfinding\PathfindingClosedList.cpp.obj" \
"CMakeFiles\CatGameSDL.dir\Pathfinding\PathfindingOpenList.cpp.obj" \
"CMakeFiles\CatGameSDL.dir\Pathfinding\Pathfinding.cpp.obj" \
"CMakeFiles\CatGameSDL.dir\Pathfinding\SearchLevel.cpp.obj" \
"CMakeFiles\CatGameSDL.dir\Pathfinding\SearchNode.cpp.obj"

# External object files for target CatGameSDL
CatGameSDL_EXTERNAL_OBJECTS =

CatGameSDL.exe: CMakeFiles\CatGameSDL.dir\SDL\main.cpp.obj
CatGameSDL.exe: CMakeFiles\CatGameSDL.dir\SDL\AnimatedTexture.cpp.obj
CatGameSDL.exe: CMakeFiles\CatGameSDL.dir\SDL\AssetManager.cpp.obj
CatGameSDL.exe: CMakeFiles\CatGameSDL.dir\SDL\AudioManager.cpp.obj
CatGameSDL.exe: CMakeFiles\CatGameSDL.dir\SDL\GameEntity.cpp.obj
CatGameSDL.exe: CMakeFiles\CatGameSDL.dir\SDL\GameManager.cpp.obj
CatGameSDL.exe: CMakeFiles\CatGameSDL.dir\SDL\Graphics.cpp.obj
CatGameSDL.exe: CMakeFiles\CatGameSDL.dir\SDL\InputManager.cpp.obj
CatGameSDL.exe: CMakeFiles\CatGameSDL.dir\SDL\Texture.cpp.obj
CatGameSDL.exe: CMakeFiles\CatGameSDL.dir\SDL\Timer.cpp.obj
CatGameSDL.exe: CMakeFiles\CatGameSDL.dir\Pathfinding\PathfindingClosedList.cpp.obj
CatGameSDL.exe: CMakeFiles\CatGameSDL.dir\Pathfinding\PathfindingOpenList.cpp.obj
CatGameSDL.exe: CMakeFiles\CatGameSDL.dir\Pathfinding\Pathfinding.cpp.obj
CatGameSDL.exe: CMakeFiles\CatGameSDL.dir\Pathfinding\SearchLevel.cpp.obj
CatGameSDL.exe: CMakeFiles\CatGameSDL.dir\Pathfinding\SearchNode.cpp.obj
CatGameSDL.exe: CMakeFiles\CatGameSDL.dir\build.make
CatGameSDL.exe: CMakeFiles\CatGameSDL.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_16) "Linking CXX executable CatGameSDL.exe"
	"E:\JetBrains\CLion 2021.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\CatGameSDL.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\CatGameSDL.dir\objects1.rsp @<<
 /out:CatGameSDL.exe /implib:CatGameSDL.lib /pdb:"E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\cmake-build-debug\CatGameSDL.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console   -LIBPATH:E:\SDL\SDL2-2.0.14\lib\x86  -LIBPATH:E:\SDL\SDL2-2.0.14\Images\lib\x86  -LIBPATH:E:\SDL\SDL2-2.0.14\Fonts\lib\x86  -LIBPATH:E:\SDL\SDL2-2.0.14\Audio\lib\x86  SDL2main.lib SDL2.lib SDL2_image.lib SDL2_ttf.lib SDL2_mixer.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\CatGameSDL.dir\build: CatGameSDL.exe

.PHONY : CMakeFiles\CatGameSDL.dir\build

CMakeFiles\CatGameSDL.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CatGameSDL.dir\cmake_clean.cmake
.PHONY : CMakeFiles\CatGameSDL.dir\clean

CMakeFiles\CatGameSDL.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL" "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL" "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\cmake-build-debug" "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\cmake-build-debug" "E:\Yliopisto toita\GitHub\CatGameSDL\Cat-Gam-SDL\cmake-build-debug\CMakeFiles\CatGameSDL.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\CatGameSDL.dir\depend

