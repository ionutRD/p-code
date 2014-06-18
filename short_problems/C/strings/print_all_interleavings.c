/**
 * Print all interlevings of a given
 * pair of strings
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void do_print_all_interleavings(const char *s1, const char *s2, char *istr, int m, int n, int i);

void print_all_interleavings(const char *s1, const char *s2)
{
    if (s1 == NULL || s2 == NULL)
        return;

    int m = strlen(s1), n = strlen(s2);
    char *istr = malloc(m + n);
    do_print_all_interleavings(s1, s2, istr, m, n, 0);
}

void do_print_all_interleavings(const char *s1, const char *s2, char *istr, int m, int n, int i)
{
    if (m == 0 && n == 0)
        printf("%s\n", istr);

    if (m != 0) {
        istr[i] = s1[0];
        do_print_all_interleavings(s1 + 1, s2, istr, m - 1, n, i + 1);
    }

    if (n != 0) {
        istr[i] = s2[0];
        do_print_all_interleavings(s1, s2 + 1, istr, m, n - 1, i + 1);
    }
}

int main(int argc, char ** argv)
{
    printf("Test 1: s1 = 'AB', s2 = 'CD' =>\n");
    print_all_interleavings("AB", "CD");
    return 0;
}
