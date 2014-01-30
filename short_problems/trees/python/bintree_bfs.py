#!/usr/bin/python

"""
Given a binary tree, print the tree level by level
"""

import sys

class Node:
    def __init__(self, data, left = None, right = None):
        self.data, self.left, self.right = data, left, right

def print_levelsV1(root):
    if not root:
        return
    prev_level = 0
    nodes_queue = [(root, 1)]
    while nodes_queue:
        crt_node, level = nodes_queue.pop(0)
        if level > prev_level:
            sys.stdout.write("\n")
            prev_level = level
        sys.stdout.write("{0} ".format(crt_node.data))
        if crt_node.left : nodes_queue.append((crt_node.left, level + 1))
        if crt_node.right: nodes_queue.append((crt_node.right, level + 1))

if __name__ == "__main__":
    t1 = Node(1, Node(2, None, Node(7)), Node(3, Node(4), Node(5, None, Node(6))))
    print_levelsV1(t1)
