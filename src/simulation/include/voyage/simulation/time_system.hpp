#pragma once
#include <voyage/core/types.hpp>
#include <functional>
#include <vector>
#include <atomic>

namespace voyage::sim {

constexpr int SUBDIVISIONS_PER_TICK = 5;
constexpr double REAL_SECONDS_PER_TICK = 5.0;
constexpr double REAL_SECONDS_PER_SUBDIVISION = REAL_SECONDS_PER_TICK / SUBDIVISIONS_PER_TICK;

enum class TimeState {
    Paused,
    Running,
    StopRequested
};

class TimeSystem {
public:
    using TickCallback = std::function<void(core::Ticks currentTick, int subdivision)>;

    TimeSystem();

    void setTickLength(core::GameDuration length);
    core::GameDuration getTickLength() const;

    void start();
    void pause();
    void requestStop();

    TimeState getState() const;
    core::Ticks getCurrentTick() const;
    int getCurrentSubdivision() const;

    void update(double realDeltaSeconds);

    void onSubdivision(TickCallback callback);
    void onTickComplete(TickCallback callback);

private:
    TimeState m_state{TimeState::Paused};
    std::atomic<bool> m_stopRequested{false};
    core::Ticks m_currentTick{0};
    int m_currentSubdivision{0};
    double m_accumulatedTime{0.0};
    core::GameDuration m_tickLength{};

    std::vector<TickCallback> m_subdivisionCallbacks;
    std::vector<TickCallback> m_tickCompleteCallbacks;
};

} // namespace voyage::sim
