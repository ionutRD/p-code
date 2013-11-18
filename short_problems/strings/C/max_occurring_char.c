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

char get_maximum_occurring_char(const char *str)
{
    int table[NO_OF_CHARS] = { 0 };
    int n = strlen(str);

    if (str == NULL)
        return 0;

    for (int i = 0; i < n; i++)
        ++table[str[i]];

    int max_idx = max_index(table, NO_OF_CHARS);
    if (max_idx < 0)
        return 0;

    return max_idx;
}

int main(int argc, char **argv)
{
    printf("Test 1 : test string = %c\n", get_maximum_occurring_char("test string"));
    assert(get_maximum_occurring_char("test_string") == 't');
    printf("Test 2 : test string = %c\n", get_maximum_occurring_char("ana are mere"));
    assert(get_maximum_occurring_char("ana are mere") == 'a');
    printf("Test 3 : test string = %c\n", get_maximum_occurring_char("x"));
    assert(get_maximum_occurring_char("x") == 'x');
    return 0;
}
