#pragma once
#include <voyage/simulation/ecs/entity.hpp>
#include <voyage/simulation/ecs/component.hpp>
#include <voyage/simulation/ecs/system.hpp>
import <memory>;
import <vector>;

namespace voyage::sim::ecs {

class World {
public:
    World();
    ~World();

    core::EntityId createEntity();
    void destroyEntity(core::EntityId id);
    bool isValidEntity(core::EntityId id) const;

    template<typename T>
    void addComponent(core::EntityId entity, T component) {
        m_components.add(entity, std::move(component));
    }

    template<typename T>
    T* getComponent(core::EntityId entity) {
        return m_components.get<T>(entity);
    }

    template<typename T>
    const T* getComponent(core::EntityId entity) const {
        return m_components.get<T>(entity);
    }

    template<typename T>
    bool hasComponent(core::EntityId entity) const {
        return m_components.has<T>(entity);
    }

    template<typename T, typename... Args>
    T& addSystem(Args&&... args) {
        auto system = std::make_unique<T>(std::forward<Args>(args)...);
        T& ref = *system;
        m_systems.push_back(std::move(system));
        return ref;
    }

    void update(double deltaTime);

private:
    EntityManager m_entities;
    ComponentRegistry m_components;
    std::vector<std::unique_ptr<System>> m_systems;
};

} // namespace voyage::sim::ecs
