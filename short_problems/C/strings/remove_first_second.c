/**
 * Remove characters in the first string which
 * are present in the second string
 */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define NO_OF_CHARS 256

char *remove_first_second(char *s1, const char *s2)
{
    if (s1 == NULL || s2 == NULL)
        return s1;

    size_t table[NO_OF_CHARS] = { 0 };
    int sz1 = strlen(s1);
    int sz2 = strlen(s2);
    int idx_old = 0, idx_new = 0;

    for (int i = 0; i < sz2; i++)
        if (table[s2[i]] == 0)
            table[s2[i]] = 1;

    while (idx_old < sz1) {
        if (table[s1[idx_old]] == 0) {
            s1[idx_new] = s1[idx_old];
            ++idx_new;
        }
        ++idx_old;
    }

    s1[idx_new] = '\0';

    return s1;
}

int main(int argc, char **argv)
{
    printf("Test 1 : s1 = geeksforgeeks s2 = doxicologie => %s\n", remove_first_second(strdup("geeksforgeeks"), "doxicologie"));
    printf("Test 2 : s1 = geeksforgeeks s2 = xxxl => %s\n", remove_first_second(strdup("geeksforgeeks"), "xxxl"));
    printf("Test 3 : s1 = geeksforgeeks s2 = from geeks => %s\n", remove_first_second(strdup("geeksforgeeks"), "from geeks"));
    return 0;
}
