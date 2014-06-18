"""
Functions for zig-zag order traversal of a binary tree.
Example:
            1
          /  \
         2   3  => 1 3 2 4 5 6 8 7
        / \   \
       4  5   6
         /     \
        7       8
"""
__author__  = "Radu Ionut-Gabriel"

from lists.nodes import DoublyLinkedListNode

def zigzag_order_v1(root):
    """
    @param root: the binary tree root
    """
    if not root:
        yield
    crt_level = 0
    nodes_deque = [(root, crt_level)]
    while nodes_deque:
        _, level = nodes_deque[0]
        if level != crt_level:
            nodes_deque = nodes_deque[::-1]
        crt_node, crt_level = nodes_deque.pop(0);
        yield crt_node.data
        if not crt_level & 1:
            if crt_node.left:
                nodes_deque.append((crt_node.left, level + 1))
            if crt_node.right:
                nodes_deque.append((crt_node.right, level + 1))
        else:
            if crt_node.right:
                nodes_deque.append((crt_node.right, level + 1))
            if crt_node.left:
                nodes_deque.append((crt_node.left, level + 1))

