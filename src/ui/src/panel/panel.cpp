#include <voyage/ui/panel/panel.hpp>

namespace voyage::ui::panel {

Panel::Panel(const std::string& title)
    : m_title(title) {}

void Panel::setRect(const Rect& rect) {
    m_rect = rect;
}

Rect Panel::getRect() const {
    return m_rect;
}

void Panel::setVisible(bool visible) {
    m_visible = visible;
}

bool Panel::isVisible() const {
    return m_visible;
}

const std::string& Panel::getTitle() const {
    return m_title;
}

} // namespace voyage::ui::panel
