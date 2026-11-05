#include <stdio.h>
#include <math.h>

double foo2(float a, float b);

int main()
{
    float a = (float)M_PI_2;
    float b = 0.0f;

    printf("%f\n", foo2(a, b));

    return 0;
}
