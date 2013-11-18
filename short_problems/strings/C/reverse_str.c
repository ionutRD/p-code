/**
 * Reverse a given string
 */
#include <stdio.h>
#include <assert.h>
#include <string.h>

char *strrev(char *str)
{
    char *p = str, *q = str + strlen(str) - 1;

    if (!str)
        return NULL;

    while (p < q) {
        char tmp = *p;
        *p = *q;
        *q = tmp;
        p++;
        q--;
    }

    return str;
}

int main(int argc, char **argv)
{
    printf("Test 1: rev(abc) = %s\n", strrev(strdup("abc")));
    assert(strcmp("cba", strrev(strdup("abc"))) == 0);
    printf("Test 2: rev(ana are mere) = %s\n", strrev(strdup("ana are mere")));
    assert(strcmp("erem era ana", strrev(strdup("ana are mere"))) == 0);
    return 0;
}
