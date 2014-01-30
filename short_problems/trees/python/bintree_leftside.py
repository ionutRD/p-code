#!/usr/bin/python

"""
Print the left side of a binary tree
E.g.
   1
 /   \
2     3
 \   /  \
  7 4    5
          \
           6
For the above tree the program should print: 1 2 7 6.
"""

class Node:
    def __init__(self, data, left = None, right = None):
        self.data, self.left, self.right = data, left, right

def print_leftsideV1(root, level = 0, height = 0):
    if not root:
        return height

    if level + 1 > height:
        print root.data
        height = level + 1

    if root.left:
        height = print_leftsideV1(root.left, level + 1, height)

    if root.right:
        height = print_leftsideV1(root.right, level + 1, height)

    return height

def print_leftsideV2(root):
    if not root:
        return
    nodes_stack = [(root, 1)]
    height = 0
    while nodes_stack:
        crt_node, level = nodes_stack.pop()
        if level > height:
            print crt_node.data
            height = level
        if crt_node.right : nodes_stack.append((crt_node.right, level + 1))
        if crt_node.left : nodes_stack.append((crt_node.left, level + 1))

def print_leftsideV3(root):
    if not root:
        return
    prev_level = 0
    nodes_queue = [(root, 1)]
    while nodes_queue:
        crt_node, level = nodes_queue.pop(0)
        if level > prev_level:
            print crt_node.data
            prev_level = level
        if crt_node.left : nodes_queue.append((crt_node.left, level + 1))
        if crt_node.right : nodes_queue.append((crt_node.right, level + 1))

if __name__ == "__main__":
    t1 = Node(1, Node(2, None, Node(7)), Node(3, Node(4), Node(5, Node(6), None)))
    print_leftsideV1(t1)
    print "------------"
    print_leftsideV2(t1)
    print "------------"
    print_leftsideV3(t1)

