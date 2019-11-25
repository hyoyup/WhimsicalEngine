// FrameRateManager.cpp

#include "pch.h"
#include "FrameRateManager.h"

#define MIN_FRAME_TIME 0.016667f

WEFrameRateManager::WEFrameRateManager(unsigned int maxFrameRate) :
	m_secondCounter(0.f),
	m_frameTime(0.0166667f)
{
	if (maxFrameRate == 0) {
		m_maxFrameRate = UINT16_MAX;
	}
	else { m_maxFrameRate = maxFrameRate;  }
	m_ticksPerFrame = 1.0f / (float)m_maxFrameRate;
	//m_frameTime = MIN_FRAME_TIME;
	m_totalElapsedTime = 0.0f;
}

WEFrameRateManager::~WEFrameRateManager() {}

void WEFrameRateManager::SetMaxFrameRate(unsigned int maxFrameRate)
{
	if (maxFrameRate == 0) {
		m_maxFrameRate = UINT16_MAX;
	}
	else { m_maxFrameRate = maxFrameRate; }
	m_ticksPerFrame = 1.0f / (float)m_maxFrameRate;
}

void WEFrameRateManager::FrameStart() {
	m_tickStart = Clock::now();
}

void WEFrameRateManager::FrameEnd() {
	m_tickEnd = Clock::now();
	Millisecond duration = std::chrono::duration_cast<Millisecond>(m_tickEnd - m_tickStart);
	while (duration.count() < m_ticksPerFrame) {
		duration = std::chrono::duration_cast<Millisecond>(m_tickEnd - m_tickStart);
		m_tickEnd = Clock::now();
	}

	//if (TETRA_GAME_STATE.IsDebugPause()) {
	//	m_frameTime = GetMaxFrameRate();
	//	m_totalElapsedTime += m_frameTime;
	//}
	//else {
	//	auto dur = m_tickEnd - m_tickStart;
	//	FloatSecond fsec = std::chrono::duration_cast<FloatSecond>(dur);
	//	m_frameTime = float(fsec.count()); //  / 1000.0f;
	//	m_totalElapsedTime += m_frameTime;

	//	m_secondCounter += m_frameTime;
	//	float fps = 1.0f / m_frameTime;
	//	if (fps < 40.0f) {
	//		//std::cout << "FPS dropped to: " << fps << std::endl;
	//	}
	//}

	//if (m_secondCounter >= 0.1f) {
	//	TETRA_EVENTS.BroadcastEventToSubscribers(&Event(EventType::EVENT_FPS_UPDATE, &FloatData(1/m_frameTime)));
	//	m_secondCounter = 0.f;
	//}
}

void WEFrameRateManager::ResetElapsedTime() {
	m_totalElapsedTime = 0.0f;
}

float WEFrameRateManager::GetElapsedTime() {
	return m_totalElapsedTime;
}

float WEFrameRateManager::GetFrameTime() {
	return m_frameTime;
}

float WEFrameRateManager::GetMaxFrameRate() {
	return MIN_FRAME_TIME;
}


StopWatch::StopWatch() :
	m_Start(Clock::now())
{
	static_assert(std::chrono::high_resolution_clock::is_steady, "Serious OS/C++ library issues. Steady clock is not steady");
}

StopWatch::StopWatch(const StopWatch& rhs) :
	m_Start(rhs.m_Start)
{}

StopWatch& StopWatch::operator=(const StopWatch& rhs)
{
	m_Start = rhs.m_Start;
	return *this;
}

// Resets stop watch to start point
Clock::time_point StopWatch::Reset()
{
	m_Start = std_clock::now();
	return m_Start;
}
