#! /usr/bin/python

import singly_linked_list

def sl_list_rev(l):
  """ Reverse a singly linked list in place in one traversal"""
  node = l.front
  if l.front != None:
    nxt_node = node.next
    node.next = None
    while nxt_node != None:
      p = nxt_node.next
      nxt_node.next = node
      node = nxt_node
      nxt_node = p

    l.front = node

if __name__ == "__main__":
  print "Test1: reverse the list 0->1->3->4"
  l = singly_linked_list.SL_List()
  for i in range(5):
    l.add_back(i)
  print l
  sl_list_rev(l)
  print l

  print "Test2: reverse the list 0"
  l = singly_linked_list.SL_List()
  for i in range(1):
    l.add_back(i)
  print l
  sl_list_rev(l)
  print l

  print "Test3: reverse the list NIL"
  l = singly_linked_list.SL_List()
  print l
  sl_list_rev(l)
  print l


