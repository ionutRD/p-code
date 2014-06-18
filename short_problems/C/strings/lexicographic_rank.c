/**
 * Given a string, calculate the
 * lexicographic rank of it
 */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define NO_OF_CHARS 256

int fact(int n)
{
    int p = 1;
    for (int i = 1; i <= n; i++)
        p *= i;
    return p;
}

void update_table(char *table, int pos)
{
    if (pos < 0 || pos >= NO_OF_CHARS)
        return ;

    for (int i = pos; i < NO_OF_CHARS; i++)
        table[i]--;
}

int lexi_rank(const char *str, int *err)
{
    if (str == NULL) {
        *err = -1;
        return 0;
    }

    int sz = strlen(str);
    char table[NO_OF_CHARS] = { 0 };
    int count = 0;
    int prod = 1;
    int rank = 0;
    *err = 0;

    if (sz == 1 || sz == 0)
        return 1;

    for (int i = 0; i < sz; i++)
        table[str[i]] = 1;

    for (int i = 1; i < NO_OF_CHARS; i++) {
            table[i] += table[i - 1];
    }

    prod = fact(sz - 1);

    for (int i = 0; i < sz - 1; i++) {
        rank += (table[str[i]] - 1) * prod;
        prod /= (sz - i - 1);
        update_table(table, str[i]);
    }

    return rank + 1;
}

int main(int argc, char **argv)
{
    int err = 0;
    printf("Test 1: s = 'STRING' => %d\n", lexi_rank("STRING", &err));
    printf("Test 2: s = 'abc' => %d\n", lexi_rank("abc", &err));
    return 0;
}

