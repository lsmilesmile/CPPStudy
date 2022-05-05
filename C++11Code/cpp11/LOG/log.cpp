/*
 * @Description: 
 * @Author: liuxiao
 * @Date: 2022-04-22 21:58:49
 */

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <direct.h>
#include <fstream>
#include <cstdarg>
#include <string>
#include "log.h"

LOG_LEVEL Log::m_logLevel = LOG_LEVEL_INFO;
LOG_TARGET Log::m_logTarget = TARGET_FILE;
std::ofstream Log::fLog;

inline void Log::getTime(char* timeString, int timeStringLength, bool isUsedToGenFile) {
    SYSTEMTIME st;
    GetLocalTime( &st );
    if (!isUsedToGenFile)
        sprintf_s(timeString, timeStringLength, \
                "[%04d-%02d-%02d %02d:%02d:%02d:%04d]", \
                st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute, st.wSecond,st.wMilliseconds);
    else
        sprintf_s(timeString, timeStringLength, \
                "%4d-%02d-%02d_%02d-%02d-%02d.log", \
                st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute, st.wSecond);
}

inline void Log::setLogLevel(LOG_LEVEL level) {
    m_logLevel = level;
}

void Log::createLogDirAndFile() {
    // 获得当前文件路径
    // TCHAR fileDirectory[256];
    // GetCurrentDirectory(256, fileDirectory);

    // 拼接路径字符串
    // TCHAR logFileDirectory[256];
    // TCHAR logFolder[10] = ".\\Logs\\";
    // _stprintf_s(logFileDirectory, logFolder, fileDirectory);

    // 文件夹不存在则常见文件夹
    const TCHAR logFolder[10] = TEXT(".\\Logs\\");
    if (_taccess(logFolder, 0) == -1)
	{
        // success:0 fail:-1
		int ret = _tmkdir(logFolder); // 不能递归创建 
	}

    if (m_logTarget == TARGET_FILE) {
        char fileName[64];
        getTime(fileName, ARRAYSIZE(fileName), true);
        char logFolderPath[100] = ".\\Logs\\";
        strcat(logFolderPath, fileName);
        fLog.open(logFolderPath, std::ios_base::out | std::ios_base::app);  
        if (!fLog.is_open())
            return;
    }
}

void Log::init(LOG_TARGET lt) {
    m_logTarget = lt;
    createLogDirAndFile();
}

void Log::genLogString(LOG_LEVEL level, const char* fileName, const char* funcName, int lineNo, const char* fmt, ...){
    //时间
    char szTime[64] = { 0 };
    getTime(szTime, ARRAYSIZE(szTime));
    std::string logInfo(szTime);

    std::string strLevel = "[INFO]";
    switch (level)
    {
    case LOG_LEVEL_DEBUG:
        strLevel = "[DEBUG]";
        break;
    case LOG_LEVEL_INFO:
        strLevel = "[INFO]";
        break;
    case LOG_LEVEL_WARNING:
        strLevel = "[WARNING]";
        break;
    case LOG_LEVEL_ERROR:
        strLevel = "[ERROR]";
        break;
    default:
        break;
    }
    logInfo += strLevel;

    char szThreadID[32] = {0};
    DWORD dwThreadID = ::GetCurrentThreadId();
    sprintf_s(szThreadID, ARRAYSIZE(szThreadID), "[ThreadID: %u]", dwThreadID);
    logInfo += szThreadID;

    char szFuncSig[512] = { 0 };
    sprintf_s(szFuncSig, "[%s:%s:%d]", fileName, funcName, lineNo);
    logInfo += szFuncSig;

    std::string strLogMsg;
    va_list ap;
    va_start(ap, fmt);
    int nLogMsgLength = _vscprintf(fmt, ap);
    //容量必须算上最后一个\0
    if ((int)strLogMsg.capacity() < nLogMsgLength + 1)
    {
        strLogMsg.resize(nLogMsgLength + 1);
    }
    vsprintf_s((char*)strLogMsg.data(), strLogMsg.capacity(), fmt, ap);
    va_end(ap);

    //string内容正确但length不对，恢复一下其length
    std::string strMsgFormal;
    strMsgFormal.append(strLogMsg.c_str(), nLogMsgLength);

    logInfo += strMsgFormal;
    logInfo += "\n";

    outputToTarget(logInfo);
}

void Log::outputToTarget(const std::string& strLogInfo) {
    if (m_logTarget == TARGET_FILE) {
        fLog << strLogInfo;
    }else {
        std::cout << strLogInfo;
    }
}

void Log::unInit() {
    fLog.close();
    fLog.clear();
}


