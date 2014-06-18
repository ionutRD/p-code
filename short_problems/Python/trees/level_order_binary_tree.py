"""
Functions for level order traversal in a binary tree.
"""
__author__ = 'Radu Ionut-Gabriel'

def level_order_v1(root):
    """
    @param root: the binary tree root
    """
    if not root:
        yield
    nodes_queue = [root]
    while nodes_queue:
        crt_node = nodes_queue.pop(0)
        yield crt_node.data
        if crt_node.left:
            nodes_queue.append(crt_node.left)
        if crt_node.right:
            nodes_queue.append(crt_node.right)
