"""
输入空间
暂存空间 = （暂存数据+栈帧空间+指令空间）

    暂存数据：用于保存算法运行过程中的各种常量、变量、对象等。
    栈帧空间：用于保存调用函数的上下文数据。系统在每次调用函数时都会在栈顶部创建一个栈帧，函数返回后，栈帧空间会被释放。
    指令空间：用于保存编译后的程序指令，在实际统计中通常忽略不计。

输出空间
空间复杂度的统计范围是"暂存空间" + "输出空间"

常见的空间复杂度类型（从低到高排列）。
常数阶 与输入数据大小无关的常量、变量。 在循环中初始化变量或调用函数而占用的内存，在进入下一循环后就会被释放，因此不会累积占用空间
对数阶 
线性阶 数组、链表、栈、队列、递归函数
平方阶 矩阵（二维列表）、图
指数阶 二叉树 

"""

class Node:
    """类"""
    def __init__(self, x: int):
        self.val: int = x              # 节点值
        self.next: Node | None = None  # 指向下一节点的引用

def function() -> int:
    """函数"""
    # 执行某些操作...
    return 0

def algorithm(n) -> int:  # 输入数据
    A = 0                 # 暂存数据（常量，一般用大写字母表示）
    b = 0                 # 暂存数据（变量）
    node = Node(0)        # 暂存数据（对象）
    c = function()        # 栈帧空间（调用函数）
    return A + b + c      # 输出数据

def algorithm(n: int):
    a = 0               # O(1)
    b = [0] * 10000     # O(1)
    if n > 10:
        nums = [0] * n  # O(n)
    return nums


def quadratic(n: int):
    """平方阶"""
    # 二维列表占用 O(n^2) 空间
    num_matrix = [[0] * n for _ in range(n)]

def quadratic_recur(n: int) -> int:
    """平方阶（递归实现）"""
    if n <= 0:
        return 0
    # 数组 nums 长度为 n, n-1, ..., 2, 1
    nums = [0] * n
    return quadratic_recur(n - 1)

class TreeNode:
    def __init__(self, val:int=0) -> None:
        self.val:int = val
        self.left:TreeNode | Node =  None
        self.right:TreeNode | Node =  None

def build_tree(n: int) -> TreeNode | None:
    """指数阶（建立满二叉树）"""
    if n == 0:
        return None
    root = TreeNode(0)
    root.left = build_tree(n - 1)
    root.right = build_tree(n - 1)
    return root

"""Driver Code"""
if __name__ == "__main__":
    n = 5
    print("输入数据大小 n =", n)
        
        # 指数阶
    root = build_tree(n)
