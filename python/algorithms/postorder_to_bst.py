#! /usr/bin/python
# Convert a postorder traversal to a binary search tree

import bst

def top(st):
  if len(st) > 0:
    return st[len(st) - 1]

def postorder_to_bst(arr):
  st = []
  t = bst.BST()
  t.add(arr[len(arr) - 1])
  st.append(t.root)
  n = len(arr)
  for i in range(n - 2, -1, -1):
    new_node = bst.BT_Node(arr[i])
    if arr[i] > top(st).key:
      top(st).right = new_node
      st.append(new_node)
    else:
      while len(st) > 0:
        old = st.pop()
        if (len(st) == 0) or (len(st) > 0 and arr[i] > top(st).key):
          old.left = new_node
          st.append(new_node)
          break
  return  t

if __name__ == "__main__":
  print "Test1: arr = [2 4 3 7 11 10 5]"
  arr = [2, 4, 3, 7, 11, 10, 5]
  t = postorder_to_bst(arr)
  t.inorder()
