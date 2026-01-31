#pragma once
#include <voyage/core/types.hpp>
#include <typeindex>
#include <any>
#include <unordered_map>

namespace voyage::sim::ecs {

using ComponentTypeId = std::type_index;

class ComponentRegistry {
public:
    template<typename T>
    void add(core::EntityId entity, T component) {
        auto typeId = std::type_index(typeid(T));
        m_components[typeId][entity] = std::move(component);
    }

    template<typename T>
    void remove(core::EntityId entity) {
        auto typeId = std::type_index(typeid(T));
        auto it = m_components.find(typeId);
        if (it != m_components.end()) {
            it->second.erase(entity);
        }
    }

    template<typename T>
    T* get(core::EntityId entity) {
        auto typeId = std::type_index(typeid(T));
        auto typeIt = m_components.find(typeId);
        if (typeIt == m_components.end()) {
            return nullptr;
        }
        auto entityIt = typeIt->second.find(entity);
        if (entityIt == typeIt->second.end()) {
            return nullptr;
        }
        return std::any_cast<T>(&entityIt->second);
    }

    template<typename T>
    const T* get(core::EntityId entity) const {
        auto typeId = std::type_index(typeid(T));
        auto typeIt = m_components.find(typeId);
        if (typeIt == m_components.end()) {
            return nullptr;
        }
        auto entityIt = typeIt->second.find(entity);
        if (entityIt == typeIt->second.end()) {
            return nullptr;
        }
        return std::any_cast<T>(&entityIt->second);
    }

    template<typename T>
    bool has(core::EntityId entity) const {
        return get<T>(entity) != nullptr;
    }

    void removeAll(core::EntityId entity);

private:
    std::unordered_map<ComponentTypeId, std::unordered_map<core::EntityId, std::any>> m_components;
};

} // namespace voyage::sim::ecs
