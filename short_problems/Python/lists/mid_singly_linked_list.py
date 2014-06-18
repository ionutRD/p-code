"""
Find the mid element in a singly linked list.
"""
__author__ = 'Radu Ionut-Gabriel'

def mid_v1(head):
    """
    @param head: the list head
    @return: the mid element of the list
    """
    if not head:
        return None
    fast_it, slow_it = head, head
    while fast_it and fast_it.next:
        slow_it = slow_it.next
        fast_it = fast_it.next.next
    return slow_it
