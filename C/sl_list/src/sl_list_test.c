#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/singly_linked_list.h"

static char* print_int(const void* elem)
{
  char* result = calloc(MAX_INT_DIGITS, 1);
  int int_elem = *(int*)elem;
  sprintf(result, "%d", int_elem);
  return result;
}

static char* print_double(const void* elem)
{
  char* result = calloc(MAX_DOUBLE_DIGITS, 1);
  double dbl_elem = *(double*)elem;
  sprintf(result, "%lf", dbl_elem);
  return result;
}

int main(int argc, char** argv)
{
  struct sl_list sll;
  char type[TYPE_DIM];
  char op[OP_DIM];
  size_t size;
  int n;
  int i;
  to_string_t fts;

  sl_list_init(&sll);

  /* Read the type of each element in the list */
  scanf("%s", type);
  if (strcmp(type, "int") == 0) {
    size = sizeof(int);
    fts = print_int;
  } else if (strcmp(type, "double") == 0) {
    size = sizeof(double);
    fts = print_double;
  }

  /* Read the number of elements in the list */
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    memset(op, 0, OP_DIM);
    scanf("%s", op);
    if (strcmp(op, "add_front") == 0) {
      if (strcmp(type, "int") == 0) {
        int crt_elem;
        scanf("%d", &crt_elem);
        sl_list_add_front(&sll, &crt_elem, size);
      } else if (strcmp(type, "double") == 0) {
        double crt_elem;
        scanf("%lf", &crt_elem);
        sl_list_add_front(&sll, &crt_elem, size);
      }
    } else if (strcmp(op, "add_back") == 0) {
      if (strcmp(type, "int") == 0) {
        int crt_elem;
        scanf("%d", &crt_elem);
        sl_list_add_back(&sll, &crt_elem, size);
      } else if (strcmp(type, "double") == 0) {
        double crt_elem;
        scanf("%lf", &crt_elem);
        sl_list_add_back(&sll, &crt_elem, size);
      }
    } else if (strcmp(op, "del_front") == 0) {
      sl_list_del_front(&sll);
    } else if (strcmp(op, "del_back") == 0) {
      sl_list_del_back(&sll);
    } else if (strcmp(op, "top_front") == 0) {
      if (strcmp(type, "int") == 0) {
        int* pi = sl_list_top_front(&sll, size);
        printf("%d\n", *pi);
        free(pi);
      } else if (strcmp(type, "double") == 0) {
        double* pd = sl_list_top_front(&sll, size);
        printf("%lf\n", *pd);
        free(pd);
      }
    } else if (strcmp(op, "top_back") == 0) {
      if (strcmp(type, "int") == 0) {
        int* pi = sl_list_top_back(&sll, size);
        printf("%d\n", *pi);
        free(pi);
      } else if (strcmp(type, "double") == 0) {
        double* pd = sl_list_top_back(&sll, size);
        printf("%lf\n", *pd);
        free(pd);
      }
    } else if (strcmp(op, "rev") == 0) {
      sl_list_reverse(&sll);
    } else if (strcmp(op, "print") == 0) {
      if (strcmp(type, "int") == 0) {
        char* sl_list_as_str = sl_list_str(&sll, print_int);
        printf("%s\n", sl_list_as_str);
        free(sl_list_as_str);
      } else if (strcmp(type, "float") == 0) {
        char* sl_list_as_str = sl_list_str(&sll, print_double);
        printf("%s\n", sl_list_as_str);
        free(sl_list_as_str);
      }
    } else if (strcmp(op, "iter_init") == 0) {
      iterate(&sll, size, 1);
    } else if (strcmp(op, "iter") == 0) {
      if (strcmp(type, "int") == 0) {
        int* pi = iterate(&sll, size, 0);
        printf("%d\n", *pi);
        free(pi);
      } else if (strcmp(type, "double") == 0) {
        double* pd = iterate(&sll, size, 0);
        printf("%lf\n", *pd);
        free(pd);
      }
    } else if (strcmp(op, "mid") == 0) {
      if (strcmp(type, "int") == 0) {
        int *pi = sl_list_find_middle(&sll, size);
        printf("%d\n", *pi);
        free(pi);
      } else if (strcmp(type, "float") == 0) {
        double* pd = sl_list_find_middle(&sll, size);
        printf("%lf\n", *pd);
        free(pd);
      }
    }
  }

  sl_list_finalize(&sll);
  return 0;
}
