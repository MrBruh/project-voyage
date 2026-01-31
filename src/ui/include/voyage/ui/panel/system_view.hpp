#pragma once
#include <voyage/ui/panel/panel.hpp>

namespace voyage::ui::panel {

class SystemViewPanel : public Panel {
public:
    SystemViewPanel();

    void update(const sim::Simulation& sim, double deltaTime) override;
    void render(Renderer& renderer) override;

private:
    double m_angle{0.0};
    double m_orbitSpeed{0.5};

    static constexpr int STAR_RADIUS = 30;
    static constexpr int ORBIT_RADIUS = 150;
    static constexpr int PLANET_RADIUS = 15;
};

} // namespace voyage::ui::panel
