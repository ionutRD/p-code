#! /usr/bin/python

import singly_linked_list

def merge(l1, l2):
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

def halve(l):
  a = singly_linked_list.SL_List()
  b = singly_linked_list.SL_List()
  node = l.front
  for i in range (len(l) / 2):
    a.add_back(node.key)
    node = node.next

  for i in range(len(l) / 2, len(l)):
    b.add_back(node.key)
    node = node.next

  return (a,b)

def merge_sort(l):
  """ Mergesort for two lists """
  if l.front != None and l.front.next == None:
    return l
  (a,b) = halve(l)
  a = merge_sort(a)
  b = merge_sort(b)
  return merge(a, b)

if __name__ == "__main__":
  print "Test1: Test half wih l=0->1->2->3->4->5->6->7->8->9->10"
  l = singly_linked_list.SL_List()
  for i in range(10):
    l.add_back(i)
  (a,b) = halve(l)
  print a
  print b
  print "Test2: Test half wih l=0->1->2->3->4->5->6->7->8->9"
  l = singly_linked_list.SL_List()
  for i in range(9):
    l.add_back(i)
  (a,b) = halve(l)
  print a
  print b
  print "Test3: Test half wih l=0->1"
  l = singly_linked_list.SL_List()
  for i in range(2):
    l.add_back(i)
  (a,b) = halve(l)
  print a
  print b
  print "Test4: Mergesort with l=7->1->4->2->3->10->8"
  l = singly_linked_list.SL_List()
  l.add_back(7)
  l.add_back(1)
  l.add_back(4)
  l.add_back(2)
  l.add_back(3)
  l.add_back(10)
  l.add_back(8)
  print merge_sort(l)

