#!/usr/bin/python

"""
Given two binary trees, check if they are identical.
Two binary trees are identical if they have the same nodes and
structure
"""

class Node:
    def __init__(self, data, left = None, right = None):
        self.data, self.left, self.right = data, left, right

def xor(val1, val2):
    if (not val1 and not val2) or (val1 and val2):
        return False
    return True

def tree_equalsV1(root1, root2):
    if not root1 and not root2:
        return True
    if not root1 or not root2:
        return False
    nodes_stack1 = [root1]
    nodes_stack2 = [root2]

    while nodes_stack1 and nodes_stack2:
        crt_node1 = nodes_stack1.pop()
        crt_node2 = nodes_stack2.pop()

        if crt_node1.data != crt_node2.data:
            return False
        if xor(crt_node1.left, crt_node2.left):
            return False
        if xor(crt_node1.right, crt_node2.right):
            return False
        if crt_node1.left:
            nodes_stack1.append(crt_node1.left)
            nodes_stack2.append(crt_node2.left)
        if crt_node1.right:
            nodes_stack1.append(crt_node1.right)
            nodes_stack2.append(crt_node2.right)
    return True

def tree_equalsV2(root1, root2):
    if (root1 and not root2) or (not root1 and root2):
        return False
    if not root1 and not root2:
        return True
    return root1.data == root2.data and \
           tree_equalsV2(root1.left, root2.left) and \
           tree_equalsV2(root1.right, root2.right)

if __name__ == "__main__":
    t1 = Node(1, Node(2, None, Node(7)), Node(3, Node(4), Node(5, None, Node(6))))
    t2 = Node(1, Node(2, Node(7), None), Node(3, Node(4), Node(5, None, Node(6))))
    t3 = None
    t4 = Node(1, Node(2, None, Node(7)), Node(3, Node(4), Node(5, None, Node(6))))
    print tree_equalsV1(t1, t2)
    print tree_equalsV1(t2, t3)
    print tree_equalsV1(t1, t4)
    print "---------------------"
    print tree_equalsV2(t1, t2)
    print tree_equalsV2(t2, t3)
    print tree_equalsV2(t1, t4)
