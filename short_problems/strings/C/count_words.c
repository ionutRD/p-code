/**
 * Count words in a string
 * Words are separated by any number of '\n', '\t' and ' '
 */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define IN_WORD     0
#define OUT_WORD    1

int is_in_word(char ch)
{
    if (ch != '\n' && ch != '\t' && ch != ' ')
        return 1;
    return 0;
}

int count_words(const char *str, int *err)
{
    if (str == NULL) {
        *err = -1;
        return 0;
    }

    int sz = strlen(str);
    int state = OUT_WORD;
    int no_words = 0;

    *err = 0;
    for (int i = 0; i < sz; i++)
        if (state == OUT_WORD && is_in_word(str[i])) {
            ++no_words;
            state = IN_WORD;
        } else if (state == IN_WORD && !is_in_word(str[i]))
            state = OUT_WORD;

    return no_words;
}

int main(int argc, char **argv)
{
    int err;
    printf("Test1: ana      are     mere => %d\n", count_words("ana     are     mere", &err));
    assert(count_words("ana     are    mere", &err) == 3 && err == 0);
    printf("Test2: hemisphere => %d\n", count_words("hemisphere", &err));
    assert(count_words("hemisphere", &err) && err == 0);
    return 0;
}
