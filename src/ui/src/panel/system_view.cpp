#include <voyage/ui/panel/system_view.hpp>
#include <voyage/ui/renderer.hpp>
#include <voyage/ui/drawing/primitives.hpp>
#include <voyage/simulation/simulation.hpp>
#include <cmath>

namespace voyage::ui::panel {

SystemViewPanel::SystemViewPanel()
    : Panel("System View") {}

void SystemViewPanel::update(const sim::Simulation& /*sim*/, double deltaTime) {
    m_angle += m_orbitSpeed * deltaTime;
}

void SystemViewPanel::render(Renderer& renderer) {
    if (!m_visible) {
        return;
    }

    int centerX = renderer.getWidth() / 2;
    int centerY = renderer.getHeight() / 2;

    renderer.setColor(colors::STAR);
    draw::filledCircle(renderer.getSDLRenderer(), centerX, centerY, STAR_RADIUS);

    renderer.setColor(colors::ORBIT);
    draw::circleOutline(renderer.getSDLRenderer(), centerX, centerY, ORBIT_RADIUS);

    int planetX = centerX + static_cast<int>(ORBIT_RADIUS * std::cos(m_angle));
    int planetY = centerY + static_cast<int>(ORBIT_RADIUS * std::sin(m_angle));

    renderer.setColor(colors::PLANET);
    draw::filledCircle(renderer.getSDLRenderer(), planetX, planetY, PLANET_RADIUS);
}

} // namespace voyage::ui::panel
