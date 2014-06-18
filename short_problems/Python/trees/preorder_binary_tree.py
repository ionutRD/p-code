"""
Functions for preorder traversal of a binary tree.
"""
__author__ = 'Radu Ionut-Gabriel'


def preorder_v1(root):
    """
    @param root: the root of the binary tree
    """
    if root:
        yield root.data
        yield from preorder_v1(root.left)
        yield from preorder_v1(root.right)


def preorder_v2(root):
    """
    @param root: the root of the binary tree
    """
    if not root:
        yield
    nodes_stack = [root]
    while nodes_stack:
        crt_node = nodes_stack.pop()
        yield crt_node.data
        if crt_node.right:
            nodes_stack.append(crt_node.right)
        if crt_node.left:
            nodes_stack.append(crt_node.left)
