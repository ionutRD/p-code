/**
 * Print all permutations in lexicographic order
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NO_OF_CHARS 256

int char_comp(const void *ch1, const void *ch2)
{
    return *(char *) ch1 - *(char *) ch2;
}

void do_permut_lexi(char *str, int k, char *table, const char *ord)
{
    if (k == strlen(ord)) {
        printf("%s\n", str);
        return;
    }

    int n = strlen(ord);
    for (int i = 0; i < n; i++)
        if (table[ord[i]] == 0) {
            table[ord[i]] = 1;
            str[k] = ord[i];
            do_permut_lexi(str, k + 1, table, ord);
            table[ord[i]] = 0;
        }
}

void permut_lexi(const char *str)
{
    if (str == NULL)
        return ;

    int n = strlen(str);
    char *ord = strdup(str);
    char *tmp = malloc(n);
    char table[NO_OF_CHARS] = { 0 };
    qsort(ord, n, 1, char_comp);
    do_permut_lexi(tmp, 0, table, ord);

    free(tmp);
    free(ord);
}

int main(int argc, char **argv)
{
    printf("Test 1: str = 'cadb' =>\n");
    permut_lexi("cadb");
    return 0;
}
