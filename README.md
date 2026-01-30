# Project Voyage

A turn-based resource management game with deep simulation mechanics and a terminal-inspired aesthetic.

## Building

Requires:
- CMake 3.16+
- C++17 compiler
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
