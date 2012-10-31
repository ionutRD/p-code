#! /usr/bin/python

import bst

def top_st(st):
  if len(st) > 0:
    return st[len(st) - 1]

def top_modify(st, t):
  if len(st) > 0:
    st[len(st) - 1] = t


def iter_postorder(bt):
  if bt == None:
    return
  st = []
  st.append((bt.root, False, False))
  while len(st) > 0:
    (node, left, right) = top_st(st)
    if left == False and node.left != None:
      top_modify(st, (node, True, False))
      st.append((node.left, False, False))
    elif left == False and node.right != None:
      top_modify(st, (node, True, True))
      st.append((node.right, False, False))
    elif left == False:
      node = st.pop()[0]
      print node.key
    elif left == True and right == False and node.right != None:
      top_modify(st, (node, True, True))
      st.append((node.right, False, False))
    elif left == True and right == False and node.right == None:
      node = st.pop()[0]
      print node.key
    elif left == True and right == True:
      node = st.pop()[0]
      print node.key

if __name__ == "__main__":
  t = bst.BST()
  t.add(5)
  t.add(3)
  t.add(2)
  t.add(4)
  t.add(10)
  t.add(7)
  t.add(11)
  iter_postorder(t)
