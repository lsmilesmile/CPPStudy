/*
 * @Description: 
 * @Author: liuxiao
 * @Date: 2022-04-22 21:58:40
 */

#ifndef __LOG_H_
#define __LOG_H_

enum LOG_LEVEL {
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_DEBUG
};

enum LOG_TARGET {
    TARGET_FILE,
    TARGET_CONSOLE
};

#define LOG_INFO(...)     Log::genLogString(LOG_LEVEL_INFO, __FILE__, __FUNCTION__,__LINE__, __VA_ARGS__)
#define LOG_WARNING(...)  Log::genLogString(LOG_LEVEL_WARNING, __FILE__, __FUNCTION__, __LINE__,__VA_ARGS__)
#define LOG_ERROR(...)    Log::genLogString(LOG_LEVEL_ERROR, __FILE__, __FUNCTION__,__LINE__, __VA_ARGS__)
#define LOG_DEBUG(...)    Log::genLogString(LOG_LEVEL_DEBUG, __FILE__, __FUNCTION__,__LINE__, __VA_ARGS__)


class Log {
public:
   
    static void init(LOG_TARGET lt);
    static void unInit();
    static void genLogString(LOG_LEVEL level, const char* fileName, const char* funcName, int lineNo, const char* fmt, ...);


private:
    static LOG_LEVEL m_logLevel;
    static LOG_TARGET m_logTarget;
    static std::ofstream fLog;

private:
    Log() = delete;
    ~Log() = delete;
    Log(const Log& rhs) = delete;
    Log& operator=(const Log& rhs) = delete;

    static inline void setLogLevel(LOG_LEVEL level);
    static inline void getTime(char* timeString, int timeStringLength, bool isUsedToGenFile = false);
    static void createLogDirAndFile();
    static void outputToTarget(const std::string& strLogInfo);
    

};

#endif