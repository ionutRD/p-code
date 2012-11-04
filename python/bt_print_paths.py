#! /usr/bin/python
# Print all paths in a binary tree

import bst

def bt_print_paths(node):
  if node.left == None and node.right == None:
    return [[node.key]]
  else:
    crt_path = []
    if node.left != None:
      left_paths = bt_print_paths(node.left)
      for path in left_paths:
        path.append(node.key)
        crt_path.append(path)
    if node.right != None:
      right_paths = bt_print_paths(node.right)
      for path in right_paths:
        path.append(node.key)
        crt_path.append(path)
    return crt_path

if __name__ == "__main__":
  t = bst.BST()
  t.add(5)
  t.add(3)
  t.add(2)
  t.add(4)
  t.add(10)
  t.add(7)
  t.add(11)
  paths = bt_print_paths(t.root)
  for path in paths:
    print path

