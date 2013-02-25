#! /usr/bin/python
# Convert a sorted array into a balanced binary tree

import bst

def array_to_bst(arr):
  if len(arr) == 1:
    return bst.BT_Node(arr[0])
  else:
    root = bst.BT_Node(arr[len(arr) / 2])
    root.left = array_to_bst(arr[:len(arr) / 2])
    root.right = array_to_bst(arr[len(arr) / 2 + 1:])
    return root

if __name__ == "__main__":
  print "Test1: arr = [2, 3, 4, 5, 7, 10, 11]"
  arr = [2, 3, 4, 5, 7, 10, 11]
  t = bst.BST()
  t.root = array_to_bst(arr)
  print "Inorder"
  t.inorder()
  print "Preorder"
  t.preorder()
