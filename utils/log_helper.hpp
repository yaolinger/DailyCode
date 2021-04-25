#ifndef UTILS_LOG_HELPER_HPP
#define UTILS_LOG_HELPER_HPP

#include <string>

#include "time_helper.hpp"

// 函数执行日志
struct FuncTrace {
	FuncTrace(const char* file, const char* func, int32_t line)
		: m_file(file), m_func(func), m_line(line) {
		Logger::output(LOG_LEVEL_TRACE, m_file.c_str(), m_line, m_func.c_str(), "~~~~~~~~~~~~[%s] start run ~~~~~~~~~~~~~~~~~~~", m_func.c_str());
	}
	~FuncTrace() {
		Logger::output(LOG_LEVEL_TRACE, m_file.c_str(), m_line, m_func.c_str(), "~~~~~~~~~~~~[%s] end, run[%d(us)]~~~~~~~~~~~~", m_func.c_str(), sw.durationUs());
	}

	StopWatch sw;
	std::string m_file;
	std::string m_func;
	int32_t m_line;
};

#define FUNC_TRACE \
		FuncTrace ft(__FILE__, __FUNCTION__, __LINE__);

#endif
