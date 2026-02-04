#pragma once
import <cmath>;

namespace voyage::core {

struct Vec2 {
    double x{0.0};
    double y{0.0};

    Vec2() = default;
    Vec2(double x, double y) : x(x), y(y) {}

    Vec2 operator+(const Vec2& other) const { return {x + other.x, y + other.y}; }
    Vec2 operator-(const Vec2& other) const { return {x - other.x, y - other.y}; }
    Vec2 operator*(double scalar) const { return {x * scalar, y * scalar}; }
    Vec2 operator/(double scalar) const { return {x / scalar, y / scalar}; }

    double length() const { return std::sqrt(x * x + y * y); }
    double lengthSquared() const { return x * x + y * y; }

    Vec2 normalized() const {
        double len = length();
        if (len > 0.0) {
            return *this / len;
        }
        return {0.0, 0.0};
    }
};

struct Vec3 {
    double x{0.0};
    double y{0.0};
    double z{0.0};

    Vec3() = default;
    Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

    Vec3 operator+(const Vec3& other) const { return {x + other.x, y + other.y, z + other.z}; }
    Vec3 operator-(const Vec3& other) const { return {x - other.x, y - other.y, z - other.z}; }
    Vec3 operator*(double scalar) const { return {x * scalar, y * scalar, z * scalar}; }
    Vec3 operator/(double scalar) const { return {x / scalar, y / scalar, z / scalar}; }

    double length() const { return std::sqrt(x * x + y * y + z * z); }
    double lengthSquared() const { return x * x + y * y + z * z; }

    Vec3 normalized() const {
        double len = length();
        if (len > 0.0) {
            return *this / len;
        }
        return {0.0, 0.0, 0.0};
    }
};

constexpr double PI = 3.14159265358979323846;
constexpr double TWO_PI = 2.0 * PI;

inline double degreesToRadians(double degrees) {
    return degrees * PI / 180.0;
}

inline double radiansToDegrees(double radians) {
    return radians * 180.0 / PI;
}

} // namespace voyage::core
