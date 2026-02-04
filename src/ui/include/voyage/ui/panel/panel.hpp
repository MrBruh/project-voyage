#pragma once
import <string>;

namespace voyage::ui {
class Renderer;
}

namespace voyage::sim {
class Simulation;
}

namespace voyage::ui::panel {

struct Rect {
    int x{0};
    int y{0};
    int width{200};
    int height{200};
};

class Panel {
public:
    explicit Panel(const std::string& title);
    virtual ~Panel() = default;

    virtual void update(const sim::Simulation& sim, double deltaTime) = 0;
    virtual void render(Renderer& renderer) = 0;

    void setRect(const Rect& rect);
    Rect getRect() const;

    void setVisible(bool visible);
    bool isVisible() const;

    const std::string& getTitle() const;

protected:
    std::string m_title;
    Rect m_rect;
    bool m_visible{true};
};

} // namespace voyage::ui::panel
