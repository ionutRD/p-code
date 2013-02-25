#! /usr/bin/python

import singly_linked_list

def sl_linked_intersect(l1, l2):
  """ Intersection of two unsorted singly linked list in O(N) where  """
  """ N is max(len(l1), len(l2)) and O(m + n) space complexity where """
  """ m is len(l1) and m is len(m2)                                  """
  node1 = l1.front
  node2 = l2.front
  hm = dict()
  # Iterate both list simultaneously until one (possibly both) list
  # reach the end.
  while node1 != None and node2 != None:
    if node1.key not in hm:
      hm[node1.key] = 1
    else:
      hm[node1.key] += 1
    if node2.key not in hm:
      hm[node2.key] = 2
    else:
      hm[node2.key] += 2
    node1 = node1.next
    node2 = node2.next

  # Iterate the rest of the bigger list (if applicable)
  which = 0
  if node1 != None:
    node = node1
    which = 1
  elif node2 != None:
    node = node2
    which = 2
  else:
    node = None
  while node != None:
    if node.key not in hm:
      hm[node.key] = which
    else:
      hm[node.key] += which
    node = node.next

  # Create the intersection list
  l = singly_linked_list.SL_List()
  for key in hm:
    if hm[key] == 3:
      l.add_back(key)

  return l

if __name__ == "__main__":
  print "Test1: l1 = 1->3->2 and l2 = 4->3"
  l1 = singly_linked_list.SL_List()
  l1.add_back(1)
  l1.add_back(3)
  l1.add_back(2)
  l2 = singly_linked_list.SL_List()
  l2.add_back(4)
  l2.add_back(3)
  l = sl_linked_intersect(l1, l2)
  print l

  print "Test2: l1 = 1->2->3->4->5->6->7 and l2 = 4->3->2->10"
  l1 = singly_linked_list.SL_List()
  for i in range(8):
    l1.add_back(i)
  l2 = singly_linked_list.SL_List()
  for i in range(4, 1, -1):
    l2.add_back(i)
  l2.add_back(10)
  l = sl_linked_intersect(l1, l2)
  print l



