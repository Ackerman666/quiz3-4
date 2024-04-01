#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>


int mod5(uint32_t n)
{
    int table[32] = {1,2,4,3,
                     1,2,4,3,
                     1,2,4,3,
                     1,2,4,3,
                     1,2,4,3,
                     1,2,4,3,
                     1,2,4,3,
                     1,2,4,3,};

    int mod = 0, index = 0;
    while(n){
        mod += (n & 0b1) * table[index];
        mod -= !!((5 - mod - 1) & 0x80000000) * 5;
        n = n >> 1;
        ++index;
    }
    return mod;
}

int mod9(uint32_t n)
{
    int table[36] = {1,2,4,8,7,5,
                     1,2,4,8,7,5,
                     1,2,4,8,7,5,
                     1,2,4,8,7,5,
                     1,2,4,8,7,5,
                     1,2,4,8,7,5};

    int mod = 0, index = 0;
    while(n){
        mod += (n & 0b1) * table[index];
        mod -= !!((9 - mod - 1) & 0x80000000) * 9;
        n = n >> 1;
        ++index;
    }
    return mod;
}


int main()
{
    for(uint32_t i = 0; i <= 0xFFFFFFFF; i++){
        assert((i % 5) == mod5(i));
        assert((i % 9) == mod9(i));
    }
    return 0;
}
