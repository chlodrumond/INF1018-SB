#include <stdio.h>
#include <math.h>

double foo3(double *a, int n);

int main()
{
    int n = 2;
    double a[2] = {M_PI_2, M_PI_2};

    double resp = foo3(a, n);

    printf("%f\n", resp);

    return 0;
}
