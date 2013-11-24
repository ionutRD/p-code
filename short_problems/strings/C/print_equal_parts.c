/**
 * Write a program to print N equal parts of a given string
 */
#include <stdio.h>
#include <string.h>

void print_eq_parts(const char *str, int n, int *err)
{
    if (str == NULL) {
        *err = -1;
        return ;
    }

    int sz = strlen(str);
    *err = 0;

    if (n <= 0 || n > sz) {
        *err = -1;
        return ;
    }

    if (n > sz)
        n = sz;

    int chunk = sz / n;

    for (int i = 0; i < sz; i++) {
        printf("%c", str[i]);
        if (i % chunk == 0 && i)
            printf("\n");
    }

}

int main(int argc, char **argv)
{
    int err = 0;
    print_eq_parts("geeksforgeeks", 3, &err);
    return 0;
}
