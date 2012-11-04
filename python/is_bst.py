#! /usr/bin/python
# Check if a tree is bst

import bst
import random_binary_tree

def is_bst(node, MIN, MAX):
  if node != None:
    if node.key > MIN and node. key < MAX:
      return is_bst(node.left, MIN, node.key) and is_bst(node.right, node.key, MAX)
    else:
      return False
  else:
    return True

if __name__ == "__main__":
  t1 = bst.BST()
  t1.add(5)
  t1.add(3)
  t1.add(2)
  t1.add(4)
  t1.add(10)
  t1.add(7)
  t1.add(11)
  print is_bst(t1.root, float("-inf"), float("inf"))
  t2 = random_binary_tree.RBT()
  for i in range(10):
    t2.add(i)
  print is_bst(t2.root, float("-inf"), float("inf"))
