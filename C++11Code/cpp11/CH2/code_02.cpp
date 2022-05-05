/*
 * @Description: 
 * @Author: liuxiao
 * @Date: 2022-04-13 16:20:21
 */


#include <iostream>
#include <string>

const char* hello() {return __func__;}
const char* world() {return __func__;}

int main() {
    std::cout << hello() << ", " << world() << std::endl;
}


