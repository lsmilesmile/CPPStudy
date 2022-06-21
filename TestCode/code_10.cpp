#include <iostream>
#include <cstring>


int main() {
    char s[10] = "hello";
    memset(s, '\0', sizeof(s));
    return 0;
}