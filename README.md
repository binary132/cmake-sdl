# cmake-sdl
A simple CMake SDL test project

 - [What you need](#what-you-need)
 - [Setting up your build](#setting-up-your-build)

# What you need

 - [CMake 2.8.12](www.cmake.org/download) or greater
 - A C++11 toolchain:
   - [Microsoft Visual Studio Community Edition](https://www.visualstudio.com/products/visual-studio-community-vs) is a gratis option for Windows.
   - [XCode](https://developer.apple.com/xcode/downloads/)
   - GCC / GNU Make \[Configuration depends on OS\]
   - Optionally [Ninja](https://github.com/martine/ninja/releases) for faster builds
   - [Eclipse CDT](https://eclipse.org/cdt/)
   - [Codeblocks](http://www.codeblocks.org/downloads/26)
   - etc.
 - [LibSDL2](https://www.libsdl.org/download-2.0.php) "Development Libraries"
   - If you're on Windows, [set an SDL2LIB environment variable](http://www.computerhope.com/issues/ch000549.htm) to the path of your SDL2 installation.
   - If you're on Mac OS X, [use Homebrew](http://brew.sh/).  `brew install sdl2`
   - GNU/Linux should be straightforward.
 
# Setting up your build

CMake is a Makefile generator.  That means a single CMake configuration can be used to build and deploy software for any toolchain which supports it, e.g. GNU Make, Visual Studio, XCode, etc.

What this means for us is that we need to run CMake first to generate our build, and then run the build using our native toolchain.

> List available toolchains:

```bash
cmake --help
...
Generators

The following generators are available on this platform:
  Unix Makefiles              = Generates standard UNIX makefiles.
  Ninja                       = Generates build.ninja files (experimental).
  CodeBlocks - Ninja          = Generates CodeBlocks project files.
  CodeBlocks - Unix Makefiles = Generates CodeBlocks project files.
  Eclipse CDT4 - Ninja        = Generates Eclipse CDT 4.0 project files.
  Eclipse CDT4 - Unix Makefiles
                              = Generates Eclipse CDT 4.0 project files.
  KDevelop3                   = Generates KDevelop 3 project files.
  KDevelop3 - Unix Makefiles  = Generates KDevelop 3 project files.
  Sublime Text 2 - Ninja      = Generates Sublime Text 2 project files.
  Sublime Text 2 - Unix Makefiles
                              = Generates Sublime Text 2 project files.
```

Use your generator:

 > Note: for Windows `NMake Makefiles`, you'll need to be in the [Developer command prompt](https://msdn.microsoft.com/en-us/library/ms229859(v=vs.110).aspx).
 
```bash
git clone https://github.com/binary132/cmake-sdl.git
cd cmake-sdl
cd build
cmake -G "Ninja" .. # Or -G "NMake Makefiles" on Windows
ninja # or nmake, or make, or open project file in XCode, etc.
```

The result should be a successful build, with an executable in `<project root>/build/target` named `SDLTest`.

# Running your build

For an OS with a distribution of SDL2 installed, the binary should be executable as-is.  On Windows, you'll need to copy `SDL2.dll` from your SDL2 install location.
