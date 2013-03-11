#! /usr/bin/python

class SL_Node:
  def __init__(self, key = None, next = None):
    self.key = key
    self.next = next

  def __str__(self):
    return str(self.key)

class SL_List:
  def __init__(self):
    self.front = self.back = None
    self.size = 0

  def __contains__(self, key):
    return self.find(key) != None

  def __len__(self):
    return self.size

  def add_front(self, key):
    """ Add an element in front of the list"""
    node = SL_Node(key)
    if self.size == 0:
      self.front = self.back = node
    else:
      node.next = self.front
      self.front = node
    self.size += 1

  def add_back(self, key):
    """ Add an element at the end of the list"""
    node = SL_Node(key)
    if self.size == 0:
      self.front = self.back = node
    else:
      self.back.next = node
      self.back = node
    self.size += 1

  def delete_front(self):
    """ Delete the first element """
    if (self.size != 0):
      self.front = self.front.next
      self.size -= 1

  def is_empty(self):
    """ Check if the list is empty """
    return self.size == 0

  def find(self, key, eq = lambda x,y : x==y):
    """ Find a specific node in O(n) """
    node = self.front
    while node != None:
      if eq(node.key, key) == True:
        return node
      node = node.next

  def __str__(self):
    node = self.front
    list_string = ''
    while node != None:
      list_string = list_string + str(node) + '->'
      node = node.next
    list_string = list_string + 'NIL'
    return list_string

if __name__ == "__main__":
  print "Test1: Add front"
  sl_list = SL_List()
  for i in range(10):
    sl_list.add_front(i)
  print str(sl_list)

  print "Test2: Add back"
  sl_list = SL_List()
  for i in range(10):
    sl_list.add_back(i)
  print str(sl_list)

  print "Test3: Delete front I"
  for i in range(5):
    sl_list.delete_front()
  print str(sl_list)

  print "Test4: Delete front II"
  for i in range(6):
    sl_list.delete_front()
  print str(sl_list)

  print "Test5: Is Empty"
  print sl_list.is_empty()

  print "Test6: Find & is empty"
  sl_list = SL_List()
  for i in range(10):
    sl_list.add_back(i)
  print str(sl_list.find(5))
  print sl_list.find(20)
  print sl_list.is_empty()
  print 5 in sl_list

