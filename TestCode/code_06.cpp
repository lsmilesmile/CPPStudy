#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdarg>


int Test_vscprintf(char* szBuffer, int iCount, const char* szFormat, ...) {
    int iReturn = 0;
    va_list pArgs;
    va_start(pArgs, szFormat);
    // 格式化字符串
    iReturn = _vscprintf(szFormat, pArgs) + 1;
    std::cout << iReturn << std::endl;
    iReturn = vsprintf(szBuffer, iReturn, szFormat, pArgs);
    va_end(pArgs);
    return iReturn;
    
}

int main() {
    char strDataV[30] = {0};
    int k = sizeof(strDataV) / sizeof(char);
    int a = Test_vscprintf(strDataV, k, "This is a test:%s, %s", "param1", "param2");
    std::cout << strDataV << std::endl;

    
    return 0;
}