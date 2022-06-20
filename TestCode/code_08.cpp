/// char* 和wchar* 转换

#include <iostream>
#include <comdef.h>
#include <cstdio>

int main() {
    WCHAR * wc = L"Hello World";
    _bstr_t b(wc);
    char* c = b;
    printf("%s\n", c);
    return 0;
}

