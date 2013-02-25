#! /usr/bin/python
# Double each node in a binary tree by creating a duplicate left child
#
#   2
#  / \
# 1   3
# would become
#           2
#          / \
#         2   3
#       /    /
#      1    3
#     /
#    1

import bst

def bt_duplicate(node):
  if node == None:
    return

  # do for left and right subtree
  bt_duplicate(node.left)
  bt_duplicate(node.right)
  
  # duplicate this node to itself
  new_node = bst.BT_Node(node.key)
  old_left = node.left
  node.left = new_node
  node.left.left = old_left

if __name__ == "__main__":
  t = bst.BST()
  t.add(5)
  t.add(3)
  t.add(2)
  t.add(4)
  t.add(10)
  t.add(7)
  t.add(11)
  bt_duplicate(t.root)
  print "Inorder"
  t.inorder()
  print "Preorder"
  t.preorder()
  print "Postorder"
  t.postorder()
