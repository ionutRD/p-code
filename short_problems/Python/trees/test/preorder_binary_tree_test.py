__author__ = 'Radu Ionut-Gabriel'

import unittest
from trees.nodes import BinaryTreeNode
from trees.preorder_binary_tree import preorder_v1, preorder_v2

class PreorderBinaryTreeTest(unittest.TestCase):
    def setUp(self):
        self.null_tree = None
        self.tree1 = BinaryTreeNode(1,
                                    BinaryTreeNode(2,
                                                   BinaryTreeNode(4),
                                                   BinaryTreeNode(5)),
                                    BinaryTreeNode(3,
                                                   None,
                                                   BinaryTreeNode(6)))
        self.list1 = [1, 2, 4, 5, 3, 6]

    def testNullTreeV1(self):
        for _, _ in zip([], preorder_v1(self.null_tree)):
            self.fail()

    def testTree1V1(self):
        for expected_data, data in zip(self.list1, preorder_v1(self.tree1)):
            self.assertEqual(expected_data, data)

    def testNullTreeV2(self):
        for _, _ in zip([], preorder_v2(self.null_tree)):
            self.fail()

    def testTree1V2(self):
        for expected_data, data in zip(self.list1, preorder_v2(self.tree1)):
            self.assertEqual(expected_data, data)
