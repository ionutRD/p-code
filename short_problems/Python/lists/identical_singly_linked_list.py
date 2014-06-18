"""
Check whether two singly linked lists are identical
"""
__author__ = 'Radu Ionut-Gabriel'

def identical_v1(head1, head2):
    """
    @param head1: the first list head
    @param head2: the second list head
    @return: true if the lists are identical
    """
    if not head1 and not head2:
        return True
    if not head1 and head2:
        return False
    if head1 and not head2:
        return False
    if head1.data != head2.data:
        return False
    return identical_v1(head1.next, head2.next)

def identical_v2(head1, head2):
    """
    @param head1: the first list head
    @param head2: the second list head
    @return: true if the lists are identical
    """
    it1, it2 = head1, head2
    while True:
        if not it1 and not it2:
            return True
        if not it1 and it2:
            return False
        if it1 and not it2:
            return False
        if it1.data != it2.data:
            return False
        it1 = it1.next
        it2 = it2.next
