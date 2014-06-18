/**
 * Remove adjacent duplicates
 * e.g. azxxzy => ay
 */
#include <stdio.h>
#include <string.h>
#define STATE_0     0
#define STATE_1     1

char *remove_adj_dup(char *str)
{
    if (str == NULL)
        return NULL;

    int sz = strlen(str);
    if (sz == 1)
        return str;

    int new_idx = -1;
    int crt_idx = 0;
    int nxt_idx = 1;
    int state = STATE_0;

    while (nxt_idx < sz) {
        if (str[crt_idx] != str[nxt_idx] && state == STATE_0) {
            str[++new_idx] = str[crt_idx];
        } else if (str[crt_idx] != str[nxt_idx] && state == STATE_1) {
            if (str[nxt_idx] != str[new_idx]) {
                state = STATE_0;
            } else if (str[nxt_idx] == str[new_idx]) {
                --new_idx;
            }
        } else if (str[crt_idx] == str[nxt_idx]) {
            state = STATE_1;
        }
        ++crt_idx;
        ++nxt_idx;
    }

    if (str[crt_idx] != str[new_idx] && state == STATE_0) {
        str[++new_idx] = str[crt_idx];
    }
    str[++new_idx] = '\0';
    return str;
}

int main(int argc, char **argv)
{
    printf("Test 1: str='abxxcc' => %s\n",
            remove_adj_dup(strdup("abxxcc")));
    printf("Test 2: str='abxxxcc' => %s\n",
            remove_adj_dup(strdup("abxxxcc")));
    printf("Test 3: str='abxxxycc' => %s\n",
            remove_adj_dup(strdup("abxxxycc")));
    printf("Test 4: str='azxxzy' => %s\n",
            remove_adj_dup(strdup("azxxzy")));
    printf("Test 5: str='geeksforgeeg' => %s\n",
            remove_adj_dup(strdup("geeksforgeeg")));
    printf("Test 6: str='caaabbbaacdddd' => %s\n",
            remove_adj_dup(strdup("caaabbbaacdddd")));
    printf("Test 7: str='acaaabbbacdddd' => %s\n",
            remove_adj_dup(strdup("acaaabbbacdddd")));
    printf("Test 8: str='acbbcddc' => %s\n",
            remove_adj_dup(strdup("acbbcddc")));
    printf("Test 9: str='bbccb' => %s\n",
            remove_adj_dup(strdup("bbccb")));
    return 0;
}
