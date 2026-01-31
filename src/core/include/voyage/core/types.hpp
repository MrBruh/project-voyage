#pragma once
#include <cstdint>

namespace voyage::core {

using EntityId = std::uint64_t;
constexpr EntityId NULL_ENTITY = 0;

using ResourceId = std::uint32_t;
using SystemId = std::uint32_t;

using Ticks = std::int64_t;
using Subdivisions = std::int32_t;

struct GameDuration {
    Ticks ticks{0};
    Subdivisions subdivisions{0};
};

} // namespace voyage::core
