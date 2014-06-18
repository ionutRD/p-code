__author__ = 'Radu Ionut-Gabriel'

import unittest
from trees.nodes import BinaryTreeNode
from trees.level_order_binary_tree import level_order_v1

class LevelOrderBinaryTreeTest(unittest.TestCase):
    def setUp(self):
        self.null_tree = None
        self.tree1 = BinaryTreeNode(1,
                        BinaryTreeNode(2,
                            BinaryTreeNode(4),
                            BinaryTreeNode(5)),
                        BinaryTreeNode(3,
                            None,
                            BinaryTreeNode(6)))
        self.list1 = [1, 2, 3, 4, 5, 6]

    def testNullTreeV1(self):
        for _, _ in zip([], level_order_v1(self.null_tree)):
            self.fail()

    def testTree1V1(self):
        for expected_data, data in zip(self.list1, level_order_v1(self.tree1)):
            self.assertEqual(expected_data, data)
