#!/usr/bin/python

"""
Write a program to find out the maximum width of a binary tree
"""

class Node:
    def __init__(self, data, left = None, right = None):
        self.data, self.left, self.right = data, left, right

def tree_widthV1(root):
    if not root:
        return 0
    max_width = 0
    crt_width = 0
    prev_level = 0
    nodes_queue = [(root, 1)]
    while nodes_queue:
        crt_node, level = nodes_queue.pop(0)
        if level > prev_level:
            max_width = max(crt_width, max_width)
            crt_width = 1
            prev_level = level
        else:
            crt_width += 1
        if crt_node.left : nodes_queue.append((crt_node.left, level + 1))
        if crt_node.right : nodes_queue.append((crt_node.right, level + 1))

    return max_width

if __name__ == "__main__":
    t1 = Node(1, Node(2, None, Node(7)), Node(3, Node(4), Node(5, None, Node(6))))
    print tree_widthV1(t1)
