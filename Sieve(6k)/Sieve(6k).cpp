#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <malloc.h>
#include <Windows.h>

#if 0
struct sieve_t {
    unsigned long size;
    unsigned char* sieve;
};
#endif


#if 1
struct sieve_t {
    unsigned long size;
    unsigned char* plus;
    unsigned char* minus;
};
#endif

unsigned long long sieve_bound(unsigned long num)
{

    double dnum = (double)num;
    dnum = dnum * (log(dnum) + log(log(dnum)));
    return (unsigned long long)round(dnum);
}

#if 0  // is_prime without Sieve
int is_prime(unsigned long n)
{
    if (n < 2) return 0;

    for (int j = 2; j * j < n; ++j)
    {
        if ((n % j) == 0)
            return 0;
    }
    return 1;
}
#endif

unsigned int is_prime(struct sieve_t* s, unsigned long n)
{
    int byte = n / 8;
    int offset = n % 8;

    assert(n < s->size);
    if (n < 4) return 1;

    int x = ((s->minus[byte] >> offset) & 1);
    return (x == 0) ? 1 : 0;
}

#if 0
void init_sieve(struct sieve_t* s)
{
    for (int i = 2; (i * i) < s->size; i++)
    {
        if (s->sieve[i] == 1)
            continue;

        int j = i * i;
        while (1)
        {
            if (j < s->size)
            {
                s->sieve[j] = 1;
                j += i;
            }
            else {
                break;
            }
        }
    }
}
#endif

#if 1
char prime(int i)
{
    if ((i % 5) == 0 || (i % 7) == 0)
    {
        return 0;
    }
    return 1;
}

void init_sieve(struct sieve_t* s)
{
    int cell, offset;

    s->minus[0] = s->minus[0] | (1 << 1);
    s->plus[0] = s->plus[0] | (1 << 1);
    for (int k = 2; k < s->size; k++)
    {
        int m = (6 * k) - 1;
        int p = (6 * k) + 1;

        cell = k / 8;
        offset = k % 8;
        s->minus[cell] = s->minus[cell] | (prime(m) << offset);

        s->plus[cell] = s->plus[cell] | (prime(p) << offset);
    }
}
#endif

int main()
{
    int cnt = 0;
    struct sieve_t s;
    int res;
    res = scanf("%lu", &s.size);
    if (res == 0)
    {
        printf("Incorrect input: %d\n", GetLastError());
        return 1;
    }
    res = s.size;
    s.size = s.size + 8;
    s.plus = (unsigned char*)calloc((s.size / 8) + 1, sizeof(char));
    s.minus = (unsigned char*)calloc((s.size / 8) + 1, sizeof(char));

    init_sieve(&s);


    for (int i = 2; i < s.size; i++)
    {
        if (is_prime(&s, i))
        {
            cnt++;
        }
    }
    printf("%d\n", cnt);
   

    free(s.plus);
    free(s.minus);

    return 0;
}