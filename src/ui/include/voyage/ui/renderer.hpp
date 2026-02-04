#pragma once
import <cstdint>;

struct SDL_Renderer;
struct SDL_Window;

namespace voyage::ui {

struct Color {
    std::uint8_t r{0};
    std::uint8_t g{0};
    std::uint8_t b{0};
    std::uint8_t a{255};

    constexpr Color() = default;
    constexpr Color(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a = 255)
        : r(r), g(g), b(b), a(a) {}
};

namespace colors {
    constexpr Color BACKGROUND{15, 25, 45};
    constexpr Color STAR{255, 140, 0};
    constexpr Color ORBIT{0, 200, 100};
    constexpr Color PLANET{50, 100, 255};
}

class Renderer {
public:
    Renderer();
    ~Renderer();

    bool initialize(SDL_Window* window);
    void shutdown();

    void clear(const Color& color);
    void present();

    void setColor(const Color& color);

    SDL_Renderer* getSDLRenderer() { return m_renderer; }

    int getWidth() const;
    int getHeight() const;

private:
    SDL_Renderer* m_renderer{nullptr};
    SDL_Window* m_window{nullptr};
};

} // namespace voyage::ui
