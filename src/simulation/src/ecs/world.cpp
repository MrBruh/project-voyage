#include <voyage/simulation/ecs/world.hpp>

namespace voyage::sim::ecs {

World::World() = default;
World::~World() = default;

core::EntityId World::createEntity() {
    return m_entities.create();
}

void World::destroyEntity(core::EntityId id) {
    m_components.removeAll(id);
    m_entities.destroy(id);
}

bool World::isValidEntity(core::EntityId id) const {
    return m_entities.isValid(id);
}

void World::update(double deltaTime) {
    for (auto& system : m_systems) {
        system->update(*this, deltaTime);
    }
}

core::EntityId EntityManager::create() {
    core::EntityId id;
    if (!m_freeList.empty()) {
        id = m_freeList.back();
        m_freeList.pop_back();
    } else {
        id = m_nextId++;
    }
    m_activeEntities.insert(id);
    return id;
}

void EntityManager::destroy(core::EntityId id) {
    if (m_activeEntities.erase(id) > 0) {
        m_freeList.push_back(id);
    }
}

bool EntityManager::isValid(core::EntityId id) const {
    return m_activeEntities.find(id) != m_activeEntities.end();
}

std::size_t EntityManager::count() const {
    return m_activeEntities.size();
}

void ComponentRegistry::removeAll(core::EntityId entity) {
    for (auto& [typeId, entityMap] : m_components) {
        entityMap.erase(entity);
    }
}

} // namespace voyage::sim::ecs
