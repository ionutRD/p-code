__author__ = 'Radu Ionut-Gabriel'

import unittest
from trees.nodes import BinaryTreeNode
from trees.height_binary_tree import height_v1, height_v2


class HeightBinaryTreeTest(unittest.TestCase):
    def setUp(self):
        self.null_tree = None
        self.tree1 = BinaryTreeNode(1,
                                    BinaryTreeNode(2,
                                                   BinaryTreeNode(4),
                                                   BinaryTreeNode(5)),
                                    BinaryTreeNode(3,
                                                   None,
                                                   BinaryTreeNode(6)))

    def testNullTreeV1(self):
        height = height_v1(self.null_tree)
        self.assertEqual(0, height)

    def testTree1V1(self):
        height = height_v1(self.tree1)
        self.assertEqual(3, height)

    def testNullTreeV2(self):
        height = height_v2(self.null_tree)
        self.assertEqual(0, height)

    def testTree1V2(self):
        height = height_v2(self.tree1)
        self.assertEqual(3, height)

