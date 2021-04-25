#ifndef UTILS_LOG_HPP
#define UTILS_LOG_HPP

#include <iostream>

//关闭所有属性:0m 黑:30m 红:31m 绿:32m 黄:33m 蓝:34m 紫:35m 深绿:36m 白:37m
#define OUTPUT_NULL_COLOUR "\033[0m"
#define OUTPUT_TRACE_COLOUR "\033[32m"
#define OUTPUT_DEBUG_COLOUR "\033[37m"
#define OUTPUT_INFO_COLOUR  "\033[33m"
#define OUTPUT_WARN_COLOUR  "\033[35m"
#define OUTPUT_ERROR_COLOUR "\033[31m"

//日志长度
#define LOG_MAX_LEN 1024000

// 日志等级
enum LogLevel {
    LOG_LEVEL_TRACE = 0,
	LOG_LEVEL_DEBUG = 1,
	LOG_LEVEL_INFO = 2,
	LOG_LEVEL_WARN = 3,
	LOG_LEVEL_ERROR = 4,
};

// 控制条件
enum LogControl {
	// 输出方式
	LOG_CONTROL_TO_CONSOLE = 0,
	LOG_CONTROL_TO_FILE = 1,

	// 输出等级
	LOG_CONTROL_TRACE = 2,
	LOG_CONTROL_DEBUG = 4,
	LOG_CONTROL_INFO = 8,
	LOG_CONTROL_WARN = 16,
	LOG_CONTROL_ERROR = 32,

};

// 日志对象
class Logger {
public:
	static void init();

	static void setControl(int32_t control);

	static void unsetControl(int32_t control);

	static void output(LogLevel level, const char* file, int32_t line, const char * func, const char* format, ...);

private:
	static bool isOutputLevel(LogLevel level);

private:
	static int32_t m_logControl;
};

// 个人抉择 用哪个函数宏
//  __PRETTY_FUNCTION__ 返回参数 函数名(参数列表)
//  __FUNCTION__ 函数名

#define log_trace(format, ...) Logger::output(LOG_LEVEL_TRACE, __FILE__, __LINE__, __FUNCTION__, format, ##__VA_ARGS__)
#define log_debug(format, ...) Logger::output(LOG_LEVEL_DEBUG, __FILE__, __LINE__, __FUNCTION__, format, ##__VA_ARGS__)
#define log_info(format, ...) Logger::output(LOG_LEVEL_INFO, __FILE__, __LINE__, __FUNCTION__, format, ##__VA_ARGS__)
#define log_warn(format, ...) Logger::output(LOG_LEVEL_WARN, __FILE__, __LINE__, __FUNCTION__, format, ##__VA_ARGS__)
#define log_error(format, ...) Logger::output(LOG_LEVEL_ERROR, __FILE__, __LINE__, __FUNCTION__, format, ##__VA_ARGS__)

#define CHECK_ERROR_LOG(error, format, ...) \
    if (error) \
        log_error(format, ##__VA_ARGS__);

#endif
