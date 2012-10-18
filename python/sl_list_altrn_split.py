#! /usr/bin/python

import singly_linked_list

def sl_altrn_split(l):
  """ Split the original list into two lists:                    """
  """ The first contains the nodes on even positions             """
  """ and the second contains the nodes on odd positions         """
  """ The time complexity is O(n) where n is the number of nodes """
  """ There is only one traversal and the                        """
  node = l.front
  alt = 0
  l1 = singly_linked_list.SL_List()
  l2 = singly_linked_list.SL_List()
  while node != None:
    if alt == 0:
      l1.add_back(node.key)
    else:
      l2.add_back(node.key)
    node = node.next
    alt = 1 - alt
  return (l1, l2)

if __name__ == "__main__":
  print "Test1: l=0->1->2->3->4"
  l = singly_linked_list.SL_List()
  for i in range(5):
    l.add_back(i)
  lists = sl_altrn_split(l)
  print lists[0]
  print lists[1]

  print "Test2: l=0->1"
  l = singly_linked_list.SL_List()
  for i in range(2):
    l.add_back(i)
  lists = sl_altrn_split(l)
  print lists[0]
  print lists[1]

  print "Test3: l=0"
  l = singly_linked_list.SL_List()
  for i in range(1):
    l.add_back(i)
  lists = sl_altrn_split(l)
  print lists[0]
  print lists[1]
  
  print "Test4: l=NIL"
  l = singly_linked_list.SL_List()
  lists = sl_altrn_split(l)
  print lists[0]
  print lists[1]
