# Project Voyage

A turn-based resource management game with deep simulation mechanics and a terminal-inspired aesthetic.

## Building

Requires:
- CMake 3.28+
- C++23 compiler (MSVC with /std:c++23 or GCC with -std=c++23)
- vcpkg with SDL2 installed

```bash
# Install SDL2 via vcpkg (if not already installed)
vcpkg install sdl2:x64-windows

# Configure and build
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE="<path-to-vcpkg>/scripts/buildsystems/vcpkg.cmake"
cmake --build build --config Release
```

## Running

```bash
./build/bin/Release/project-voyage.exe
```

Press Escape or close the window to exit.
