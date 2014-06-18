"""
Functions for inorder traversal of a binary tree.
"""
__author__ = 'Radu Ionut-Gabriel'


def inorder_v1(root):
    """
    @param root: the binary tree root
    """
    if root:
        yield from inorder_v1(root.left)
        yield root.data
        yield from inorder_v1(root.right)


def inorder_v2(root):
    """
    @param root: the binary tree root
    """
    if not root:
        yield
    nodes_stack = []
    crt_node = root
    while nodes_stack or crt_node:
        if crt_node:
            nodes_stack.append(crt_node)
            crt_node = crt_node.left
        else:
            crt_node = nodes_stack.pop()
            yield crt_node.data
            crt_node = crt_node.right