"""
Functions for calculating the height of a binary tree.
"""
__author__ = 'Radu Ionut-Gabriel'


def height_v1(root):
    """
    @param root: the binary tree root
    @return: the height of the binary tree
    """
    if not root:
        return 0
    return 1 + max(height_v1(root.left), height_v1(root.right))


def height_v2(root):
    """
    @param root: the binary tree root
    @return: the height of the binary tree
    """
    if not root:
        return 0
    nodes_and_levels_stack = [(root, 1)]
    height = 0
    while nodes_and_levels_stack:
        crt_node, crt_level = nodes_and_levels_stack.pop()
        height = max(height, crt_level)
        if crt_node.left:
            nodes_and_levels_stack.append((crt_node.left, crt_level + 1))
        if crt_node.right:
            nodes_and_levels_stack.append((crt_node.right, crt_level + 1))
    return height

