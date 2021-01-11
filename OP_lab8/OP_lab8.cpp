#define _USE_MATH_DEFINES
#define PI 3.14
#include <math.h>
#include <iostream>


int main()
{
    double h = 0.05;
    double x = 0.1;
    int n = 25;
    while (x <= 1)
    {
        double y = exp(x * cos(PI / 4)) * cos(x * sin(PI / 4));
        double s = 1;
        for (int i = 1; i <= n; i++)
        {
            int k = 1;
            for (int j = 2; j <= i; j++)
                k *= j;
            double slag = cos(i * PI / 4) / k * pow(x, i);
            s += slag;
        }
        printf("| %lf\t| %lf\t| %lf\t|\n", x, y, s);
        x += h;
    }
    return 0;
}