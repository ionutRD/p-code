#! /usr/bin/python

import singly_linked_list

def sl_del_altrn(l):
  """ Delete nodes on even positions in O(n) """
  node = l.front
  while node.next != None:
    print node.key
    node.next = node.next.next
    node = node.next
    if node == None:
      break

if __name__ == "__main__":
  print "Test1: l=0->1->2->3->4->5->6"
  l = singly_linked_list.SL_List()
  for i in range(7):
    l.add_back(i)
  sl_del_altrn(l)
  print l

  print "Test2: l=0->1"
  l = singly_linked_list.SL_List()
  for i in range(2):
    l.add_back(i)
  sl_del_altrn(l)
  print l

  print "Test3: l=0"
  l = singly_linked_list.SL_List()
  for i in range(1):
    l.add_back(i)
  sl_del_altrn(l)
  print l

