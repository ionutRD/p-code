"""
Functions for border order traversal of a binary tree
Example:
            1
          /  \
         2   3
        / \   \     =>  1 2 4 7 8 6 3
       4  5   6
         /     \
        7       8

"""
__author__ = 'Radu Ionut-Gabriel'

def traverse_left_border(root):
    """
    @param root: The root of a binary tree
    """
    if root:
        if root.left or root.right:
            yield root.data
        if (root.left):
            yield from traverse_left_border(root.left)
        else:
            yield from traverse_left_border(root.right)

def traverse_right_border(root):
    """
    @param root: The root of a binary tree
    """
    if root:
        if (root.right):
            yield from traverse_right_border(root.right)
        else:
            yield from traverse_right_border(root.left)
        if root.left or root.right:
            yield root.data

def traverse_leaves(root):
    """
    @param root: Traverse leaves from left to right
    """
    if root:
        if not root.left and not root.right:
            yield root.data
        yield from traverse_leaves(root.left)
        yield from traverse_leaves(root.right)

def border_order_v1(root):
    """
    @param root: the binary tree root
    """
    if not root:
        yield
    while bool(root.left) ^ bool(root.right):
        yield root
        if root.left:
            root = root.left
        else:
            root = root.right
    yield from traverse_left_border(root)
    yield from traverse_leaves(root)
    yield from traverse_right_border(root.right)