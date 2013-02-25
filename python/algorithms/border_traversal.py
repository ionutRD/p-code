#! /usr/bin/python
# Perform border traversal for binary trees

import bst

def traverse_left_border(node):
  if node != None:
    if node.left != None or node.right != None:
      print node.key
    if node.left != None:
      traverse_left_border(node.left)
    elif node.right != None:
      traverse_left_border(node.right)

def traverse_right_border(node):
  if node != None:
    if node.right != None:
      traverse_right_border(node.right)
    elif node.left != None:
      traverse_right_border(node.left)
    if node.left != None or node.right != None:
      print node.key

def traverse_leaves(node):
  if node.left == None and node.right == None:
    print node.key
  else:
    if node.left != None:
      traverse_leaves(node.left)
    if node.right != None:
      traverse_leaves(node.right)

def border_traverse(bt):
  if bt != None:
    traverse_left_border(bt.root)
    traverse_leaves(bt.root)
    traverse_right_border(bt.root)

if __name__ == "__main__":
  t = bst.BST()
  t.add(5)
  t.add(2)
  t.add(1)
  t.add(3)
  t.add(10)
  t.add(7)
  t.add(11)
  border_traverse(t)
