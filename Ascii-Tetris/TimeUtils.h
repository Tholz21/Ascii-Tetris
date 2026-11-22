#define TIMEUTILS_H
#include <chrono>

using namespace std::chrono;

class TimeUtils {
private:
	// Frames per second (target)
	static const int targetFPS = 60;
	static const int targetFrameTime = 1000 / targetFPS; // in milliseconds
	static auto getElapsedTime(steady_clock::time_point startTime, steady_clock::time_point endTime);

public:
	static void enforceFrameRate(steady_clock::time_point startTime, steady_clock::time_point endTime);

};