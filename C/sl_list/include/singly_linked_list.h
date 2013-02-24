#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H
#include "../../util/utils.h"

struct sl_node;

struct sl_list {
  struct sl_node* front;
  struct sl_node* back;
  size_t size;
};

struct sl_node {
  void* key;
  struct sl_node *next;
};


void sl_list_init(struct sl_list*);
void sl_list_add_front(struct sl_list*, const void*, size_t);
void sl_list_add_back(struct sl_list*, const void*, size_t);
void sl_list_del_front(struct sl_list*);
void sl_list_del_back(struct sl_list*);
void* sl_list_top_front(struct sl_list*, size_t);
void* sl_list_top_back(struct sl_list*, size_t);
void sl_list_reverse(struct sl_list*);
void* iterate(struct sl_list*, size_t, int);
char* sl_list_str(struct sl_list*, to_string_t);
void sl_list_finalize(struct sl_list*);

#endif /* SINGLY_LINKED_LIST_H */
