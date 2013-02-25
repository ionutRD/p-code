#! /usr/bin/python
# Convert level order traversal into binary search tree

import bst

def top(q):
  if len(q) > 0:
    return q[0]

def level_order_to_bst(arr):
  q = []
  t = bst.BST()
  t.add(arr[0])
  q.append((t.root, float("-inf"), float("inf")))
  n = len(arr)
  for i in range(1, n):
    new_node = bst.BT_Node(arr[i])
    last = top(q)
    if arr[i] < last[0].key and arr[i] > last[1] and arr[i] < last[2]:
      last[0].left = new_node
      q.append((new_node, last[1], last[0].key)
    elif (arr[i] > last[0].key) and (arr[i] > last[1]) and (arr[i] < last[2]):
      last[0].right = new_node
      old = last[0]
      MIN = last[1]
      MAX = last[2]
      q.pop(0)
      q.append((new_node, old.key, MAX))

  return t

if __name__ == "__main__":
  print "Test1: arr = [5, 3, 10, 2, 7, 11]"
  arr = [5, 3, 10, 2, 7, 11]
  t = level_order_to_bst(arr)
  print "Inorder traversal"
  t.inorder()


