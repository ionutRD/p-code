#! /usr/bin/python

import singly_linked_list

def sl_find_mid(lst):
  """ Find the middle element of a singly linked list """
  mid_node = node = lst.front
  i = 0
  while node != None:
    i = 1 - i
    node = node.next
    if i == 0:
      mid_node = mid_node.next
  return mid_node

if __name__ == "__main__":
  print "Test1:"
  sl_list = singly_linked_list.SL_List()
  for i in range(10):
    sl_list.add_back(i)

  print sl_list
  print str(sl_find_mid(sl_list))

  print "Test2:"
  sl_list = singly_linked_list.SL_List()
  for i in range(13):
    sl_list.add_back(i)

  print sl_list
  print str(sl_find_mid(sl_list))

  print "Test3:"
  sl_list = singly_linked_list.SL_List()

  print sl_list
  print str(sl_find_mid(sl_list))
