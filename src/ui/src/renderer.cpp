#include <voyage/ui/renderer.hpp>
#include <SDL.h>

namespace voyage::ui {

Renderer::Renderer() = default;

Renderer::~Renderer() {
    shutdown();
}

bool Renderer::initialize(SDL_Window* window) {
    m_window = window;
    m_renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (!m_renderer) {
        SDL_Log("Renderer creation failed: %s", SDL_GetError());
        return false;
    }

    return true;
}

void Renderer::shutdown() {
    if (m_renderer) {
        SDL_DestroyRenderer(m_renderer);
        m_renderer = nullptr;
    }
    m_window = nullptr;
}

void Renderer::clear(const Color& color) {
    SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(m_renderer);
}

void Renderer::present() {
    SDL_RenderPresent(m_renderer);
}

void Renderer::setColor(const Color& color) {
    SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
}

int Renderer::getWidth() const {
    int w, h;
    SDL_GetWindowSize(m_window, &w, &h);
    return w;
}

int Renderer::getHeight() const {
    int w, h;
    SDL_GetWindowSize(m_window, &w, &h);
    return h;
}

} // namespace voyage::ui
