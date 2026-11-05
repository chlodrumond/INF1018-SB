#include <stdio.h>
#include <math.h>

float foo1(float a, float b);

int main()
{
    float a = (float)M_PI_2;
    float b = 3.5f;

    printf("%f\n", foo1(a, b));

    return 0;
}
