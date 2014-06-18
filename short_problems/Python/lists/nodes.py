__author__ = 'Radu Ionut-Gabriel'

class SinglyLinkedListNode:
    def __init__(self, data, next=None):
        """
        @param data: the node's data
        @param next: the node's next element
        """
        self.data, self.next = data, next

class DoublyLinkedListNode:
    def __init__(self, data, next=None, prev=None):
        """
        @param data: the node's data
        @param next: the node's next element
        @param prev: the nodes' previous element
        """
        self.data, self.next, self.prev = data, next, prev
