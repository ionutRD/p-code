#! /usr/bin/python
# Construct a random binary tree

import bst
import random

class RBT:
  def __init__(self):
    self.root = None

  def _add(self, node, key):
    if node == None:
      node = bst.BT_Node(key)
    else:
      rnd = random.randint(0, 1)
      if rnd == 0:
        node.left = self._add(node.left, key)
      else:
        node.right = self._add(node.right, key)
    return node

  def add(self, key):
    self.root = self._add(self.root, key)

  def _inorder(self, node):
    if node != None:
      self._inorder(node.left)
      print node.key
      self._inorder(node.right)

  def _preorder(self, node):
    if node != None:
      print node.key
      self._preorder(node.left)
      self._preorder(node.right)

  def inorder(self):
    self._inorder(self.root)

  def preorder(self):
    self._preorder(self.root)

if __name__ == "__main__":
  rbt = RBT()
  for i in range(10):
    rbt.add(i)

  print "Inorder"
  rbt.inorder()

  print "Preorder"
  rbt.preorder()
