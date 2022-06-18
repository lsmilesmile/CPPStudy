# char\*和wchar\*

> Felix
>
> 2022.6.18



###### 问题描述

编写程序时通常会面对一些不同的编码格式，如Unicode和multibytes。在有关字符串的处理时尤其重要，系统编程时通常会遇到很多这样的问题，例如把wchar*的字符串转换为char*的字符串，有时还需要把char*类型的字符串转换为wchar*类型。下面提供几种解决方案。



解决方案

###### wchar* 转到 char*

方法一，使用_bstr_t转换。 

```c++
#include <comdef.h> // you will need this
const WCHAR* wc = L"Hello World" ;
_bstr_t b(wc);
const char* c = b;
printf("Output: %s\n", c);
```



方法二，使用conversion macros。 
包含在头文件#include <atlconv.h>中，使用需谨慎！因为转换字符串分配的空间在栈上，直到函数返回才释放。如归使用很多次，例如在递归函数里使用，容易造成内存溢出。

```c++
USES_CONVERSION;
WCHAR* wc = L"Hello World" ;
char* c = W2A(wc);
```



方法三，使用sprintf，比较简洁。 　　

```c++
char output[256];
WCHAR* wc = L"Hellow World" ;
sprintf(output, "%ws", wc );
```





###### char*转 wchar*

方法一：使用mbstowcs函数。 

```c++
const wchar_t *GetWC(const char *c)
{
const size_t cSize = strlen(c)+1;
wchar_t* wc = new wchar_t[cSize];
mbstowcs (wc, c, cSize);

return wc;
}
```

方法二：使用USES_CONVERSION。 
用法及注意事项同上。 

```c++
USES_CONVERSION;
char* c = L"Hello World" ;
Wchar* wc = A2W(c);
```

方法三：使用swprintf函数，推荐使用。 

```c++
wchar_t ws[100];
swprintf(ws, 100, L"%hs", "ansi string");
```



