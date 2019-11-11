// FrameRateManager.h

// Description:
//	frame rate controller

#pragma once
#ifndef FRAME_RATE_MANAGER_H
#define FRAME_RATE_MANAGER_H

typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::steady_clock::time_point TimePoint;
typedef std::chrono::milliseconds Millisecond;
typedef std::chrono::duration<float> FloatSecond;

class FrameRateManager
{
private:
	unsigned int m_maxFrameRate;
	float m_ticksPerFrame;
	TimePoint m_tickStart, m_tickEnd;
	float m_frameTime;
	float m_totalElapsedTime;
	float m_secondCounter;

public:
	FrameRateManager(unsigned int maxFrameRate = 60);
	~FrameRateManager();
	FrameRateManager(const FrameRateManager &) = delete;
	void operator=(const FrameRateManager &) = delete;
	void SetMaxFrameRate(unsigned int maxFrameRate = 60);
	void FrameStart();
	void FrameEnd();
	void ResetElapsedTime();
	float GetMaxFrameRate();
	float GetElapsedTime(); // total elapsed time from level start in seconds
	float GetFrameTime(); // in seconds
};

#endif