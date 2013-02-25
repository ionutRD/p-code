#! /usr/bin/python
# Convert a binary search tree into a doubly linked list in place

import bst

def bst_to_dl(cnode, pnode):
  if cnode.left == None and cnode.right and pnode == None:
    return cnode
  elif cnode.left == None and cnode.right == None and pnode != None:
    pnode.right = cnode
    cnode.left = pnode
    return cnode
  else:
    if cnode.left != None:
      lnode = bst_to_dl(cnode.left,pnode)
      lnode.right = cnode
      cnode.left = lnode
    else:
      cnode.left = None
    if cnode.right != None:
      rnode = bst_to_dl(cnode.right, cnode)
      return rnode
    else:
      return cnode

if __name__ == "__main__":
  t = bst.BST()
  t.add(5)
  t.add(3)
  t.add(2)
  t.add(4)
  t.add(10)
  t.add(11)
  t.add(7)
  node = bst_to_dl(t.root, None)
  while node.left != None:
    node = node.left
  start = node
  str_repr = "NIL<->"
  while start != None:
    str_repr += str(start.key) + "<->"
    start = start.right
  str_repr += "NIL"
  print str_repr
