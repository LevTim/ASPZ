#include <stdio.h>
#include <time.h>
#include <limits.h>

int main() {
    // Визначення максимального значення time_t
    time_t max_time_t;

    // Для 32-бітної архітектури
    #if UINT_MAX == 0xFFFFFFFF
        max_time_t = (time_t)0x7FFFFFFF; // Максимальне значення для 32-бітного signed int
        printf("32-bit architecture:\n");
        printf("Max time_t: %ld\n", (long)max_time_t);
        printf("Will overflow on: %s", ctime(&max_time_t));
    #endif

    // Для 64-бітної архітектури
    #if UINT_MAX == 0xFFFFFFFFFFFFFFFF
        max_time_t = (time_t)0x7FFFFFFFFFFFFFFF; // Максимальне значення для 64-бітного signed int
        printf("64-bit architecture:\n");
        printf("Max time_t: %ld\n", (long)max_time_t);
        printf("Will overflow on: %s", ctime(&max_time_t));
    #endif

    return 0;
}