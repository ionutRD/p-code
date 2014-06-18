/**
 * Check if two strings are anagram of each other
 */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define NO_OF_CHARS 256

int check_anagram(const char *s1, const char *s2)
{
    if (s1 == NULL || s2 == NULL)
        return 0;

    int sz1 = strlen(s1);
    int sz2 = strlen(s2);
    char table[NO_OF_CHARS] = { 0 };

    if (sz1 != sz2)
        return 0;

    for (int i = 0; i < sz1; i++) {
        ++table[s1[i]];
        --table[s2[i]];
    }

    for (int i = 0; i < NO_OF_CHARS; i++)
        if (table[i] != 0)
            return 0;
    return 1;
}

int main(int argc, char **argv)
{
    printf("Test 1: s1 = 'peretele', s2 = 'telepere' => %d\n", check_anagram("peretele", "telepere"));
    assert(check_anagram("peretele", "telepere") == 1);
    return 0;
}
