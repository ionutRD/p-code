/**
 * Write a program to calculate pow(x,n)
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 0.00000001


double power_pos(double, int);

double power(double x, int n)
{
    if (abs(x) < EPS && n <= 0)
        return 0;
    else if (abs(x) < EPS)
        return 0;
    else if (n <= 0)
        return 1 / power_pos(x, -n);
    return power_pos(x, n);
}

double power_pos(double x, int n)
{
    if (n == 0)
        return 1;
    double hsq = power_pos(x, n >> 1);
    double result = hsq * hsq;
    if (n & 1)
        result *= x;
    return result;
}

int main(int argc, char **argv)
{
    printf("Test 1 : pow(3,4): ");
    printf("%lf\n", power(3.,4));
    printf("Test 2 : pow(4,2): ");
    printf("%lf\n", power(4.,2));
    printf("Test 3 : pow(5,3): ");
    printf("%lf\n", power(5.,3));
    printf("Test 4 : pow(7,1): ");
    printf("%lf\n", power(7.,1));
    printf("Test 5 : pow(2.,-3): ");
    printf("%lf\n", power(2.,-3));
    printf("Test 6 : pow(0.,7): ");
    printf("%lf\n", power(0.,7));
    printf("Test 7 : pow(1.,1): ");
    printf("%lf\n", power(1.,1));
    printf("Test 8 : pow(1.,2540): ");
    printf("%lf\n", power(1.,2540));
    return 0;
}
