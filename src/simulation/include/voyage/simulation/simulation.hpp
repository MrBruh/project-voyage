#pragma once
#include <voyage/simulation/ecs/world.hpp>
#include <voyage/simulation/time_system.hpp>
#include <memory>

namespace voyage::sim {

class Simulation {
public:
    Simulation();
    ~Simulation();

    void initialize();
    void update(double realDeltaSeconds);
    void shutdown();

    TimeSystem& time();
    const TimeSystem& time() const;

    ecs::World& world();
    const ecs::World& world() const;

private:
    std::unique_ptr<TimeSystem> m_timeSystem;
    std::unique_ptr<ecs::World> m_world;

    void registerSystems();
};

} // namespace voyage::sim
