#include "cube.h"

double sin(double x)
{
    double sum = 0.0;

    double a  = 1.0; 
    double b  = 1.0;
    double expx = x;

    for (int i = 1; i <= SUM_LINM; i++)
    {
        sum += (a / b) * expx;
        
        expx *= x * x;

        a *= -1.0;
        b *= 4 * i * i + 2 * i;
    }

    return sum;
}

double cos(double x)
{
    double sum = 0.0;

    double a  = 1.0;
    double b  = 1.0;
    double expx = 1;

    for (int i = 1; i <= SUM_LINM; i++)
    {
        sum += (a / b) * expx;
        
        expx *= x * x;

        a *= -1.0;
        b *= 4 * i * i - 2 * i;
    }

    return sum;
}