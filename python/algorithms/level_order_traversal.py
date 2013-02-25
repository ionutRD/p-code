#! /usr/bin/python
# Level order traversal of a given binary tree

import bst

def level_order_traversal(bt):
  if bt == None:
    return
  q = []
  q.append(bt.root)
  while len(q) > 0:
    crt_node = q.pop(0)
    print crt_node.key
    if crt_node.left != None:
      q.append(crt_node.left)
    if crt_node.right != None:
      q.append(crt_node.right)

if __name__ == "__main__":
  t = bst.BST()
  t.add(5)
  t.add(3)
  t.add(1)
  t.add(4)
  t.add(9)
  t.add(7)
  t.add(10)
  level_order_traversal(t)
