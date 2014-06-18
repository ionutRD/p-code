__author__ = 'Radu Ionut-Gabriel'

import unittest
from lists.nodes import SinglyLinkedListNode
from lists.mid_singly_linked_list import mid_v1

class MidSinglyLinkedListTest(unittest.TestCase):
    def setUp(self):
        self.nullList = None
        self.list1 = SinglyLinkedListNode(1)
        self.list2 = SinglyLinkedListNode(1, SinglyLinkedListNode(3))
        self.list3 = SinglyLinkedListNode(1, (SinglyLinkedListNode(2, SinglyLinkedListNode(3, SinglyLinkedListNode(4)))))
        self.list4 = SinglyLinkedListNode(1, (SinglyLinkedListNode(2, SinglyLinkedListNode(3))))

    def testNullListV1(self):
        self.assertFalse(mid_v1(self.nullList))

    def testList1V1(self):
        self.assertEqual(mid_v1(self.list1).data, 1)

    def testList2V1(self):
        self.assertEqual(mid_v1(self.list2).data, 3)

    def testList3V1(self):
        self.assertEqual(mid_v1(self.list3).data, 3)

    def testList4V1(self):
        self.assertEqual(mid_v1(self.list4).data, 2)