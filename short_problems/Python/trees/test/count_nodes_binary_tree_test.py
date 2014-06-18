__author__ = 'Radu Ionut-Gabriel'

import unittest
from trees.count_nodes_binary_tree import count_nodes_v1
from trees.count_nodes_binary_tree import count_nodes_v2
from trees.count_nodes_binary_tree import count_nodes_v3
from trees.nodes import BinaryTreeNode


class CountNodesBinaryTreeTest(unittest.TestCase):
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
        tree_size = count_nodes_v1(self.null_tree)
        self.assertEqual(0, tree_size)

    def testTree1V1(self):
        tree_size = count_nodes_v1(self.tree1)
        self.assertEqual(6, tree_size)

    def testNullTreeV2(self):
        tree_size = count_nodes_v2(self.null_tree)
        self.assertEqual(0, tree_size)

    def testTree1V2(self):
        tree_size = count_nodes_v2(self.tree1)
        self.assertEqual(6, tree_size)

    def testNullTreeV3(self):
        tree_size = count_nodes_v3(self.null_tree)
        self.assertEqual(0, tree_size)

    def testTree1V3(self):
        tree_size = count_nodes_v3(self.tree1)
        self.assertEqual(6, tree_size)


if __name__ == '__main__':
    unittest.main()
