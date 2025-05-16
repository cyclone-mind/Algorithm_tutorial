""" 
递归：函数调用自身
迭代：使用循环结构

"""

import cProfile

def for_loop(n: int) -> int:
    """for 循环"""
    res = 0
    # 循环求和 1, 2, ..., n-1, n
    for i in range(1, n + 1):
        res += i
    return res

def while_loop_ii(n: int) -> int:
    """while 循环（两次更新）"""
    res = 0
    i = 1  # 初始化条件变量
    # 循环求和 1, 4, 10, ...
    while i <= n:
        res += i
        # 更新条件变量
        i += 1
        i *= 2
    return res


def nested_for_loop(n: int) -> str:
    """双层 for 循环"""
    res = ""
    # 循环 i = 1, 2, ..., n-1, n
    for i in range(1, n + 1):
        # 循环 j = 1, 2, ..., n-1, n
        for j in range(1, n + 1):
            res += f"({i}, {j}), "
    return res

""" 
递归分为两个阶段
1. 递：程序不断深入地调用自身，通常传入更小或更简化的参数，直到达到“终止条件”。
2. 归：触发“终止条件”后，程序从最深层的递归函数开始逐层返回，汇聚每一层的结果。
3个要素，终止条件，递归调用，递归返回
什么是尾递归？
尾递归是指在递归函数中，递归调用是函数的最后一行，没有其他操作。
尾递归可以被编译器或解释器优化为迭代，从而避免栈溢出。
尾递归的优点是节省栈空间，缺点是可读性较差。
尾递归函数内除了终止条件外就是最后一行：返回函数，且返回函数内除了递归调用外没有其他操作。 
普通递归：https://www.hello-algo.com/chapter_computational_complexity/iteration_and_recursion.assets/recursion_sum_depth.png
尾递归：https://www.hello-algo.com/chapter_computational_complexity/iteration_and_recursion.assets/tail_recursion_sum.png
"""

def recur(n: int) -> int:
    """递归
    终止条件：n = 1
    递归关系：f(n) = f(n-1) + n
    """
    # 终止条件
    if n == 1:
        return 1
    # 递：递归调用
    res = recur(n - 1) + n
    # 归：递归返回
    return res

def tail_recur(n: int, accumulator: int) -> int:
    """尾递归
    终止条件：n = 0
    递归关系：f(n) = f(n-1) + n
    """
    # 终止条件
    if n == 0:
        return accumulator
    # 递：递归调用
    return tail_recur(n - 1, accumulator + n)

# 3.递归树
# 斐波那契数列
def fib(n:int) -> int:
    """斐波那契数列：递归
    终止条件：f(1) = 0, f(2) = 1
    递归关系：f(n) = f(n-1) + f(n-2)
    递归树：https://www.hello-algo.com/chapter_computational_complexity/iteration_and_recursion.assets/recursion_tree.png
    """
    # 终止条件
    if n == 0:
        return 0
    if n == 1:
        return 1
    # 递：递归调用
    res = fib(n - 1) + fib(n - 2)
    # 归：递归返回
    return res

# 斐波那契数列的递归树
def fib_tree(n:int) -> int:
    """斐波那契数列：递归树"""
    return fib(n)
# How to understand the difference between recursion and iteration?
# Implementation method, time efficiency, memory usage. applicable scenarios.
if __name__ == "__main__":
    print(tail_recur(5, 0))




 