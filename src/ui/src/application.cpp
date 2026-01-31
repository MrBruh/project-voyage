#include <voyage/ui/application.hpp>
#include <SDL.h>

namespace voyage::ui {

Application::Application(const AppConfig& config)
    : m_config(config)
    , m_renderer(std::make_unique<Renderer>())
    , m_simulation(std::make_unique<sim::Simulation>())
    , m_systemView(std::make_unique<panel::SystemViewPanel>()) {}

Application::~Application() {
    shutdown();
}

bool Application::initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL initialization failed: %s", SDL_GetError());
        return false;
    }

    m_window = SDL_CreateWindow(
        m_config.windowTitle.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        m_config.windowWidth,
        m_config.windowHeight,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );

    if (!m_window) {
        SDL_Log("Window creation failed: %s", SDL_GetError());
        SDL_Quit();
        return false;
    }

    if (!m_renderer->initialize(m_window)) {
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }

    m_simulation->initialize();

    return true;
}

void Application::run() {
    m_running = true;

    Uint64 lastTime = SDL_GetPerformanceCounter();
    Uint64 frequency = SDL_GetPerformanceFrequency();

    while (m_running) {
        Uint64 currentTime = SDL_GetPerformanceCounter();
        double deltaTime = static_cast<double>(currentTime - lastTime) / frequency;
        lastTime = currentTime;

        processEvents();
        update(deltaTime);
        render();
    }
}

void Application::shutdown() {
    if (m_simulation) {
        m_simulation->shutdown();
    }

    if (m_renderer) {
        m_renderer->shutdown();
    }

    if (m_window) {
        SDL_DestroyWindow(m_window);
        m_window = nullptr;
    }

    SDL_Quit();
}

sim::Simulation& Application::simulation() {
    return *m_simulation;
}

Renderer& Application::renderer() {
    return *m_renderer;
}

void Application::processEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            m_running = false;
        }
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
            m_running = false;
        }
    }
}

void Application::update(double deltaTime) {
    m_simulation->update(deltaTime);
    m_systemView->update(*m_simulation, deltaTime);
}

void Application::render() {
    m_renderer->clear(colors::BACKGROUND);
    m_systemView->render(*m_renderer);
    m_renderer->present();
}

} // namespace voyage::ui
