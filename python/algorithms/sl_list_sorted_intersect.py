#! /usr/bin/python

import singly_linked_list

def sl_list_sorted_intersect(l1, l2):
  """ Intersect two sorted singly linked list in O(n) time complexity """
  """ where n is min(len(l1), len(l2))                                """
  node1 = l1.front
  node2 = l2.front
  l = singly_linked_list.SL_List()
  while node1 != None and node2 != None:
    if node1.key == node2.key:
      l.add_back(node1.key)
      node1 = node1.next
      node2 = node2.next
    elif node1.key < node2.key:
      node1 = node1.next
    else:
      node2 = node2.next
  return l

if __name__ == "__main__":
  print "Test1: l1 = 1->7->8->10, l2 = 2->3->5->7->10->11"
  l1 = singly_linked_list.SL_List()
  l2 = singly_linked_list.SL_List()
  l1.add_back(1)
  l1.add_back(7)
  l1.add_back(8)
  l1.add_back(10)
  l2.add_back(2)
  l2.add_back(3)
  l2.add_back(5)
  l2.add_back(7)
  l2.add_back(10)
  l2.add_back(11)
  print sl_list_sorted_intersect(l1, l2)

