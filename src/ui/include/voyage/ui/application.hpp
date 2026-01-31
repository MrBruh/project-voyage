#pragma once
#include <voyage/ui/renderer.hpp>
#include <voyage/ui/panel/system_view.hpp>
#include <voyage/simulation/simulation.hpp>
#include <memory>
#include <string>

struct SDL_Window;

namespace voyage::ui {

struct AppConfig {
    int windowWidth{1280};
    int windowHeight{720};
    std::string windowTitle{"Project Voyage"};
};

class Application {
public:
    explicit Application(const AppConfig& config = {});
    ~Application();

    bool initialize();
    void run();
    void shutdown();

    sim::Simulation& simulation();
    Renderer& renderer();

private:
    AppConfig m_config;
    bool m_running{false};

    SDL_Window* m_window{nullptr};
    std::unique_ptr<Renderer> m_renderer;
    std::unique_ptr<sim::Simulation> m_simulation;
    std::unique_ptr<panel::SystemViewPanel> m_systemView;

    void processEvents();
    void update(double deltaTime);
    void render();
};

} // namespace voyage::ui
