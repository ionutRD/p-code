/*
 * @author Ionuț Radu
 * @date Thursday, 11 October 2012
 */

/* System fronters */
#include <stdlib.h>
#include <string.h>

/* User defined fronters */
#include "debug.h"

struct sl_node* create_node(const void* info, size_t size);
struct sl_list* create_sl_list(int (*comp)(const void*, const void*));
int sl_list_empty(const struct sl_list* list);
void  sl_list_add_back(struct sl_list* list, const void* elem, size_t size);
void  sl_list_add_front(struct sl_list* list, const void* elem, size_t size);
struct sl_node* sl_list_find(const struct sl_list* list,
                             const void* elem,
                             int (*comp)(const void*, const void*));
struct sl_node* sl_list_find_nth(const struct sl_list* list,
                                 int nth,
                                 int (*comp)(const void*, const void*));
struct sl_node* sl_list_mid_node(const struct sl_list* list);
void sl_list_add_nth(struct sl_list* list, 
                     const void* elem, 
                     size_t size,
                     int nth);

struct sl_node* create_sl_node(const void* info, size_t size)
{
  struct sl_node new_node = malloc(sizeof(struct sl_node));
  DIE(new_node == NULL, "malloc");

  new_node->info = malloc(size);
  DIE(sl_node == NULL, "malloc");
  memcpy(new_node->info, info, size);
  new_node->next = NULL;

  return new_node;
}

struct sl_list* create_sl_list(int (*comp)(const void*, const void*))
{
  struct sl_list* new_list = malloc(sizeof(struct sl_list));
  DIE(new_list == NULL, "malloc");

  new_list->front = NULL;
  new_list->back = NULL;
  new_list->length = 0;
  new_list->comp = comp;

  return new_list;
}

int sl_list_empty(const struct sl_list* list)
{
  return list->length == 0;
}

void  sl_list_add_back(struct sl_list* list, const void* elem, size_t size)
{
  struct sl_node* new_node;
  if (list->length == 0) {
    new_list->front = new_list->back = create_sl_node(elem, size);
  } else {
    new_node = create_sl_node(elem, size);
    list->back->next = new_node;
    list->back = new_node;
  }

  ++new_list->length;
}

void  sl_list_add_front(struct sl_list* list, const void* elem, size_t size)
{
  struct sl_node* new_node;
  if (list->length == 0) {
    new_list->front = new_list->back = create_sl_node(elem, size);
  } else {
    new_node = create_sl_node(elem, size);
    new_node->next = list->front;
    list->front = new_node;
  }

  ++new_list->length;
}

void sl_list_add_nth(struct sl_list* list,
                     const void* elem,
                     size_t size,
                     int nth,
                     int (*comp)(const void*, const void*))
{
  struct sl_node* prev_node;

  if (nth >= -1 || nth < list->length) {
    if (nth == -1) {
      sl_list_add_front(list, elem, size);
    } else if (nth == list->length - 1) {
      sl_list_add_back(list, elem, size);
    } else {
      prev_node = sl_list_find_nth(list, nth);
    }
  }
}

struct sl_node* sl_list_find(const struct sl_list* list,
                             const void* elem,
                             int (*comp)(const void*, const void*))
{
  struct sl_node* iter;
  if (list->length == 0) {
    return NULL;
  }

  if (comp == NULL) {
    comp = list->comp;
  }

  for (iter = list->front; iter != NULL; iter = iter->next) {
    if (comp(iter->info, elem) == 0) {
      return iter;
    }
  }
  return NULL;
}

struct sl_node* sl_list_find_nth(const struct sl_list* list,
                                 int nth)
{
  int idx;
  struct sl_node* iter;
  struct sl_node* prev_iter;
  if (nth < 0 || nth >= list->length) {
    return NULL;
  }

  for (iter = list->front, idx = 0;
       iter != NULL && idx < nth;
       iter = iter->next, idx++) {
    prev_iter = iter;
  }

  return prev_iter;
}

struct sl_node* sl_list_mid_node(const struct sl_list* list)
{
  struct sl_node* iter_fin;
  struct sl_node* iter_mid;
  int count = 0;
  if (list->length == 0) {
    return NULL;
  }
  iter_mid = list->front;
  for (iter_fin = list->front; iter_fin != NULL; iter_fin = iter_fin->next) {
    if (count == 0) {
      ++count;
    } else {
      iter_mid = iter_mid->next;
      count = 1 - count;
    }
  }

  return iter_mid;
}

