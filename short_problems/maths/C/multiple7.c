/**
 * Write an efficient method to multiple by 7
 */
#include <stdio.h>

int multiple_by_7(int x)
{
    return (x << 3) - x;
}

int main(int argc, char **argv)
{
    printf("Test 1: 3 x 7 => %d\n", multiple_by_7(3));
    return 0;
}
