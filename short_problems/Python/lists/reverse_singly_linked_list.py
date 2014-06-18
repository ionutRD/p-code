"""
Reverse a singly linked list.
"""
__author__ = 'Radu Ionut-Gabriel'

def reverse_v1(head):
    """
    @param head: the list head
    """
    if head:
        yield from reverse_v1(head.next)
        yield head.data

def reverse_v2(head):
    """
    @param head: the list head
    """
    if not head:
        yield
    prev_node = None
    crt_node = head
    while crt_node:
        tmp = crt_node.next
        crt_node.next = prev_node
        crt_node = tmp
    while prev_node:
        yield prev_node
        prev_node = prev_node.next
