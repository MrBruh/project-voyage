# Project Voyage - Design Document

## Overview

A turn-based resource management game with simulation depth comparable to Aurora 4x, featuring a terminal/retro aesthetic UI inspired by Cogmind.

## Core Design Goals

- **Deep Simulation**: Complex, interconnected systems that create emergent gameplay
- **Terminal Aesthetic**: Retro/matrix visual style without being constrained to actual terminal limitations
- **Flexible UI**: Resizable windows, not strictly tiled or monospace-only

## Technology Stack

| Component | Choice | Rationale |
| --------- | ------ | --------- |
| Language | C++ | Performance, control over memory, suitable for complex simulations |
| Graphics | SDL2 | Maximum control over rendering, mature library, good for custom UI systems |
| Text | SDL_ttf | Integrates with SDL2, supports various font styles and sizes |

## UI Design Principles

### Visual Style

- Terminal/retro aesthetic as a *style choice*, not a technical constraint
- Matrix-inspired color schemes (greens, ambers, cyans on dark backgrounds)
- Box-drawing and line elements for panel borders
- Monospace fonts for data-heavy displays (tables, logs)
- Proportional fonts permitted where readability benefits

### Window System

- Resizable panels/windows
- UI elements scale appropriately with window size
- Not locked to character grid - pixel-level positioning allowed
- Consistent visual language across all panels

## Architecture

### Separation of Concerns

```
simulation/     Pure game logic, no rendering dependencies
ui/             Rendering and input handling
core/           Shared utilities, data structures
```

### Development Approach

1. **Simulation-first**: Build and test game systems with minimal/console output
2. **Vertical slices**: Implement one complete system (logic + display) before expanding
3. **Data-driven**: Prefer configuration over hardcoding where practical

## Systems (Planned)

*To be expanded as design progresses*

- Resource management (production, consumption, stockpiles)
- Entity/component architecture for game objects
- Turn/tick system
- Economy simulation

## Open Questions

- Specific resource types and economic model
- Save/load format
- Modding support scope
- Multiplayer considerations

## Answers to Open Questions

- Specific resource types and economic model: TODO
- Save/load format: Custom file type to store user data, but majority of universe data lies in a database file
- Modding support scope: Will want to do in the future, for now none for simplicity
- Multiplayer considerations: There will be no multiplayer

---

*Document created: 2026-01-29*
*Last updated: 2026-01-29*
