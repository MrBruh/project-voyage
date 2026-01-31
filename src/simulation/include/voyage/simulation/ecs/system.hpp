#pragma once

namespace voyage::sim::ecs {

class World;

class System {
public:
    virtual ~System() = default;
    virtual void update(World& world, double deltaTime) = 0;
    virtual int priority() const { return 0; }
};

} // namespace voyage::sim::ecs
