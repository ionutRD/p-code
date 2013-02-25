#! /usr/bin/python
# Binary search tree

class BT_Node:
  def __init__(self, key, left = None, right = None):
    self.key = key
    self.left = left
    self.right = right

class BST:
  def __init__(self, comp = lambda x, y: x - y):
    self.root = None
    self.comp = comp

  def _addrec(self, root, key):
    if root == None:
      root = BT_Node(key)
    elif key < root.key:
      root.left = self._addrec(root.left, key)
    else:
      root.right = self._addrec(root.right, key)
    return root
  
  def add(self, key):
    self.root = self._addrec(self.root, key)

  def _height(self, node):
    if node == None:
      return 0
    else:
      return 1 + max(self._height(node.left), self._height(node.right))

  def height(self):
    return self._height(self.root)

  def _inorder(self, node):
    if node != None:
      self._inorder(node.left)
      print node.key
      self._inorder(node.right)

  def inorder(self):
    self._inorder(self.root)

  def inorder_nonrec(self):
    s = []
    node = self.root
    s.append(node)
    while len(s) > 0:
      if node.left != None:
        node = node.left
        s.append(node)
      else:
        print node.key
        if len(s) > 0:
          node = s.pop()
          while node.right == None and len(s) > 0:
            node = s.pop()
            print node.key
          if node.right != None:
            node = node.right
            s.append(node)

  def _preorder(self, node):
    if node != None:
      print node.key
      self._preorder(node.left)
      self._preorder(node.right)

  def preorder(self):
    self._preorder(self.root)

  def preorder_nonrec(self):
    s = []
    s.append(self.root)

    while len(s) > 0:
      node = s.pop()
      print node.key
      if node.right != None:
        s.append(node.right)
      if node.left != None:
        s.append(node.left)

  def _postorder(self, node):
    if node != None:
      self._postorder(node.left)
      self._postorder(node.right)
      print node.key

  def postorder(self):
    self._postorder(self.root)


if __name__ == "__main__":
  bst = BST()
  bst.add(5)
  bst.add(10)
  bst.add(3)
  bst.add(2)
  bst.add(4)
  bst.add(7)
  bst.add(11)
  print "Inorder traversal"
  bst.inorder()
  print "Inorder nonrec"
  bst.inorder_nonrec()
  print "Preorder traversal"
  bst.preorder()
  print "Preorder nonrec"
  bst.preorder_nonrec()
  print "Postorder traversal"
  bst.postorder()
  print "Height"
  print bst.height()

