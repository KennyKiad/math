#define _CRT_SECURE_NO_WARNINGS

#include <math.h>
#include <stdio.h>
#include <random>

#include "Pow.h"

char Ferm_test(unsigned long long prim)
{
	int i;
	unsigned long long n = 0;
	struct timespec ts;
	if (prim <= 0) {
		return 0;
	} else if (prim <= 3.0)
	{
		return 1;
	}

	for (i = 0; i < 100; i++)
	{
		timespec_get(&ts, TIME_UTC);
		n = ((ts.tv_nsec >> 3) % prim);
		
		if ((n % prim) != 0)
		{
			double dPrim = (double)prim;
			double tmp = pow((double)n, (dPrim - 1.0));
			if (fmod( tmp, dPrim) != 1.0)
			{
				return 0;
			}
		}
		
	}
	return 1;
}

int main()
{
	unsigned long long prim;
	unsigned long long tmp ;
	int res;

	printf("%f\n", fmod( fast_pow_dbl(17.0, 30.0), 31.0));

	while (1)
	{
		if (scanf("%llu", &prim) == 0)
		{
			return 1;
		}

		printf("%d\n\n", Ferm_test(prim));
	}
}

