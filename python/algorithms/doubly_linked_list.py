#! /usr/bin/python
# Doubly linked list

class DL_Node:
  def __init__(self, key = None, next = None, prev = None):
    self.key = key
    self.next = next
    self.prev = prev
  
  def __str__(self):
    return str(self.key)

class DL_List:
  def __init__(self):
    self.front = self.back = None
    self.size = 0

  def __len__(self):
    return self.size

  def add_front(self, key):
    new_node = DL_Node(key)
    if self.size == 0:
      self.front = self.back = new_node
    else:
      new_node.next = self.front
      self.front.prev = new_node
      self.front = new_node
    self.size += 1

  def add_back(self, key):
    new_node = DL_Node(key)
    if self.size == 0:
      self.front = self.back = new_node
    else:
      new_node = DL_Node(key, None, None)
      self.back.next = new_node
      new_node.prev = self.back
      self.back = new_node
    self.size += 1

  def del_front(self):
    if self.size > 0:
      self.front = self.front.next
      if self.size > 1:
        self.front.prev = None
      if self.size == 1:
        self.back = self.front
      self.size -= 1

  def del_back(self):
    if self.size > 0:
      self.back = self.back.prev
      if self.size > 1:
        self.back.next = None
      if self.size == 1:
        self.front = self.back
      self.size -= 1

  def is_empty(self):
    return self.size == 0

  def find(self, key):
    if self.size > 0:
      iter_node = self.front
      while iter_node != None:
        if iter_node.key == key:
          return iter_node
        iter_node = iter_node.next

  def __str__(self):
    iter_node = self.front
    dlist_string = 'NIL<->'
    while iter_node != None:
      dlist_string += str(iter_node) + '<->'
      iter_node = iter_node.next
    dlist_string = dlist_string + 'NIL'
    return dlist_string

if __name__ == "__main__":
  print "Test1: Add front"
  dl_list = DL_List()
  for i in range(10):
    dl_list.add_front(i)
  print dl_list
  print "Test2: Add front"
  dl_list = DL_List()
  for i in range(10):
    dl_list.add_back(i)
  print dl_list
  dl_list.del_back()
  dl_list.del_back()
  dl_list.del_back()
  print dl_list
  dl_list.del_front()
  dl_list.del_front()
  print dl_list
  print dl_list.find(3).key
  print dl_list.find(4)
  print dl_list.find(10)
  dl_list.del_front()
  dl_list.del_front()
  print dl_list
  dl_list.del_back()
  dl_list.del_back()
  print dl_list
  dl_list.del_back()
  print dl_list
  print dl_list.is_empty()

