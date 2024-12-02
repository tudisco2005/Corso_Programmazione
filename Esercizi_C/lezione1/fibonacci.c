#include <stdio.h>

#define CACHE_SIZE 100
#define FB_MAX 90

long long cache[CACHE_SIZE];

void my_memset(long long arr[], int val, int lenght) {
    for (int i = 0; i < lenght; i++){
        arr[i] = val;
    }
}

long long fb(int val) {
    if(val == 0) return 0;
    if(val == 1) return 1;
    if(cache[val] != 0) return cache[val];


    cache[val] = fb(val-2) + fb(val-1);
    return cache[val];
}

int main() {
    my_memset(cache, 0, CACHE_SIZE);

    for(int i = 0; i<CACHE_SIZE; i++) {
        printf("cache (%d) = %lld\n", i, cache[i]);
    }

    printf("\n----------------------\n");
    for(int i = 0; i<FB_MAX; i++) {
        printf("fb %d = %lld\n", i, fb(i));
    }
    return 0;
}