/**
 * Given a string and a pattern with . and * wildcards
 * check whether the string match the pattern
 */
#include <stdio.h>
#include <string.h>

int str_match(const char *str, const char *pat)
{
    if (*pat == '\0' && *str == '\0')
        return 1;

    if (*(pat + 1) == '*' && *(pat + 2) == '\0' && *str == '\0')
        return 1;

    if (*pat == '\0' || *str == '\0')
        return 0;

    if (*(pat + 1) == '*')
        return str_match(str + 1, pat) || str_match(str, pat + 2);

    if (*pat == *str || *pat == '.')
        return str_match(str + 1, pat + 1);

    return 0;
}

int main(int argc, char **argv)
{
    printf("Test 1: str='anax' pat='anaxi'=> %d\n",
            str_match("anax", "anaxi"));
    printf("Test 2: str='anax' pat='a..x' => %d\n",
            str_match("anax", "a..x"));
    printf("Test 3: str='baaac', pat='ba*c' => %d\n",
            str_match("baaac", "ba*c"));
    printf("Test 4: str='bccd', pat='ba*c*d' => %d\n",
            str_match("bccd", "ba*c*d"));
    printf("Test 5: str='abcd', pat='.*d' => %d\n",
            str_match("abcd", ".*d"));
    printf("Test 6: str='abcdefgh', pat='.*' => %d\n",
            str_match("abcdefgh", ".*"));
    return 0;
}
