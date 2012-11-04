#! /usr/bin/python
# Find the maximum sum from leaf to root in a binary tree

import random_binary_tree
import random
import bst

def find_max_path_to_leaf(node):
  if node.left == None and node.right == None:
    return node.key
  sumleft = float("-inf")
  sumright = float("-inf")
  if node.left != None:
    sumleft = find_max_path_to_leaf(node.left)
  if node.right != None:
    sumright = find_max_path_to_leaf(node.right)
  return node.key + max(sumleft, sumright)

if __name__ == "__main__":
  rbt = random_binary_tree.RBT()
  arr = [1, -6, 2, -4, 8, 10, -11, 0]
  random.shuffle(arr)
  for i in arr:
    rbt.add(i)
  print "Inorder"
  rbt.inorder()
  print "Preorder"
  rbt.preorder()
  print "Max sum is:"
  print find_max_path_to_leaf(rbt.root)
  t = bst.BST()
  t.add(5)
  t.add(3)
  t.add(2)
  t.add(4)
  t.add(10)
  t.add(7)
  t.add(11)
  print "Max sum is:"
  print find_max_path_to_leaf(t.root)
