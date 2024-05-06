#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <malloc.h>

char find_low(long long n)
{
    for (long long i = 0; i < (sizeof(long long) * 8); i++)
    {
        long long tmp = (static_cast<long long>(1) << i);
        if ((n & tmp) == tmp)
            return i;
    }
}

char find_up(long long n)
{
    
    for (long long i = ((sizeof(long long) * 8) - 1); i >= 0; i--)
    {
        long long tmp = (static_cast<long long>(1) << i);
        if ((n & tmp) == tmp)
            return i;
    }
}

int SetBits(long long n)
{
    long long cnt = 0;
    for (long long i = n; i > 0; i = (i & (i - 1)))
    {
        cnt++;
    }
    return cnt;
}

int main()
{
    long long num = 0;

    if (scanf("%lld", &num) == 0)
    {
        return 1;
    }

    printf("Bits: %d\n", SetBits(num));

    printf("%d\t", find_up(num));
    printf("%d\n", find_low(num));

    return 0;
}

//2699712745688965