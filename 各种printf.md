# 各种printf

> Felix
>
> 2022.6.18



###### printf

```c++
int printf(const char* szFormat, ...);
```

第一个参数是一个格式化字符串，后面是与格式化字符串中的代码相对应的不同类型多个参数。

```c++
#include <iostream>
#include <cstdio>
#include <cstring>

int main() {
    std::string str = "This is a test:%s\n";
    printf(str.c_str(), "printf");
    printf("\n");
    return 0;
}
```



###### sprintf

```c++
int sprintf(char* szBuffer, const char* szFormat, ...);
```

szBuffer - 字符串缓冲区

szFormat - 格式字符串

sprintf不是将格式化结果标准输出，而是将其存入szBuffer。该函数返回该字符串的长度。

```c++
#include <iostream>
#include <cstdio>
#include <cstring>

int main() {
    char strData[25] = {0};
    int i = sprintf(strData, "This is test:%s\n", "sprintf");
    std::cout << i << ", " << strData << std::endl;
    return 0;
}
```



###### _snprintf

当格式化字符串与被格式化的变数不合时，可能使printf 执行错误并可能造成程序当掉。使用sprintf 时，您不但要担心这些，而且还有一个新的负担：您定义的字符串缓冲区必须足够大以存放结果。Microsoft 专用函数_snprintf 解决了这一问题，此函数引进了另一个参数，表示以字节计算的缓冲区大小。

```c++
#include <iostream>
#include <cstdio>
#include <cstring>

int main() {
    char strDataS[30] = {0};
    int k = sizeof(strDataS) / sizeof(char);
    std::cout << k << std::endl;
    _snprintf(strDataS, k, "This is a test:%s\n", "_snprintf_s");
    std::cout << strDataS << std::endl;
    memset(strDataS, 0, sizeof(strDataS));
    _snprintf(strDataS, k-10, "This is a test:%s\n", "_snprintf_s");
    
    return 0;
}
```



###### vsprintf

```c++
int vsprintf(char* string, char* format, va_list param);
```

vsprintf 是sprintf 的一个变形，它只有三个参数。vsprintf 用于执行有不定数量参数的函数，类似printf 格式。vsprintf的前两个参数与sprintf相同：一个用于保存结果的字符串缓冲区和一个格式化字符串。第三个参数是指向格式化参数队列的指针。实际上，该指针指向在堆栈中供函数调用的变量。va_list、va_start和va_end宏（在STDARG.H中定义）帮助我们处理堆栈指针。va_start宏将pArg设置为指向一个堆栈变量，该变量位址在堆栈参数szFormat的上面。

```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdarg>


int Testvsprintf(char* szBuffer, int iCount, const char* szFormat, ...) {
    int iReturn = 0;
    va_list pArgs;
    va_start(pArgs, szFormat);
    // 格式化字符串
    iReturn = vsprintf(szBuffer, szFormat, pArgs);
    va_end(pArgs);
    return iReturn;
    
}

int main() {
    char strDataV[30] = {0};
    int k = sizeof(strDataV) / sizeof(char);
    int a = Testvsprintf(strDataV, k, "This is a test:%s, %s", "param1", "param2");
    std::cout << strDataV << std::endl;

    
    return 0;
}
```



在寻找第三方日志库的过程中，格式化字符串需要计算当前格式化字符串的长度，如果长度不够可能越界发生崩溃，接下来这个函数能帮我们获取格式化字符串长度；

###### _vscprintf

```c++
int _vscprintf(const char* format, va_list argptr);
```

返回格式化列表字符字节数。