__author__ = 'Radu Ionut-Gabriel'

def postorder_v1(root):
    """
    @param root: the root of a binary tree
    """
    if root:
        yield from postorder_v1(root.left)
        yield from postorder_v1(root.right)
        yield root.data

def postorder_v2(root):
    """
    @param root: the root of a binary tree
    """
    if not root:
        yield
    nodes_stack = [root]
    postorder_stack = []
    while nodes_stack:
        crt_node = nodes_stack.pop()
        postorder_stack.append(crt_node)
        if crt_node.left:
            nodes_stack.append(crt_node.left)
        if crt_node.right:
            nodes_stack.append(crt_node.right)

    while postorder_stack:
        yield postorder_stack.pop().data