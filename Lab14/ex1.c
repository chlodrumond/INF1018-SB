#include <stdio.h>
#include <math.h>

#define getsig(x)        ((x)>>31 & 1)
#define getexp(x)        ((x)>>23 & 0xff)
#define getfrac(x)       ((x) & 0x7fffff)
#define makefloat(s,e,f) ((s & 1)<<31 | (((e) & 0xff) << 23) | ((f) & 0x7fffff))

typedef union 
{
    float f;
    unsigned int i;
} U;

float float2(float f)
{
    U u;
    unsigned int s, e, frac;

    u.f = f;

    s = getsig(u.i);
    e = getexp(u.i);
    frac = getfrac(u.i);

    if (e == 0)
    {
        frac = frac << 1;

        if (frac & 0x800000) 
        {
            e = 1;
            frac = frac & 0x7fffff;
        }
    }
    else if (e < 254) 
    {
        e++;
    }
    else if (e == 254) 
    {
        e = 255;
        frac = 0;
    }

    u.i = makefloat(s, e, frac);

    return u.f;
}
