#include "time_helper.hpp"

#include <ctime>
#include <iomanip>
#include <sstream>

int32_t TimeHelper::m_initTime;

steadyClock::time_point TimeHelper::m_start;

void TimeHelper::init(int now) {
	m_start = steadyClock::now();
	m_initTime = now == 0 ? getSystemCurrentSecond(): now;
}

int32_t TimeHelper::getCurrentSecond() {
	return std::chrono::duration_cast<seconds>(steadyClock::now() - m_start).count() + m_initTime;
}

int64_t TimeHelper::getCurrentMilliseconds() {
	return std::chrono::duration_cast<milliseconds>(steadyClock::now() - m_start).count() + int64_t(m_initTime) * 1000;
}

//获取当前系统时间
//typedef int32_t/int64_t time_t
//time_t time(arg) or time_t to_time_t()
int32_t TimeHelper::getSystemCurrentSecond() {
	//return (int32_t)time(nullptr);
	//return (int32_t)systemClock::to_time_t(systemClock::now());
    std::chrono::system_clock::time_point start; // 初始时间,默认值为 1970-01-01 08:00:00
    return std::chrono::duration_cast<seconds>(systemClock::now() - start).count();
}

int64_t TimeHelper::getSystemCurrentMillisecond() {
    std::chrono::system_clock::time_point start; // 初始时间,默认值为 1970-01-01 08:00:00
    return (int64_t)std::chrono::duration_cast<milliseconds>(systemClock::now() - start).count();
}

std::string TimeHelper::getTimeStr(int32_t ts) {
	std::time_t t = ts;
	std::stringstream os;
	os << std::put_time(std::localtime(&t), "%Y/%m/%d %T");
	return os.str();
}

std::string TimeHelper::getNowTimeStr() {
    return getTimeStr(getCurrentSecond());
}

