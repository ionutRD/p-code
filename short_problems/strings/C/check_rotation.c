/**
 * Write a program to check if two strings are rotation
 * of each other or not
 */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int is_rot(const char *s1, const char *s2)
{
    if (s1 == NULL || s2 == NULL)
        return 0;
    int sz1 = strlen(s1), sz2 = strlen(s2);
    if (sz1 != sz2)
        return 0;
    char *aux = malloc(sz1 << 1);
    strcat(aux, s1);
    strcat(aux, s1);
    char *res = strstr(aux, s2);
    if (res) {
        free(aux);
        return 1;
    }
    free(aux);
    return 0;
}

int main(int argc, char **argv)
{
    printf("Test 1: s1 = ABCD, s2 = CDAB => %d\n", is_rot("ABCD", "CDAB"));
    printf("Test 2: s1 = ABCD, s2 = BCAD => %d\n", is_rot("ABCD", "BCAD"));
    return 0;
}
