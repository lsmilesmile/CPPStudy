/*
 * @Description: 
 * @Author: liuxiao
 * @Date: 2022-04-13 17:00:07
 */

#include <climits>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    long long ll_min = LLONG_MIN;
    long long ll_max = LLONG_MAX;
    unsigned long long ull_max = ULLONG_MAX;

    printf("min of long long: %lld\n", ll_min);
    printf("max of long long: %lld\n", ll_max);
    printf("max of unsigned long long: %llu\n", ull_max);

    std::cout << __cplusplus << std::endl;
    return 0;
}
