# Project Voyage Architecture

## Overview

The codebase is organized into four CMake targets with strict dependency separation:

```
voyage_core       → No external dependencies (pure C++)
voyage_simulation → Links only voyage_core (NO SDL2)
voyage_ui         → Links voyage_core, voyage_simulation, SDL2
ProjectVoyage     → Links voyage_ui (executable)
```

**Key Enforcement**: If simulation code accidentally includes SDL headers, the build fails.

## Directory Structure

```
src/
├── CMakeLists.txt
├── core/                         # Shared utilities (no SDL)
│   ├── CMakeLists.txt
│   ├── include/voyage/core/
│   │   ├── types.hpp             # EntityId, ResourceId, Ticks, GameDuration
│   │   └── math.hpp              # Vec2, Vec3, math utilities
│   └── src/
│       └── math.cpp
│
├── simulation/                   # Pure game logic (ZERO SDL)
│   ├── CMakeLists.txt
│   ├── include/voyage/simulation/
│   │   ├── simulation.hpp        # Main facade
│   │   ├── time_system.hpp       # 5-subdivision tick system
│   │   └── ecs/
│   │       ├── entity.hpp        # Entity manager
│   │       ├── component.hpp     # Component registry (template-based)
│   │       ├── system.hpp        # System base class
│   │       └── world.hpp         # ECS container
│   └── src/
│       ├── simulation.cpp
│       ├── time_system.cpp
│       └── ecs/
│           └── world.cpp
│
├── ui/                           # SDL2-dependent rendering
│   ├── CMakeLists.txt
│   ├── include/voyage/ui/
│   │   ├── application.hpp       # Main app lifecycle
│   │   ├── renderer.hpp          # SDL2 wrapper + color definitions
│   │   ├── panel/
│   │   │   ├── panel.hpp         # Base panel class
│   │   │   └── system_view.hpp   # Orbit visualization
│   │   └── drawing/
│   │       └── primitives.hpp    # Circle, line functions
│   └── src/
│       ├── application.cpp
│       ├── renderer.cpp
│       ├── panel/
│       │   ├── panel.cpp
│       │   └── system_view.cpp
│       └── drawing/
│           └── primitives.cpp
│
└── app/                          # Executable entry point
    ├── CMakeLists.txt
    └── main.cpp                  # Minimal bootstrap
```

## Namespace Strategy

```cpp
namespace voyage::core { }      // Types, math, utilities
namespace voyage::sim { }       // All simulation logic
namespace voyage::sim::ecs { }  // Entity-Component-System
namespace voyage::ui { }        // Rendering, input
namespace voyage::ui::panel { } // Panel implementations
namespace voyage::ui::draw { }  // Drawing primitives
```

## Key Components

### Core Library (voyage_core)

- **types.hpp**: Fundamental types - `EntityId`, `ResourceId`, `Ticks`, `GameDuration`
- **math.hpp**: `Vec2`, `Vec3`, angle conversions

### Simulation Library (voyage_simulation)

- **TimeSystem**: Manages game ticks with 5 subdivisions per tick, interruptible
- **ECS World**: Entity creation/destruction, component storage, system updates
- **Simulation**: Main facade coordinating time and world

### UI Library (voyage_ui)

- **Application**: SDL2 initialization, game loop, shutdown
- **Renderer**: SDL2 renderer wrapper with color management
- **Panel**: Base class for UI panels with visibility and positioning
- **SystemViewPanel**: Renders orbit visualization (star + planet)
- **Primitives**: Circle drawing functions (filled and outline)

## Build Commands

```bash
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE="C:/Users/mdnss/Dev/vcpkg/scripts/buildsystems/vcpkg.cmake"
cmake --build build --config Release
```

Executable outputs to `build/bin/Release/project-voyage.exe`.
