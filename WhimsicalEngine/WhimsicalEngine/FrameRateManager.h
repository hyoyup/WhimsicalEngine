// FrameRateManager.h

// Description:
//	frame rate controller

#pragma once
#ifndef WE_FRAME_RATE_MANAGER_H
#define WE_FRAME_RATE_MANAGER_H

typedef std::chrono::high_resolution_clock					Clock;
typedef std::chrono::high_resolution_clock::time_point		TimePoint;
typedef std::chrono::milliseconds							Millisecond; // 
typedef std::chrono::microseconds							Microsecond;
typedef std::chrono::duration<float>						FloatSecond;
typedef std::chrono::seconds								Seconds;

class WEFrameRateManager
{
private:
	unsigned int m_maxFrameRate;
	float m_ticksPerFrame;
	TimePoint m_tickStart, m_tickEnd;
	float m_frameTime;
	float m_totalElapsedTime;
	float m_secondCounter;

public:
	WEFrameRateManager(unsigned int maxFrameRate = 60);
	~WEFrameRateManager();
	WEFrameRateManager(const WEFrameRateManager &) = delete;
	void operator=(const WEFrameRateManager &) = delete;
	void SetMaxFrameRate(unsigned int maxFrameRate = 60);
	void FrameStart();
	void FrameEnd();
	void ResetElapsedTime();
	float GetMaxFrameRate();
	float GetElapsedTime(); // total elapsed time from level start in seconds
	float GetFrameTime(); // in seconds
};


using std_clock = std::chrono::steady_clock;
using std_seconds = std::chrono::seconds;

class StopWatch
{

public:

	StopWatch();
	StopWatch(const StopWatch&);
	StopWatch& operator=(const StopWatch& rhs);
	~StopWatch() = default;

	// Return the elapsed microseconds since start
	inline uint64           ElapsedInUs() const;

	// Return the elapsed milliseconds since start
	inline uint64           ElapsedInMs() const;

	// Return the elapsed seconds since start
	inline uint64           ElapsedInSec() const;

	Clock::time_point   Reset();

private:
	Clock::time_point   m_Start;

};

//////////////////////////////////////////////////////////////////////////

inline uint64 StopWatch::ElapsedInUs() const
{
	return std::chrono::duration_cast<Microsecond>(std_clock::now() - m_Start).count();
}
// Return the elapsed milliseconds since start
inline uint64 StopWatch::ElapsedInMs() const
{
	return std::chrono::duration_cast<Millisecond>(std_clock::now() - m_Start).count();
}
// Return the elapsed seconds since start
inline uint64 StopWatch::ElapsedInSec() const
{
	return std::chrono::duration_cast<std_seconds>(std_clock::now() - m_Start).count();
}


#endif