#! /usr/bin/python

import singly_linked_list

def sl_list_merge1(l1, l2):
  """ Merge two sorted list                                    """
  """ Assume lists hold numeric values                         """
  """ Assume list has both pointers to the first and last node """
  l = singly_linked_list.SL_List()
  node1 = l1.front
  node2 = l2.front
  while node1 != None and node2 != None:
    key = min(node1.key, node2.key)
    l.add_back(key)
    if key == node1.key:
      node1 = node1.next
    elif key == node2.key:
      node2 = node2.next
  while node1 != None:
    l.add_back(node1.key)
    node1 = node1.next
  while node2 != None:
    l.add_back(node2.key)
    node2 = node2.next
  return l

if __name__ == "__main__":
  print "Test1: l1 = 4->7->8, l2 = 0->1->5->6"
  l1 = singly_linked_list.SL_List()
  l2 = singly_linked_list.SL_List()
  l1.add_back(4)
  l1.add_back(7)
  l1.add_back(8)
  l2.add_back(0)
  l2.add_back(1)
  l2.add_back(5)
  l2.add_back(6)
  print sl_list_merge1(l1, l2)
