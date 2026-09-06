class Node:
    def __init__(self,data:int):
        self.data=data
        self.left=None
        self.right=None
        self.height=1

root = None

def getHeight(root):
    if root is None:
        return 0
    return root.height

def getBalanceFactor(root):
    if root is None:
        return 0
    return getHeight(root.left)-getHeight(root.right)

def leftRotate(root):
    right = root.right
    displaced = right.left

    right.left=root
    root.right = displaced
    root.height = 1+ max(getHeight(root.left),getHeight(root.right))
    right.height = 1+max(getHeight(right.left),getHeight(right.right))
    return right

def rightRotate(root):
    left = root.left
    displaced = left.right

    left.right=root
    root.left=displaced

    root.height = 1+ max(getHeight(root.left),getHeight(root.right))
    left.height = 1+max(getHeight(left.left),getHeight(left.right))
    return left



def insert(root:Node, data:int):
    if root==None:
        root = Node(data)
    elif root.data > data:
        root.left = insert(root.left,data)
    elif root.data < data:
        root.right = insert(root.right,data)

    root.height = 1+max(getHeight(root.left),getHeight(root.right))
    bf = getBalanceFactor(root)

    # left-left
    if bf > 1 and data < root.left.data:
        return rightRotate(root)

    # right-right
    if bf < -1 and data > root.right.data:
        return leftRotate(root)

    # left - right
    if bf > 1 and data > root.right.data:
        root.left = leftRotate(root.left)
        return rightRotate(root)

    # right - left
    if bf < -1 and data < root.left.data:
        root.right = rightRotate(root.right)
        return leftRotate(root)

    return root

def display(root, height=0):
    if root is None:
        return
    print(" "*height,root.data)
    display(root.left,height+1)
    display(root.right,height+1)

arr = [1,2,3,4,5,6,7,8]
for i in arr:
    root = insert(root,i)

display(root)
