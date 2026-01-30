#include <SDL.h>
#include <cmath>

constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;

constexpr Uint8 BG_R = 15;
constexpr Uint8 BG_G = 25;
constexpr Uint8 BG_B = 45;

constexpr Uint8 STAR_R = 255;
constexpr Uint8 STAR_G = 140;
constexpr Uint8 STAR_B = 0;
constexpr int STAR_RADIUS = 30;

constexpr Uint8 ORBIT_R = 0;
constexpr Uint8 ORBIT_G = 200;
constexpr Uint8 ORBIT_B = 100;
constexpr int ORBIT_RADIUS = 150;

constexpr Uint8 PLANET_R = 50;
constexpr Uint8 PLANET_G = 100;
constexpr Uint8 PLANET_B = 255;
constexpr int PLANET_RADIUS = 15;

constexpr double ORBIT_SPEED = 0.5;

void drawFilledCircle(SDL_Renderer* renderer, int cx, int cy, int radius) {
    for (int y = -radius; y <= radius; y++) {
        int dx = static_cast<int>(SDL_sqrt(radius * radius - y * y));
        SDL_RenderDrawLine(renderer, cx - dx, cy + y, cx + dx, cy + y);
    }
}

void drawCircleOutline(SDL_Renderer* renderer, int cx, int cy, int radius) {
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y) {
        SDL_RenderDrawPoint(renderer, cx + x, cy + y);
        SDL_RenderDrawPoint(renderer, cx + y, cy + x);
        SDL_RenderDrawPoint(renderer, cx - y, cy + x);
        SDL_RenderDrawPoint(renderer, cx - x, cy + y);
        SDL_RenderDrawPoint(renderer, cx - x, cy - y);
        SDL_RenderDrawPoint(renderer, cx - y, cy - x);
        SDL_RenderDrawPoint(renderer, cx + y, cy - x);
        SDL_RenderDrawPoint(renderer, cx + x, cy - y);

        y++;
        err += 1 + 2 * y;
        if (2 * (err - x) + 1 > 0) {
            x--;
            err += 1 - 2 * x;
        }
    }
}

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL initialization failed: %s", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Project Voyage",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );

    if (!window) {
        SDL_Log("Window creation failed: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (!renderer) {
        SDL_Log("Renderer creation failed: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Event event;

    double angle = 0.0;
    Uint64 lastTime = SDL_GetPerformanceCounter();
    Uint64 frequency = SDL_GetPerformanceFrequency();

    while (running) {
        Uint64 currentTime = SDL_GetPerformanceCounter();
        double deltaTime = static_cast<double>(currentTime - lastTime) / frequency;
        lastTime = currentTime;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                running = false;
            }
        }

        angle += ORBIT_SPEED * deltaTime;

        SDL_SetRenderDrawColor(renderer, BG_R, BG_G, BG_B, 255);
        SDL_RenderClear(renderer);

        int centerX = WINDOW_WIDTH / 2;
        int centerY = WINDOW_HEIGHT / 2;

        SDL_SetRenderDrawColor(renderer, STAR_R, STAR_G, STAR_B, 255);
        drawFilledCircle(renderer, centerX, centerY, STAR_RADIUS);

        SDL_SetRenderDrawColor(renderer, ORBIT_R, ORBIT_G, ORBIT_B, 255);
        drawCircleOutline(renderer, centerX, centerY, ORBIT_RADIUS);

        int planetX = centerX + static_cast<int>(ORBIT_RADIUS * std::cos(angle));
        int planetY = centerY + static_cast<int>(ORBIT_RADIUS * std::sin(angle));

        SDL_SetRenderDrawColor(renderer, PLANET_R, PLANET_G, PLANET_B, 255);
        drawFilledCircle(renderer, planetX, planetY, PLANET_RADIUS);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
