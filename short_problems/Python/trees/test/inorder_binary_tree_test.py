__author__ = 'Radu Ionut-Gabriel'

import unittest
from trees.nodes import BinaryTreeNode
from trees.inorder_binary_tree import inorder_v1, inorder_v2


class InorderBinaryTreeTest(unittest.TestCase):
    def setUp(self):
        self.null_tree = None
        self.tree1 = BinaryTreeNode(1,
                                    BinaryTreeNode(2,
                                                   BinaryTreeNode(4),
                                                   BinaryTreeNode(5)),
                                    BinaryTreeNode(3,
                                                   None,
                                                   BinaryTreeNode(6)))
        self.list1 = [4, 2, 5, 1, 3, 6]

    def testNullTreeV1(self):
        for _, _ in zip([], inorder_v1(self.null_tree)):
            self.fail()

    def testTree1TreeV1(self):
        for expected_data, data in zip(self.list1, inorder_v1(self.tree1)):
            self.assertEqual(expected_data, data)

    def testNullTreeV2(self):
        for _, _ in zip([], inorder_v2(self.null_tree)):
            self.fail()

    def testTree1TreeV2(self):
        for expected_data, data in zip(self.list1, inorder_v2(self.tree1)):
            self.assertEqual(expected_data, data)