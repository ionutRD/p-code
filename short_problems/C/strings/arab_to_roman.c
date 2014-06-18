/**
 * Convert a number from arab format to
 * roman format
 * Example: 192 = CXCII
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_DIM_ROMAN 16

char *convert_unit(char ch1, char ch2, char ch3, unsigned int num)
{
    if (num > 9)
        return NULL;

    char *result = malloc(MAX_DIM_ROMAN);
    int base = num > 5 ? num - 5 : num;
    int addition = num < 5 ? 0 : 1;
    int i = 0;

    if (result == NULL)
        return NULL;

    if (num == 4 || num == 9) {
        result[0] = ch1;
        result[1] = num == 4 ? ch2 : ch3;
        result[2] = '\0';
    } else if (num == 0 || num == 5) {
        result[0] = num == 5 ? ch2 : ch3;
        result[1] = '\0';
    } else {
        for (i = 0; i < base; i++) {
            result[i + addition] = ch1;
        }
        result[i + addition] = '\0';
        if (num > 5)
            result[0] = ch2;
    }

    return result;
}

char *arab_to_roman(unsigned int num, int *err)
{
    if (num == 0 || num > 3999) {
        *err = -1;
        return NULL;
    }

    char syms[][3] = {{'I', 'V', 'X'},
                      {'X', 'L', 'C'},
                      {'C', 'D', 'M'},
                      {'M', 'M', 'M'}};

    int div = 1000;
    int rank = 3;
    char *roman = malloc(MAX_DIM_ROMAN);
    strcpy(roman, "");
    *err = 0;

    while (div >= 1) {
        int digit = (num / div) % 10;
        if (digit != 0) {
            char *roman_digit = convert_unit(syms[rank][0], syms[rank][1], syms[rank][2], digit);
            if (roman_digit == NULL) {
                free(roman);
                *err = -1;
                return NULL;
            }
            strcat(roman, roman_digit);
            free(roman_digit);
        }
        div /= 10;
        --rank;
    }

    return roman;
}

int main(int argc, char **argv)
{
    int err = 0;
    printf("Test 1: n = 1918 => %s\n", arab_to_roman(1918, &err));
    printf("Test 2: n = 75 => %s\n", arab_to_roman(75, &err));
    printf("Test 3: n = 3023 => %s\n", arab_to_roman(3023, &err));
    return 0;
}
