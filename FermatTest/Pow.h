

long long fast_pow(unsigned long long n, unsigned long long pow)
{
    unsigned long long x, y;
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

double fast_pow_dbl(double n, double pow)
{
    double x, y;
    x = n;
    y = 1;

    while (pow > 0)
    {
        if ((fmod(pow,2.0)) == 1)
        {
            y = (y * x);
            pow--;
        }
        x = (x * x);
        pow = pow / 2.0;
    }
    return y;
}

long long fast_pow_mod(unsigned long long n, unsigned long long pow, unsigned long long m)
{
    unsigned long long x, y;
    x = n;
    y = 1;

    while (pow > 0)
    {
        if ((pow % 2) == 1)
        {
            y = (y * x) % m;
            pow--;
        }
        x = (x * x) % m;
        pow = pow >> 1;
    }
    return y;
}
