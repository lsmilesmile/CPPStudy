/*
 * @Description: 
 * @Author: liuxiao
 * @Date: 2022-04-13 16:23:32
 */

#include <iostream>

struct TestStruct
{
    /* data */
    TestStruct() : name(__func__){}
    const char* name;
};

int main() {
    TestStruct ts;
    std::cout << ts.name << std::endl;
}

