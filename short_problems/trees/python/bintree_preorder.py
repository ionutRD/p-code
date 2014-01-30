#!/usr/bin/python

"""
Given a binary tree print its preorder traversal
"""

class Node:
    def __init__(self, data, left = None, right = None):
        self.data, self.left, self.right = data, left, right

def preorderV1(root):
    if root:
        print root.data
        preorderV1(root.left)
        preorderV1(root.right)

def preorderV2(root):
    if not root:
        return
    nodes_stack = [root]
    while nodes_stack:
        crt_node = nodes_stack.pop()
        print crt_node.data
        if crt_node.right : nodes_stack.append(crt_node.right)
        if crt_node.left : nodes_stack.append(crt_node.left)

if __name__ == "__main__":
    t1 = Node(1, Node(2, None, Node(7)), Node(3, Node(4), Node(5, None, Node(6))))
    preorderV1(t1)
    print "--------------"
    preorderV2(t1)
