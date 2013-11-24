/**
 * Write an efficient C funciton to return maximum occurring
 * character in the input string
 * For example: if the input string is "test string" the function should
 * return "t"
 */
#include<stdio.h>
#include <assert.h>
#include <string.h>
#define NO_OF_CHARS 256

int max_index(const int *arr, size_t dim)
{
    int max_idx = -1, max_val = -1;

    if (arr == NULL)
        return -1;

    for (int i = 0; i < dim; ++i)
        if (max_val < arr[i]) {
            max_val = arr[i];
            max_idx = i;
        }
    return max_idx;
}

char get_maximum_occurring_char(const char *str, int *err)
{
    int table[NO_OF_CHARS] = { 0 };
    int n = strlen(str);

    *err = 0;
    if (str == NULL) {
        *err = -1;
        return 0;
    }

    for (int i = 0; i < n; i++)
        ++table[str[i]];

    int max_idx = max_index(table, NO_OF_CHARS);
    if (max_idx < 0) {
        *err = -1;
        return 0;
    }

    return max_idx;
}

int main(int argc, char **argv)
{
    int err = 0;
    printf("Test 1 : test string = %c\n", get_maximum_occurring_char("test string", &err));
    assert(get_maximum_occurring_char("test_string", &err) == 't' && err == 0);
    printf("Test 2 : test string = %c\n", get_maximum_occurring_char("ana are mere", &err));
    assert(get_maximum_occurring_char("ana are mere", &err) == 'a' && err == 0);
    printf("Test 3 : test string = %c\n", get_maximum_occurring_char("x", &err));
    assert(get_maximum_occurring_char("x", &err) == 'x' && err == 0);
    return 0;
}
