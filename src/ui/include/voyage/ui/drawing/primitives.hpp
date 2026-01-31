#pragma once

struct SDL_Renderer;

namespace voyage::ui::draw {

void filledCircle(SDL_Renderer* renderer, int cx, int cy, int radius);
void circleOutline(SDL_Renderer* renderer, int cx, int cy, int radius);

} // namespace voyage::ui::draw
