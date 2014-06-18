"""
Find the kth element from the end of a singly linked list.
"""
__author__ = 'Radu Ionut-Gabriel'

def kth_v1(head, k):
    """
    @param head: the head of a singly linked list
    @param k: the position
    @return: the kth element from the end of a singly linked list
    """
    if k < 0:
        return None
    i = 0
    second_t = head
    while i < k and second_it:
        second_it = second_it.next
        i += 1
    if i < k:
        return None
    first_it = head
    while second_it:
        second_it = second_it.next
        first_it = first_it.next

    return first_it
