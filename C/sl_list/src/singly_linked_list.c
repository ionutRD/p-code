#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/singly_linked_list.h"

static void* make_node(const void* info, size_t size)
{
  struct sl_node* new_sl_node = malloc(sizeof(struct sl_node));
  DIE(new_sl_node == 0, "malloc");

  new_sl_node->key = malloc(size);
  memcpy(new_sl_node->key, info, size);
  DIE(new_sl_node->key == 0, "malloc");
  new_sl_node->next = NULL;

  return new_sl_node;
}

static void free_node(struct sl_node** sln)
{
  if (*sln != 0) {
    if ((*sln)->key != 0) {
      free((*sln)->key);
    }
    free(*sln);
    *sln = 0;
  }
}

/**
 * Initialize a singly linked list
 * @sll - a singly linked list
 */
void sl_list_init(struct sl_list* sll)
{
  sll->front = sll->back = NULL;
  sll->size = 0;
}

/**
 * Add a new node in front of the list
 * @sll - a singly linked list
 * @info - the value of the newly added node
 * @size - the total size of the value
 */
void sl_list_add_front(struct sl_list* sll, const void* info, size_t size)
{
  if (sll->size == 0) {
    sll->front = sll->back = make_node(info, size);
  } else {
    struct sl_node* new_sl_node = make_node(info, size);
    new_sl_node->next = sll->front;
    sll->front = new_sl_node;
  }
  ++sll->size;
}

/**
 * Add a new node at the end of the list
 * @sll - a singly linked list
 * @info - the value of the newly added node
 * @size - the total size of the value
 */
void sl_list_add_back(struct sl_list* sll, const void* info, size_t size)
{
  if (sll->size == 0) {
    sll->front = sll->back = make_node(info, size);
  } else {
    struct sl_node* new_sl_node = make_node(info, size);
    sll->back->next = new_sl_node;
    sll->back = new_sl_node;
  }
  ++sll->size;
}

/**
 * Iterate through the entire list
 * @sll - a singly linked list
 * @size - the total size of a list element
 * @init - specifies whether to reset the iterator
 *         to the first element
 * @return the value of the current interator
 */
void* iterate(const struct sl_list* sll, size_t size, int init)
{
  static struct sl_node* iter;
  if (init == 1) {
    iter = sll->front;
    return 0;
  }

  if (iter == 0) {
      return 0;
  }

  void* crt_val = malloc(size);
  DIE(crt_val == 0, "malloc");
  memcpy(crt_val, iter->key, size);
  iter = iter->next;
  return crt_val;
}

/**
 * Deletes the first element in a singly linked list
 * @sll - a singly linked list
 */
void sl_list_del_front(struct sl_list* sll)
{
  if (sll->size == 0) {
    return ;
  }
  struct  sl_node* old_first = sll->front;
  sll->front = sll->front->next;
  if (sll->size == 1) {
    sll->back = sll->back->next;
  }
  free_node(&old_first);
  --sll->size;
}

/**
 * Deletes the last element in a singly linked list
 * @sll - a singly linked list
 */
void sl_list_del_back(struct sl_list* sll)
{
  if (sll->size == 0) {
    return ;
  }
  if (sll->size == 1) {
    free_node(&sll->front);
    sll->front = sll->back = 0;
  } else {
    struct sl_node* iter = sll->front;
    while (iter->next->next != 0) {
      iter = iter->next;
    }
    free_node(&sll->back);
    sll->back = iter;
    sll->back->next = 0;
  }
  --sll->size;
}

/**
 * Return a copy of the first element in the list
 * @sll - a singly linked list
 * @size - the total size of the first element in the list
 */
void* sl_list_top_front(const struct sl_list* sll, size_t size)
{
  if (sll->size == 0) {
    return 0;
  }
  void* key = malloc(size);
  DIE(key == 0, "malloc");
  memcpy(key, sll->front->key, size);
  return key;
}

/**
 * Return a copy of the last element in the list
 * @sll - a singly linked list
 * @size - the total size of the first element in the list
 */
void* sl_list_top_back(const struct sl_list* sll, size_t size)
{
  if (sll->size == 0) {
    return 0;
  }
  void* key = malloc(size);
  memcpy(key, sll->back->key, size);
  DIE(key == 0, "malloc");
  return key;
}

/**
 * Reverse a singly linked list in place
 * @sll - a singly linked list
 */
void sl_list_reverse(struct sl_list* sll)
{
  if (sll->size != 0 && sll->size != 1) {
    struct sl_node* prev = 0;
    struct sl_node* crt = sll->front;
    struct sl_node* aux;

    while (crt != 0) {
      aux = crt->next;
      crt->next = prev;
      prev = crt;
      crt = aux;
    }

    aux = sll->front;
    sll->front = prev;
    sll->back = aux;
  }
}

/**
 * Find the middle element of a singly linked list
 * @sll - a singly linked list
 * @size - the size of an element
 * return the address of the middle element
 */
void* sl_list_find_middle(const struct sl_list* sll, size_t size)
{
  if (sll->size == 0) {
    return 0;
  }
  int k = 0;
  struct sl_node* middle = sll->front;
  struct sl_node* last = sll->front;
  void* result;

  while (last != 0) {
    last = last->next;
    if (k == 1) {
      middle = middle->next;
    }
    k = 1 - k;
  }

  result = malloc(size);
  DIE(result == 0, "malloc");
  memcpy(result, middle->key, size);

  return result;
}

/**
 * Transform a list into a string representation
 * @sll - a singly linked list
 * @fts - a function that converts an element in the list into
 *        a string
 * @return a string representation of a list
 */
char* sl_list_str(const struct sl_list* sll, to_string_t fts)
{
  int init_cap = INIT_STR_CAP;
  int actual_len = 0;
  char* result = calloc(init_cap, 1);
  DIE(result == 0, "calloc");
  struct sl_node* iter = sll->front;

  *result = '[';
  ++actual_len;

  while (iter != 0) {
    char* iter_str = (*fts)(iter->key);
    int iter_str_len = strlen(iter_str);
    if (actual_len + iter_str_len > init_cap) {
      init_cap += iter_str_len + 1;
      init_cap <<= 1;
      result = realloc(result, init_cap);
      DIE(result == 0, "realloc");
    }
    strcat(result, iter_str);
    actual_len = strlen(result);
    free(iter_str);
    if (iter->next != 0) {
      strcat(result, ", ");
    } else {
      strcat(result, "]");
    }
    iter = iter->next;
  }

  if (sll->size == 0) {
    strcat(result, "]");
  }

  return result;
}

/**
 * Deallocate the memory of a singly linked list
 * @sll - a singly linked list
 */
void sl_list_finalize(struct sl_list* sll)
{
  if (sll->size != 0) {
    struct sl_node* iter = sll->front;
    struct sl_node* tmp = 0;
    while (iter != 0) {
      tmp = iter;
      iter = iter->next;
      free_node(&tmp);
    }
  }
}
