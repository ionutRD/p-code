__author__ = 'Radu Ionut-Gabriel'

import unittest
from lists.nodes import SinglyLinkedListNode
from lists.reverse_singly_linked_list import reverse_v1, reverse_v2

class ReverseSinglyLinkedListTest(unittest.TestCase):
    def setUp(self):
        self.null_list = None
        self.list1 = SinglyLinkedListNode(1, (SinglyLinkedListNode(2, SinglyLinkedListNode(3, SinglyLinkedListNode(4)))))
        self.exp_list1 = [4, 3, 2, 1]

    def testNullListV1(self):
        for _, _ in zip([], reverse_v1(self.null_list)):
            self.fail()

    def testList1V1(self):
        for expected_data, data in zip(self.exp_list1, reverse_v1(self.list1)):
            self.assertEqual(expected_data, data)

    def testList1V2(self):
        for expected_data, data in zip(self.exp_list1, reverse_v2(self.list1)):
            self.assertEqual(expected_data, data)
