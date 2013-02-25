#! /usr/bin/python
# Check whether a given binary tree is complete or not

import bst

def is_complete(bt):
  if bt.root == None:
    return True
  queue = []
  queue.append(bt.root)
  while len(queue) > 0:
    crt_node = queue.pop(0)
    if crt_node.left != None and crt_node.right == None:
      return False
    elif crt_node.left == None and crt_node.right != None:
      return False
    elif crt_node.left != None and crt_node.right != None:
      queue.append(crt_node.left)
      queue.append(crt_node.right)

  return True

if __name__ == "__main__":
  t = bst.BST()
  t.add(5)
  t.add(2)
  t.add(9)
  t.add(0)
  t.add(4)
  t.add(7)
  t.add(17)
  print is_complete(t)
  t = bst.BST()
  t.add(5)
  t.add(2)
  t.add(9)
  t.add(0)
  t.add(4)
  t.add(7)
  print is_complete(t)

