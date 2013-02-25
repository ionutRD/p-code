#! /usr/bin/python
# Merge two sorted doubly linked list in O(1) space

import doubly_linked_list

def dl_list_merge(dl1, dl2):
  iter1 = dl1.front
  iter2 = dl2.front
  start = True

  while iter1 != None and iter2 != None:
    if iter1.key < iter2.key:
      iter1 = iter1.next
    elif iter1.key >= iter2.key and start == True:
      old_node = iter2
      iter2 = iter2.next
      old_node.next = iter1
      iter1.prev = old_node
      old_node.prev = None
      dl1.front = old_node
    else:
      old_node = iter2
      iter2 = iter2.next
      old_node.next = iter1
      iter1.prev.next = old_node
      old_node.prev = iter1.prev
      iter1.prev = old_node
    start = False

  while iter2 != None:
    dl1.back.next = iter2
    iter2.prev = dl1.back
    dl1.back = iter2
    iter2 = iter2.next

if __name__ == "__main__":
  print "Test1: Merge two doubly linked list in O(1) space"
  dl1 = doubly_linked_list.DL_List()
  dl2 = doubly_linked_list.DL_List()
  for i in range(0, 10, 2):
    dl1.add_back(i)
  for i in range(1, 10, 2):
    dl2.add_back(i)
  dl_list_merge(dl1, dl2)
  print dl1
  print "Test2: Merge two doubly linked list in O(1) space"
  dl1 = doubly_linked_list.DL_List()
  dl2 = doubly_linked_list.DL_List()
  for i in range(0, 6, 2):
    dl1.add_back(i)
  for i in range(3, 9, 2):
    dl2.add_back(i)
  dl_list_merge(dl1, dl2)
  print dl1
  print "Test3: Merge two doubly linked list in O(1) space"
  dl1 = doubly_linked_list.DL_List()
  dl2 = doubly_linked_list.DL_List()
  for i in range(0, 12, 2):
    dl1.add_back(i)
  for i in range(1, 5, 2):
    dl2.add_back(i)
  dl_list_merge(dl1, dl2)
  print dl1
  print "Test4: Merge two doubly linked list in O(1) space"
  dl1 = doubly_linked_list.DL_List()
  dl2 = doubly_linked_list.DL_List()
  for i in range(4, 10, 2):
    dl1.add_back(i)
  for i in range(1, 5, 2):
    dl2.add_back(i)
  for i in range(11, 17, 2):
    dl2.add_back(i)
  dl_list_merge(dl1, dl2)
  print dl1
  print "Test5: Merge two doubly linked list in O(1) space"
  dl1 = doubly_linked_list.DL_List()
  dl2 = doubly_linked_list.DL_List()
  for i in range(6, 10, 2):
    dl1.add_back(i)
  for i in range(1, 5, 2):
    dl2.add_back(i)
  dl_list_merge(dl1, dl2)
  print dl1
  print "Test6: Merge two doubly linked list in O(1) space"
  dl1 = doubly_linked_list.DL_List()
  dl2 = doubly_linked_list.DL_List()
  for i in range(1, 5, 2):
    dl1.add_back(i)
  for i in range(6, 10, 2):
    dl2.add_back(i)
  dl_list_merge(dl1, dl2)
  print dl1

