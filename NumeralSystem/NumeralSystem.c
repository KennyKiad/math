#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Перевод в любую систему счисления
#if 0
int print_conv(unsigned int n, unsigned int base)
{
    int tmp[32];
    int k = 0;
    int arrtobit = 0;

    do
    {
        tmp[k] = n % base;

        k = k + 1;
        n = n / base;
    } while (n != 0);

    do
    {
        putchar(tmp[k - 1] + 0x30);
        --k;
    } while (k > 0);
    printf("\n");
}
#endif

// Выводит десятичное число в факториальную систему
#if 1
int print_fact_sys(unsigned int n)
{
    int tmp[32];
    int k = 1;

    do
    {
        tmp[k] = n % k;
        n = n / k;
        k = k + 1;

    } while (n != 0);

    do
    {
        putchar(tmp[k - 1] + 0x30);
        putchar(46);
        --k;
    } while (k > 2);
    printf("\n");
}
#endif

int main()
{
    print_fact_sys(463);

    return 0;
}
