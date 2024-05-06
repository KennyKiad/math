#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <malloc.h>
#include <Windows.h>

#if 1
struct sieve_t {
    unsigned long size;
    unsigned char* sieve;
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

unsigned int is_prime(struct sieve_t *s, unsigned long n)
{
    int byte = n / 8;
    int offset = n % 8;

    assert(n < s->size);
    if (n < 4) return 1;
    
    int x = ((s->sieve[byte] >> offset) & 1);
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
void init_sieve(struct sieve_t* s)
{
    int byte, offset;
    for (int i = 2; (i * i) < s->size; i++)
    {
        if (is_prime(s, i))
        {
            for (int j = i * i; j < s->size; j += i)
            {
                byte = j / 8;
                int bit = (1 << (j % 8));
                s->sieve[byte] = (s->sieve[byte] | bit);

            }
        }
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
    s.sieve = (unsigned char *)calloc((s.size / 8) + 1, sizeof(char));
    if (s.sieve == 0)
    {
        return 1;

    }

    init_sieve(&s);

    for (int i = 2; i < s.size; i++)
    {
        if (is_prime(&s, i))
        {
            cnt++;
        }
    }
    printf("%d\n", cnt);

    free(s.sieve);

    return 0;
}