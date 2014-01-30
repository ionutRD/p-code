#!/usr/bin/python

"""
Given a binary tree, print its inorder traversal
"""

class Node:
    def __init__(self, data, left = None, right = None):
        self.data, self.left, self.right = data, left, right


def inorderV1(root):
    if root:
        inorderV1(root.left)
        print root.data
        inorderV1(root.right)

def inorderV2(root):
    crt_node = root
    nodes_stack = []
    while True:
        if crt_node:
            nodes_stack.append(crt_node)
            crt_node = crt_node.left
        else:
            if not nodes_stack:
                return
            crt_node = nodes_stack.pop()
            print crt_node.data
            crt_node = crt_node.right

if __name__ == "__main__":
    t1 = Node(1, Node(2, None, Node(7)), Node(3, Node(4), Node(5, None, Node(6))))
    inorderV1(t1)
    print "-------------"
    inorderV2(t1)
