# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

Project Voyage is a turn-based resource management game with Aurora 4x-level simulation depth and a Cogmind-inspired terminal/retro aesthetic UI.

## Technology Stack

- **Language**: C++ (C++17 or later)
- **Graphics**: SDL2
- **Text Rendering**: SDL_ttf
- **Build System**: CMake

## Architecture

The codebase follows strict separation between simulation and presentation:

```
simulation/     Pure game logic, no rendering dependencies
ui/             Rendering and input handling
core/           Shared utilities, data structures
```

**Key principle**: Simulation code must never depend on UI code. Build systems with console/test output first, then add visual representation.

## UI Constraints

- Terminal aesthetic is a *style choice*, not a technical limitation
- Panels are resizable with pixel-level positioning (not character-grid locked)
- Monospace fonts for data tables/logs; proportional fonts allowed elsewhere
- Blue/light blue color scheme with amber accents on dark backgrounds

## Simulation Timing

- Time steps are player-configurable
- Each time step processes over 5 real-time seconds
- Time steps have 5 subdivisions (player can stop mid-step with max 1 subdivision delay)
- System must remain responsive during time step processing

## Build Commands

```bash
cmake -B build -S .
cmake --build build
```

Executable outputs to `build/bin/`.

## Development Approach

Follow vertical slice development: implement one complete system (simulation logic + UI display) before adding the next. Prefer data-driven configuration over hardcoding.
