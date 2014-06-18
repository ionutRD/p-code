/**
 * Print reverse of a string using recursion
 */
#include <stdio.h>
#include <string.h>

void print_reverse_rec(const char *str)
{
    if (str == NULL || *str == '\0')
        return;
    print_reverse_rec(str + 1);
    printf("%c", *str);
}

int main(int argc, char **argv)
{
    printf("Test 1: geeksforgeeks => \n");
    print_reverse_rec(strdup("geeksforgeeks"));
    printf("\n");
    printf("Test 2: a => \n");
    print_reverse_rec(strdup("a"));
    printf("\n");
    printf("Test 3: a => \n");
    print_reverse_rec(NULL);
    printf("\n");
    return 0;
}
