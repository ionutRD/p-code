__author__ = 'Radu Ionut-Gabriel'


class BinaryTreeNode:
    def __init__(self, data, left=None, right=None):
        """
        @param data: the node's data
        @param left: the node's left child
        @param right: the node's right child
        """
        self.data, self.left, self.right = data, left, right

