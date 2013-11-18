/**
 * Write a program to print N equal parts of a given string
 */
#include <stdio.h>
#include <string.h>

void print_eq_parts(const char *str, int n)
{
    if (str == NULL)
        return ;

    int sz = strlen(str);

    if (n <= 0 || n > sz)
        return ;

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
    print_eq_parts("geeksforgeeks", 3);
    return 0;
}
