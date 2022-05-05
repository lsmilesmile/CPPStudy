/*
 * @Description: 
 * @Author: liuxiao
 * @Date: 2022-04-22 22:46:11
 */

#include <iostream>
#include <windows.h>
#include "log.h"



int main() {
    Log::init(TARGET_CONSOLE);
    LOG_INFO("我现在 %d years old嘎嘎发放", 55);
    LOG_INFO("我现在 %d years old嘎嘎发放", 55);
    LOG_INFO("我现在 %d years old嘎嘎发放", 55);
    LOG_INFO("我现在 %d years old嘎嘎发放", 55);
    LOG_INFO("我现在 %d years old嘎嘎发放", 55);
    Log::unInit();
    return 0;
}
