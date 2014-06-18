"""
Functions for counting the number of nodes in a binary tree.
"""
__author__ = 'Radu Ionut-Gabriel'


def count_nodes_v1(root):
    """
    @param root: the root of a binary tree
    @return: the number of nodes in a binary tree
    """
    if not root:
        return 0
    return 1 + count_nodes_v1(root.left) + count_nodes_v1(root.right)


def count_nodes_v2(root, count=0):
    """
    @param root: the root of a binary tree
    @param count: the number of nodes in a binary tree
    @return:
    """
    if not root:
        return count
    return count_nodes_v2(root.left, count_nodes_v2(root.right, count + 1))


def count_nodes_v3(root):
    """
    @param root: the root of a binary tree
    @return: the number of nodes in the binary tree
    """
    if not root:
        return 0
    nodes_stack = [root]
    count = 0
    while nodes_stack:
        crt_node = nodes_stack.pop()
        count += 1
        if crt_node.left:
            nodes_stack.append(crt_node.left)
        if crt_node.right:
            nodes_stack.append(crt_node.right)
    return count
