/*
 * @author Ionuț Radu
 * @date Thursday, 11 October 2012
 */
#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#define SEP "->"
#define TERM "NIL"

/* Singly linked list node */
struct sl_node {
  void* info;
  struct sl_node* next;
};

/* Singly linked list */
struct sl_list {
  struct sl_node* front;
  struct sl_node* back;
  size_t length;
  int (*comp)(const void*, const void*);
};

/* Create a new singly linked list */
struct sl_list* create_sl_list(int (*comp)(const void*, const void*));

/* Add a new element to the singly linked list */
void  sl_list_add_back(struct sl_list* list, const void* elem, size_t size);

/* Add a new element to the front of a singly linked list */
void  sl_list_add_back(struct sl_list* list, const void* elem, size_t size);

/* Add a new element after the nth element of a singly linked list */
void sl_list_add_nth(struct sl_list* list,
                     const void* elem,
                     size_t size,
                     int nth);

/* Verify emptiness of a singly linked list */
int sl_list_empty(const struct sl_list* list);

/* Search for a node in a singly linked list */
struct sl_node* sl_list_find(const struct sl_list* list,
                             const void* elem,
                             int (*comp)(const void*, const void*));

/* Find the nth element of a singly linked list */
struct sl_node* sl_list_find_nth(const struct sl_list* list,
                                 int nth);

/* Find the mid node */
struct sl_node* sl_list_mid_node(const struct sl_list* list);

/* Print the list */
void sl_list_repr(const struct sl_list* list, void (*print)(void*, FILE*), FILE* f);

/* Delete the nth element of a list */
void sl_list_delete_nth(struct sl_list* list, int nth);

/* Delete the first element of a list */
void sl_list_delete_front(struct sl_list* list);

#endif /* SINGLY_LINKED_LIST_H */
