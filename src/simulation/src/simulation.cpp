#include <voyage/simulation/simulation.hpp>

namespace voyage::sim {

Simulation::Simulation()
    : m_timeSystem(std::make_unique<TimeSystem>())
    , m_world(std::make_unique<ecs::World>()) {}

Simulation::~Simulation() = default;

void Simulation::initialize() {
    registerSystems();
}

void Simulation::update(double realDeltaSeconds) {
    m_timeSystem->update(realDeltaSeconds);
}

void Simulation::shutdown() {
    // TODO: cleanup resources
}

TimeSystem& Simulation::time() {
    return *m_timeSystem;
}

const TimeSystem& Simulation::time() const {
    return *m_timeSystem;
}

ecs::World& Simulation::world() {
    return *m_world;
}

const ecs::World& Simulation::world() const {
    return *m_world;
}

void Simulation::registerSystems() {
    // TODO: register game systems (OrbitalSystem, ResourceSystem, etc.)
}

} // namespace voyage::sim
