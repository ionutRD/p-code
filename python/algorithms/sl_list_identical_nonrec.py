#! /usr/bin/python

import singly_linked_list

def sl_list_id_nonrec(l1, l2):
  """ Check if two singly linked list are identical """
  node1 = l1.front
  node2 = l2.front

  while node1 != None and node2 != None:
    if node1.key != node2.key:
      return False
    node1 = node1.next
    node2 = node2.next

  if node1 != None or node2 != None:
    return False
  return True

if __name__ == "__main__":
  print "Test1: l1 = 1->2->3 and l2 = 1->2->3"
  l1 = singly_linked_list.SL_List()
  l2 = singly_linked_list.SL_List()
  for i in range(3):
    l1.add_back(i + 1)
    l2.add_back(i + 1)

  print sl_list_id_nonrec(l1, l2)

  print "Test2: l1 = 1->3->2 and l2 = 1->2->3"
  l1 = singly_linked_list.SL_List()
  l2 = singly_linked_list.SL_List()
  for i in range(3):
    l2.add_back(i + 1)
  l1.add_back(1)
  l1.add_back(3)
  l1.add_back(2)
  print sl_list_id_nonrec(l1, l2)

  print "Test3: l1 = 1 and l2 = 1->2->3"
  for i in range(3):
    l2.add_back(i + 1)
  l1.add_back(1)
  print sl_list_id_nonrec(l1, l2)
