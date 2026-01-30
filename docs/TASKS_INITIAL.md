# Initial Tasks - Orbit Visualization

Tasks to create a basic SDL2 window displaying a planet orbiting a star.

## Visual Requirements

- Background: desaturated deep blue
- Star: orange, centered
- Orbital path: green line/circle
- Planet: saturated blue, renders in front of orbital path

## Task Sequence

### Task 1: Set up CMake build system for SDL2 project

Create a CMakeLists.txt that:

- Sets C++ standard (C++17 or later)
- Finds and links SDL2
- Defines the executable target
- Configures output directories

### Task 2: Create SDL2 window initialization

Create main.cpp that:

- Initializes SDL2
- Creates a window with appropriate dimensions
- Creates a renderer
- Implements a basic game loop (event polling, quit on close)
- Properly cleans up SDL2 resources on exit
- Window displays with the desaturated deep blue background color

### Task 3: Render static star at window center

Draw an orange filled circle at the center of the window representing the star.

### Task 4: Draw green orbital path circle

Draw a green circle (unfilled) around the star representing the orbital path.

- Render order: after background, before planet

### Task 5: Render planet on orbital path

Draw a saturated blue filled circle representing the planet.

- Position: on the orbital path circle
- Render order: after orbital path (planet appears in front of the line)

### Task 6: Animate planet orbit around star

Make the planet move along the orbital path over time:

- Track an angle value that increments each frame
- Calculate planet position using trigonometry (cos/sin of angle * orbital radius)
- Use delta time for frame-rate independent movement

---

*Created: 2026-01-30*
