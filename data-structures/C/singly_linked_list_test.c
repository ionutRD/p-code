/*
 * @author Ionuț Radu
 * @date Friday, 12 October 2012
 */

/* System headers */
#include <stdio.h>

/* User defined headers*/
#include "singly_linked_list.h"
#define MAX 10

void print_int(void*, FILE*);
void print_str(void*, FILE*);
int comp_int(const void*, const void*);
int comp_str(const void*, const void*);

int main(void)
{
  int idx;
  struct sl_list* list_int = create_sl_list(comp_int);
  FILE* f = fopen("sl_list.out", "w");

  /* TEST sl_list_add_back */
  for (idx = 0; idx < MAX; idx++) {
    sl_list_add_back(list_int, &idx, sizeof(int));
  }

  /* TEST sl_list_add_nth */
  idx = 10;
  sl_list_add_nth(list_int, &idx, sizeof(int), -1);

  idx = 15;
  sl_list_add_nth(list_int, &idx, sizeof(int), 2);

  idx = 20;
  sl_list_add_nth(list_int, &idx, sizeof(int), 11);

  /* TEST sl_list_add_front */
  idx = 25;
  sl_list_add_front(list_int, &idx, sizeof(int));

  /* TEST sl_list_add_nth error */
  idx = 30;
  sl_list_add_nth(list_int, &idx, sizeof(int), -2);

  /* TEST sl_list_del_front */
  sl_list_delete_front(list_int);
  sl_list_repr(list_int, print_int, f);

  /* TEST sl_list_del_nth */
  sl_list_delete_nth(list_int, 2);
  sl_list_repr(list_int, print_int, f);

  sl_list_delete_nth(list_int, 3);
  sl_list_repr(list_int, print_int, f);

  /* TEST sl_list_mid_node */
  fprintf(f, "mid=%d\n", *(int*)sl_list_mid_node(list_int)->info);

  idx = 35;
  sl_list_add_nth(list_int, &idx, sizeof(int), 3);
  fprintf(f, "mid=%d\n", *(int*)sl_list_mid_node(list_int)->info);

  idx = 40;
  sl_list_add_nth(list_int, &idx, sizeof(int), -1);
  sl_list_repr(list_int, print_int, f);
  fprintf(f, "mid=%d\n", *(int*)sl_list_mid_node(list_int)->info);

  fclose(f);
  return 0;
}

void print_int(void* x, FILE* f)
{
  int a = *(int*)x;
  fprintf(f, "%d", a);
}

void print_str(void* x, FILE* f)
{
  char* str = (char*)x;
  fprintf(f, "%s", str);
}

int comp_int(const void* x, const void* y)
{
  int a = *(int*)x;
  int b = *(int*)y;

  if (a > b) {
    return 1;
  }

  if (a < b) {
    return -1;
  }

  return 0;
}

int comp_str(const void* s1, const void* s2)
{
  return strcmp(s1, s2);
}
