#!/usr/bin/python

"""
Given a binary tree, find the number of nodes in the tree
"""

class Node:
    def __init__(self, data, left = None, right = None):
        self.data, self.left, self.right = data, left, right

def count_nodesV1(root):
    if not root:
        return 0
    return 1 + count_nodesV1(root.left) + count_nodesV1(root.right)

def count_nodesV2(root, count = 0):
    if not root:
        return count
    return count_nodesV2(root.left, count_nodesV2(root.right, count + 1))

def count_nodesV3(root):
    if not root:
        return 0
    count  = 0
    nodes_stack = [root]
    while nodes_stack:
        crt_node = nodes_stack.pop()
        count += 1
        if crt_node.left : nodes_stack.append(crt_node.left)
        if crt_node.right : nodes_stack.append(crt_node.right)
    return count

if __name__ == "__main__":
    t1 = None
    print count_nodesV1(t1)
    print count_nodesV2(t1)
    print count_nodesV3(t1)

    t2 = Node(1, Node(2, Node(4), Node(5)), Node(3, None, Node(6)))
    print count_nodesV1(t2)
    print count_nodesV2(t2)
    print count_nodesV3(t2)

