#! /usr/bin/python
# Mirror a binary tree

import bst

def bt_mirror(node):
  if node == None:
    return
  bt_mirror(node.left)
  bt_mirror(node.right)
  (node.right, node.left) = (node.left, node.right)

if __name__ == "__main__":
  t = bst.BST()
  t.add(5)
  t.add(3)
  t.add(2)
  t.add(4)
  t.add(10)
  t.add(7)
  t.add(11)
  bt_mirror(t.root)
  print "Inorder"
  t.inorder()
  print "Preorder"
  t.preorder()
  print "Postorder"
  t.postorder()
