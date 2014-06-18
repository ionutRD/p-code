__author__ = 'Radu Ionut-Gabriel'

import unittest
from lists.nodes import SinglyLinkedListNode
from lists.identical_singly_linked_list import identical_v1, identical_v2

class IdenticalSinglyLinkedListTest(unittest.TestCase):
    def setUp(self):
        self.list1 = SinglyLinkedListNode(1, (SinglyLinkedListNode(2, SinglyLinkedListNode(3, SinglyLinkedListNode(4)))))
        self.list2 = SinglyLinkedListNode(1, (SinglyLinkedListNode(2, SinglyLinkedListNode(3, SinglyLinkedListNode(4)))))

    def testIdenticalV1(self):
        self.assertTrue(identical_v1(self.list1, self.list2))

    def testIdenticalV2(self):
        self.assertTrue(identical_v2(self.list1, self.list2))