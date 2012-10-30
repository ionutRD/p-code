#! /usr/bin/python
# Perform a zigzag traversal on binary trees

import bst

def inspect_front(dq):
  if len(dq) > 0:
    return dq[0][1]

def inspect_back(dq):
  if len(dq) > 0:
    return dq[len(dq) - 1][1]

def zigzag_traversal(bt):
  if bt == None:
    return
  dq = []
  h = 0
  reverse = False
  dq.append((bt.root, h))
  while len(dq) > 0:
    if (reverse == False):
      insp_h = inspect_back(dq)
      if (insp_h == h):
        nd = dq.pop()[0]
        print nd.key
        if nd.left != None:
          dq.append((nd.left, h + 1))
        if nd.right != None:
          dq.append((nd.right, h + 1))
      else:
        h += 1
        reverse = True
    else:
        insp_h = inspect_front(dq)
        if (insp_h == h):
          nd = dq.pop(0)[0]
          print nd.key
          if nd.left != None:
            dq.append((nd.left, h + 1))
          if nd.right != None:
            dq.append((nd.right, h + 1))
        else:
          h += 1
          reverse = False

if __name__ == "__main__":
  t = bst.BST()
  t.add(5)
  t.add(3)
  t.add(2)
  t.add(4)
  t.add(10)
  t.add(7)
  t.add(11)
  zigzag_traversal(t)
