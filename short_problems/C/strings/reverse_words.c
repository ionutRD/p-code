/**
 * Reverse words in a given string
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void custom_revert(char *str, int i, int j)
{
    if (str == NULL || i >= j || i < 0 || j >= strlen(str))
        return;

    while(i < j) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
}

void find_next_indexes(char *str, int crt, int *start, int *end)
{
    if (str == NULL || start == NULL ||
        end == NULL || crt < 0)
        return;

    if (crt >= strlen(str)) {
        *start = *end = -1;
        return;
    }

    int i = crt;
    int sz = strlen(str);
    while (i < sz && !isalpha(str[i])) {
        i++;
    }

    if (i != sz)
        *start = i;
    else {
        *start = *end = -1;
        return;
    }

    while (i < sz && isalpha(str[i]))
        i++;

    *end = i - 1;
}

char *reverse_words(char *sentence)
{
    if (sentence == NULL)
        return NULL;

    int sz = strlen(sentence);
    int inf = 0, sup = -1;

    custom_revert(sentence, 0, sz - 1);
    while (inf >= 0) {
        find_next_indexes(sentence, sup + 1, &inf, &sup);
        custom_revert(sentence, inf, sup);
    }

    return sentence;
}


int main(int argc, char **argv)
{
    printf("Test 1: ana are mere => %s\n", reverse_words(strdup("ana are mere")));
    printf("Test 2: this is a beautiful story about kings and queens => %s\n", reverse_words(strdup("this is a beautiful story about kings and queens")));
    return 0;
}
