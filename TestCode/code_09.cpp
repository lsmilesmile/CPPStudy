#include <iostream>
#include <cstring>

// 函数返回char*
char* rs() {
    std::string s = "hello";
    static char sc[20];
    strcpy(sc, s.c_str());
    return sc;
}

int main() {
    const char* re  = rs();
    std::cout << re << std::endl;
    return 0;
}