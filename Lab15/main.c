#include <stdio.h>

float foo(double a, float b);

int main()
{
    double a = 2.5;
    float b = 3.5f;

    printf("%f\n", foo(a, b));

    return 0;
}
