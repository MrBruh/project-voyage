#include <voyage/ui/application.hpp>

int main(int /*argc*/, char* /*argv*/[]) {
    voyage::ui::AppConfig config;
    config.windowWidth = 1280;
    config.windowHeight = 720;
    config.windowTitle = "Project Voyage";

    voyage::ui::Application app(config);

    if (!app.initialize()) {
        return 1;
    }

    app.run();
    app.shutdown();

    return 0;
}
