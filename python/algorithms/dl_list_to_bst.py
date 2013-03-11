#! /usr/bin/python
# Convert a doubly linked list into a bst

import doubly_linked_list

def dl_to_bst(node, n):
  if n <= 0:
    return (None, node)
  (left, new_node) = dl_to_bst(node, n / 2)
  root = new_node
  root.prev = left
  new_node = new_node.next
  (root.next, new_node) = dl_to_bst(new_node, n - n / 2 - 1)
  return (root, new_node)

def inorder(node):
  if node != None:
    inorder(node.prev)
    print node.key
    inorder(node.next)

def preorder(node):
  if node != None:
    print node.key
    preorder(node.prev)
    preorder(node.next)

if __name__ == "__main__":
  dl = doubly_linked_list.DL_List()
  for i in range(10):
    dl.add_back(i)
  (root, new_node) = dl_to_bst(dl.front, dl.size)
  print "Inorder"
  inorder(root)
  print "Preorder"
  preorder(root)


