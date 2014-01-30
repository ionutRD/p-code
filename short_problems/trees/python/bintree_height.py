#! /usr/bin/pyton

"""
Find the height of a binary tree.
Height of a binary tree is defined as the longest path from root to leaves
"""

class Node:
    def __init__(self, data, left = None, right = None):
        self.data, self.left, self.right = data, left, right

def tree_heightV1(root):
    if not root:
        return 0
    return 1 + max(tree_heightV1(root.left), tree_heightV1(root.right))

def tree_heightV2(root):
    if not root:
        return 0
    height = 0
    nodes_stack = [(root, 1)]
    while nodes_stack:
        crt_node, level = nodes_stack.pop()
        if crt_node.left :
            nodes_stack.append((crt_node.left, level + 1))
            height = max(height, level + 1)

        if crt_node.right :
            nodes_stack.append((crt_node.right, level + 1))
            height = max(height, level + 1)

    return height


if __name__ == "__main__":
    t1 = None
    print tree_heightV1(t1)
    print tree_heightV2(t1)

    t2 = Node(1, Node(2, Node(4, None, Node(6)), Node(5)), Node(3, Node(7), None))
    print tree_heightV1(t2)
    print tree_heightV2(t2)
