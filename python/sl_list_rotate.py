#! /usr/bin/python

import singly_linked_list

def sl_rotate_list_ck(sl_list, rot):
  """ Rotate a singly linked list counter clockwise        """
  """ For 1->2->3->4->5->6 and rot = 2 => 3->4->5->6->1->2 """
  """ Assum rot less than the list length                  """
  if rot != 0:
    i = 0
    node = sl_list.front
    old_first = node
    for i in range(rot):
      node = node.next

    new_first = node.next
    node.next = None
    if  new_first != None:
      p = new_first
      while p.next != None:
        p = p.next
      p.next = old_first
      sl_list.front = new_first

if __name__ == "__main__":
  sl_list = singly_linked_list.SL_List()
  for i in range(7):
    sl_list.add_back(i)
  sl_rotate_list_ck(sl_list, 2)
  print sl_list

  sl_list = singly_linked_list.SL_List()
  for i in range(7):
    sl_list.add_back(i)
  sl_rotate_list_ck(sl_list, 4)
  print sl_list


