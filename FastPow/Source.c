#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


double asm_get_mod(double x, double y);

const int MICROSEC_AS_NSEC = 1000, SEC_AS_MICROSEC = 1000000,
SEC_AS_NSEC = 1000000000;

double diff(struct timespec start, struct timespec end) {
    struct timespec temp;
    if (end.tv_nsec - start.tv_nsec < 0) {
        temp.tv_sec = end.tv_sec - start.tv_sec - 1;
        temp.tv_nsec = SEC_AS_NSEC + end.tv_nsec - start.tv_nsec;
    }
    else {
        temp.tv_sec = end.tv_sec - start.tv_sec;
        temp.tv_nsec = end.tv_nsec - start.tv_nsec;
    }
    double msec = temp.tv_sec * SEC_AS_MICROSEC + temp.tv_nsec / MICROSEC_AS_NSEC;
    return msec / SEC_AS_MICROSEC;
}


double fast_pow(double n, unsigned long long pow)
{
    double x, y;
    x = n;
    y = 1;

    while (pow > 0)
    {
        if ((pow % 2) == 1)
        {
            y = (y * x);
            pow--;
        }
        x = (x * x);
        pow = pow >> 1;
    }
    return y;
}

double fast_pow_mod(double n, unsigned long long pow, double m)
{
    double x, y;
    x = n;
    y = 1;

    while (pow > 0)
    {
        if ((pow % 2) == 1)
        {
            y = fmod((y * x), m);
            pow--;
        }
        x = fmod((x * x), m);
        pow = pow >> 1;
    }
    return y;
}

#if 0
int fast_spow_mod(unsigned int n, unsigned int spow, unsigned int m)
{
    unsigned int x, y;
    x = n;
    y = n;

    while (spow > 0)
    {
        if ((spow % 2) == 1)
        {
            y = fast_pow(x, y) % m;
            spow--;
        }
        x = fast_pow(x, x) % m;
        spow = spow >> 1;
    }
    return y;
}
#endif

int main()
{
    struct timespec start;
    struct timespec end;

    asm_get_mod(3.0, 2.0);
    

    timespec_get(&start, TIME_UTC);
        printf("%f\n", fast_pow_mod(2.0, 1024, 10.0));
    timespec_get(&end, TIME_UTC);
    printf("Time: %f\n", diff(start, end));

    timespec_get(&start, TIME_UTC);
        printf("%f\n", pow(2.0, 1024.0));
    timespec_get(&end, TIME_UTC);
    printf("Time: %f\n", diff(start, end));

    

    return 0;
}