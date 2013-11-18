/**
 * Count the number of zeros a factorial ends
 */
#include <stdio.h>

int count_zeros_fact(int n)
{
    int i = 0;
    int zeros = 0;
    if (n < 5)
        return 0;
    for (; i <= n; i += 5) {
        int tmp = i;
        while (tmp && tmp % 5 == 0) {
            tmp = tmp / 5;
            ++zeros;
        }
    }
    return zeros;
}

int main(int argc, char **argv)
{
    printf ("Test 1 : zeros(1) = ");
    printf("%d\n", count_zeros_fact(1));
    printf ("Test 2 : zeros(2) = ");
    printf("%d\n", count_zeros_fact(2));
    printf ("Test 3 : zeros(3) = ");
    printf("%d\n", count_zeros_fact(3));
    printf ("Test 4 : zeros(4) = ");
    printf("%d\n", count_zeros_fact(4));
    printf ("Test 5 : zeros(5) = ");
    printf("%d\n", count_zeros_fact(5));
    printf ("Test 6 : zeros(6) = ");
    printf("%d\n", count_zeros_fact(6));
    printf ("Test 7 : zeros(25) = ");
    printf("%d\n", count_zeros_fact(25));
    return 0;
}
