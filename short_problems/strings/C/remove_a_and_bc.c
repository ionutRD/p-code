/**
 * Remove a and bc from a given string
 */
#include <stdio.h>
#include <string.h>
#define STATE_0 0
#define STATE_B 1

char *remove_a_and_bc(char *str)
{
    if (str == NULL)
        return NULL;

    int old_idx = 0;
    int new_idx = 0;
    int sz = strlen(str);
    int state = STATE_0;

    while (old_idx < sz) {
        if (str[old_idx] == 'a' && state == STATE_B) {
            state = STATE_0;
            str[new_idx] = 'b';
            ++new_idx;
            ++old_idx;
        } else if (str[old_idx] == 'a' && state == STATE_0) {
            ++old_idx;
        } else if (str[old_idx] == 'b' && state == STATE_B) {
            str[new_idx] = 'b';
            ++new_idx;
            ++old_idx;
        } else if (str[old_idx] == 'b' && state == STATE_0) {
            ++old_idx;
            state = STATE_B;
        } else if (str[old_idx] == 'c' && state == STATE_B) {
            state = STATE_0;
            ++old_idx;
        } else if (str[old_idx] == 'c' && state == STATE_0) {
            str[new_idx] = 'c';
            ++new_idx;
            ++old_idx;
        } else if (state == STATE_B) {
            state = STATE_0;
            str[new_idx] = 'b';
            str[new_idx + 1] = str[old_idx];
            new_idx += 2;
            ++old_idx;
        } else {
            str[new_idx] = str[old_idx];
            ++new_idx;
            ++old_idx;
        }
    }

    if (state == STATE_B) {
        str[new_idx] = 'b';
        ++new_idx;
    }
    str[new_idx] = '\0';
    return str;
}

int main(int argc, char ** argv)
{
    printf("Test 1: str = 'abxbcbbcab' => %s\n",
            remove_a_and_bc(strdup("abxbcbbcab")));
    return 0;
}
