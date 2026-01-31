#pragma once
#include <voyage/core/types.hpp>
#include <unordered_set>
#include <vector>

namespace voyage::sim::ecs {

class EntityManager {
public:
    core::EntityId create();
    void destroy(core::EntityId id);
    bool isValid(core::EntityId id) const;
    std::size_t count() const;

private:
    core::EntityId m_nextId{1};
    std::unordered_set<core::EntityId> m_activeEntities;
    std::vector<core::EntityId> m_freeList;
};

} // namespace voyage::sim::ecs
