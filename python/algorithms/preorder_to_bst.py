#! /usr/bin/python
# Construct a binary tree given the preorder traversal

import bst

def top(st):
  if len(st) > 0:
    return st[len(st) - 1]

def preorder_to_bst(arr):
  st = []
  t = bst.BST()
  t.add(arr[0])
  st.append(t.root)
  n = len(arr)
  for i in range(1, n):
    new_node = bst.BT_Node(arr[i])
    if arr[i] < top(st).key:
      top(st).left = new_node
      st.append(new_node)
    else:
      while len(st) > 0:
        old = st.pop()
        if (len(st) == 0) or (len(st) > 0 and arr[i] < top(st).key):
          old.right = new_node
          st.append(new_node)
          break
  return t

if __name__ == "__main__":
  print "Test1: arr = [5, 3, 2, 4, 10, 7, 11]"
  arr = [5, 3, 2, 4, 10, 7, 11]
  t = preorder_to_bst(arr)
  print "Inorder"
  t.inorder()
  print "Preorder"
  t.preorder()
  print "Postorder"
  t.postorder()
