#include <voyage/simulation/time_system.hpp>

namespace voyage::sim {

TimeSystem::TimeSystem() = default;

void TimeSystem::setTickLength(core::GameDuration length) {
    m_tickLength = length;
}

core::GameDuration TimeSystem::getTickLength() const {
    return m_tickLength;
}

void TimeSystem::start() {
    m_state = TimeState::Running;
    m_stopRequested = false;
}

void TimeSystem::pause() {
    m_state = TimeState::Paused;
}

void TimeSystem::requestStop() {
    m_stopRequested = true;
    m_state = TimeState::StopRequested;
}

TimeState TimeSystem::getState() const {
    return m_state;
}

core::Ticks TimeSystem::getCurrentTick() const {
    return m_currentTick;
}

int TimeSystem::getCurrentSubdivision() const {
    return m_currentSubdivision;
}

void TimeSystem::update(double realDeltaSeconds) {
    if (m_state != TimeState::Running) {
        return;
    }

    m_accumulatedTime += realDeltaSeconds;

    while (m_accumulatedTime >= REAL_SECONDS_PER_SUBDIVISION) {
        if (m_stopRequested) {
            m_state = TimeState::Paused;
            m_stopRequested = false;
            m_accumulatedTime = 0.0;
            return;
        }

        m_accumulatedTime -= REAL_SECONDS_PER_SUBDIVISION;

        for (const auto& callback : m_subdivisionCallbacks) {
            callback(m_currentTick, m_currentSubdivision);
        }

        m_currentSubdivision++;
        if (m_currentSubdivision >= SUBDIVISIONS_PER_TICK) {
            for (const auto& callback : m_tickCompleteCallbacks) {
                callback(m_currentTick, m_currentSubdivision);
            }
            m_currentTick++;
            m_currentSubdivision = 0;
        }
    }
}

void TimeSystem::onSubdivision(TickCallback callback) {
    m_subdivisionCallbacks.push_back(std::move(callback));
}

void TimeSystem::onTickComplete(TickCallback callback) {
    m_tickCompleteCallbacks.push_back(std::move(callback));
}

} // namespace voyage::sim
