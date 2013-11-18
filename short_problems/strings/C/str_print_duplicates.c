/**
 * Write a function to print all duplicates in
 * a given string
 */
#include <stdio.h>
#include <string.h>
#define NO_OF_CHARS 256

void solution(const char *str)
{
    size_t table[NO_OF_CHARS] = { 0 };
    int len = strlen(str);

    for (int i = 0; i < len; i++)
        table[str[i]]++;

    for (int i = 0; i < NO_OF_CHARS; i++) {
        if (table[i] > 0)
            printf("Character %c has %zu appearances\n", i, table[i]);
    }
}

int main(int argc, char **argv)
{
    solution(strdup("geeksforgeeks"));
    return 0;
}
