# C++23 Migration Guide

This document describes the migration of Project Voyage from C++17 to C++23, including the adoption of C++ header units for standard library imports.

## Overview

- **Previous Standard**: C++17
- **New Standard**: C++23
- **CMake Version**: 3.28+ (required for native module support)
- **Migration Date**: 2026-02-04

## Changes Made

### Build System Updates

#### Root CMakeLists.txt
```cmake
cmake_minimum_required(VERSION 3.28)  # Changed from 3.16
set(CMAKE_CXX_STANDARD 23)              # Changed from 17
set(CMAKE_CXX_EXTENSIONS OFF)           # Added for standard conformance

if(MSVC)
    add_compile_options(/std:c++23 /experimental:module)
endif()
```

#### All Target CMakeLists.txt files
- Added `CXX_STANDARD 23` and `CXX_STANDARD_REQUIRED ON` properties to:
  - `voyage_core`
  - `voyage_simulation`
  - `voyage_ui`

### Source Code Changes

#### Header Unit Conversions

All standard library headers have been converted from `#include` to `import` statements using the header unit syntax.

**Before:**
```cpp
#include <vector>
#include <string>
#include <memory>
```

**After:**
```cpp
import <vector>;
import <string>;
import <memory>;
```

#### Converted Headers by Library

**voyage_core:**
- `types.hpp`: `#include <cstdint>` → `import <cstdint>;`
- `math.hpp`: `#include <cmath>` → `import <cmath>;`

**voyage_simulation:**
- `entity.hpp`: `#include <unordered_set>`, `#include <vector>` → imports
- `component.hpp`: `#include <typeindex>`, `#include <any>`, `#include <unordered_map>` → imports, added `import <typeinfo>;`
- `world.hpp`: `#include <memory>`, `#include <vector>` → imports
- `time_system.hpp`: `#include <functional>`, `#include <vector>`, `#include <atomic>` → imports
- `simulation.hpp`: `#include <memory>` → import

**voyage_ui:**
- `renderer.hpp`: `#include <cstdint>` → `import <cstdint>;`
- `application.hpp`: `#include <memory>`, `#include <string>` → imports
- `panel.hpp`: `#include <string>` → `import <string>;`

**Implementation Files:**
- `ui/src/panel/system_view.cpp`: `#include <cmath>` → `import <cmath>;`

### What Was NOT Changed

#### Project Headers
All project headers continue to use `#include` directives:
```cpp
#include <voyage/core/types.hpp>
#include <voyage/simulation/world.hpp>
```

This is intentional because:
- Project headers need to support forward declarations
- Mix of `#include` and `import` is well-supported
- Maintains compatibility with tools that may not fully support modules yet

#### SDL2 Headers
SDL2 headers must remain as `#include`:
```cpp
#include <SDL.h>
```
SDL headers are C-based and cannot be imported as C++ modules.

## Import Syntax Guidelines

### Standard Library Headers
Use `import <header>;` syntax for explicit imports:
```cpp
import <cstdint>;
import <vector>;
import <string>;
import <functional>;
import <atomic>;
```

### Project Headers
Continue using `#include` for project headers:
```cpp
#include <voyage/core/types.hpp>
#include <voyage/simulation/ecs/world.hpp>
```

### External Library Headers
Use `#include` for external C-based libraries (SDL2, etc.):
```cpp
#include <SDL.h>
```

## Build Requirements

### Minimum Versions
- **CMake**: 3.28 or later
- **MSVC**: Visual Studio 2022 17.8+ with `/std:c++23`
- **GCC**: 13+ with `-std=c++23 -fmodules-ts`
- **Clang**: 16+ with `-std=c++23 -fmodules-ts`

### MSVC-Specific Notes
- Requires `/std:c++23` flag
- Requires `/experimental:module` flag for header unit support
- MSVC has the most mature C++23 module implementation

## Benefits of This Migration

1. **Faster Compilation**: Header units precompile standard library headers once, reducing rebuild times
2. **Better Isolation**: Importing headers prevents macro pollution and name conflicts
3. **Explicit Dependencies**: Import statements clearly declare module dependencies
4. **Future-Ready**: Foundation for converting project headers to modules in the future

## Potential Issues and Workarounds

### LSP/IDE Errors
Some language servers may show errors for `import <header>;` syntax. These are false positives from incomplete LSP module support. The code compiles correctly with MSVC 17.8+.

### Template Metaprogramming
Some advanced template techniques may need adjustment when switching to modules. This project's current usage is compatible.

### Incremental Builds
CMake 3.28's native module support properly handles incremental builds with header units.

## Future Considerations

### Full Module Migration
This migration only converts standard library headers to header units. Future work could:
- Convert project headers to C++20 modules (`.cppm` files)
- Create module boundaries for voyage_core, voyage_simulation, voyage_ui
- Use module partitions for large headers

### Compiler Support
As compiler support for C++23 modules improves, we may be able to:
- Remove the `/experimental:module` flag for MSVC
- Enable additional C++23 features

## Rolling Back

If issues arise, the migration can be reverted by:
1. Reverting all `import <header>;` to `#include <header>`
2. Reverting CMakeLists.txt files to C++17
3. Reverting cmake_minimum_required to 3.16

---

*Document created: 2026-02-04*
*Last updated: 2026-02-04*