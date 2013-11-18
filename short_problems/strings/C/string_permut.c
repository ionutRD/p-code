/**
 * Write a C program to print all
 * permutations of a given string
 */
#include <stdio.h>
#include <string.h>

void do_print_permut(char *, int, int);

void swap(char *str, int i, int j)
{
    if (str != NULL) {
        int sz = sizeof(str);
        if (i < 0 || j < 0 || i >= sz || j >= sz)
            return;
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}

void print_permut(char *str)
{
    if (str != NULL) {
        int sz = strlen(str);
        do_print_permut(str, 0, sz);
    }
}

void do_print_permut(char *str, int k, int sz)
{
    if (k == sz) {
        printf("%s\n", str);
        return;
    }
    for (int i = k; i < sz; i++) {
        swap(str, i, k);
        do_print_permut(str, k + 1, sz);
        swap(str, i, k);

    }
}

int main(int argc, char **argv)
{
    print_permut(strdup("abc"));
    return 0;
}
