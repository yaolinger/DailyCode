#ifndef UTILS_TIME_HELPER_HPP
#define UTILS_TIME_HELPER_HPP

#include <string>
#include "time_base.hpp"

/* 单调计时器
 * c++11 std::chrono::steady_clock
 * 基础时间点 steady_clock::time_point
 */

class StopWatch {
public:
    StopWatch() : m_start(now()) {}

    ~StopWatch() {}

    // 重置计时器
    void reset() {
        m_start = now();
    }


public:
    // 获取经过时长(us)
    int32_t durationUs() {
        return std::chrono::duration_cast<microseconds>(now() - m_start).count();
    }

    // 获取经过时长(ms)
    int32_t durationMs() {
        return std::chrono::duration_cast<milliseconds>(now() - m_start).count();
    }

    // 获取经过时长(s)
    int32_t durationS() {
        return std::chrono::duration_cast<seconds>(now() - m_start).count();
    }

private:
    // 获取当前时间点
    static steadyClock::time_point now() {
        return steadyClock::now();
    }

private:
    steadyClock::time_point m_start;
};

// 常规时间函数
class TimeHelper {
public:
    // 初始化
    static void init(int32_t now = 0);

    // 获取当前时间(s)
    static int32_t getCurrentSecond();

    // 获取当前时间(ms)
    static int64_t getCurrentMilliseconds();

    // 获取系统时间(s)
    static int32_t getSystemCurrentSecond();

    // 获取系统时间(ms)
    static int64_t getSystemCurrentMillisecond();

    // 获取时间字符串
    static std::string getTimeStr(int32_t ts);

    // 获取当前时间字符串
    static std::string getNowTimeStr();

private:
    static int32_t m_initTime;  // 初始时间
    static steadyClock::time_point m_start;  // 开始时间点
};

#endif
