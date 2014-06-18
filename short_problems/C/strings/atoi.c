/**
 * Write your own atoi function
 * It should support negative numbers
 */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

int my_atoi(const char *str, int *err)
{
    if (str == NULL) {
        *err = -1;
        return 0;
    }

    int num = 0;
    int sgn = 1;
    int sz = strlen(str);
    int start = 0;

    if (str[0] == '-') {
        sgn = -1;
        start = 1;
    } else if (str[0] == '+')
        start = 1;


    for (int i = start; i < sz; i++)
        if ('0' <= str[i] && str[i] <= '9') {
            if (num > INT_MAX / 10) {
                *err = -1;
                return 0;
            }
            num *= 10;

            if (num > INT_MAX - (str[i] - '0')) {
                *err = -1;
                return 0;
            }

            num += str[i] - '0';
        }
        else {
            *err = -1;
            return 0;
        }

    num *= sgn;
    *err = 0;

    return num;
}

int main(int argc, char **argv)
{
    int err = 0;
    printf("Test 1: n = 1923 => %d\n", my_atoi("1923", &err));
    assert(my_atoi("1923", &err) == 1923 && err == 0);
    printf("Test 2: n = -1923 => %d\n", my_atoi("-1923", &err));
    assert(my_atoi("-1923", &err) == -1923 && err == 0);
    printf("Test 3: n = -1 => %d\n", my_atoi("-1", &err));
    assert(my_atoi("-1", &err) == -1 && err == 0);
    printf("Test 4: n = 0 => %d\n", my_atoi("0", &err));
    assert(my_atoi("0", &err) == 0 && err == 0);
    printf("Test 5: n = +123 => %d\n", my_atoi("+123", &err));
    assert(my_atoi("+123", &err) == 123 && err == 0);
    printf("Test 6: n = +123+ => error\n");
    assert(my_atoi("+123+", &err) == 0 && err < 0);
    printf("Test 7: n = 12345678909876543211234567890 => error\n");
    assert(my_atoi("12345678909876543211234567890",  &err) == 0 && err < 0);
    return 0;
}
