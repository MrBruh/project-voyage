# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

Project Voyage is a turn-based resource management game with Aurora 4x-level simulation depth and a Cogmind-inspired terminal/retro aesthetic UI.

## Technology Stack

- **Language**: C++
- **Graphics**: SDL2
- **Text Rendering**: SDL_ttf

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
- Matrix-inspired color schemes (greens, ambers, cyans on dark backgrounds)

## Development Approach

Follow vertical slice development: implement one complete system (simulation logic + UI display) before adding the next. Prefer data-driven configuration over hardcoding.
