"""


好的，这段关于时间复杂度的笔记可以总结为以下几点 📝：

1.  **精确评估难**: 直接计算算法的精确运行时间非常困难，因为它受到硬件、编程语言、操作系统等多种因素的影响，而且统计各种操作（加法、赋值、比较等）的具体次数也很繁琐 🤯。
2.  **关注增长趋势**: 实际中，我们更关心的是随着输入数据量 `n` 的增大，算法运行时间的**增长趋势**，而不是绝对时间 📈。
3.  **简化分析**: 时间复杂度分析做了以下简化：
    *   忽略运行平台差异。
    *   假设所有计算操作的执行时间都是一个固定的“单位时间”。这样，我们只需要关注**计算操作的数量** 🔢。
4.  **渐进上界**: 我们用 大O 表示法 \(O(f(n))\) 来描述时间复杂度，它表示算法运行时间随 `n` 增长的**渐进上界**。
5.  **确定 \(f(n)\)**:
    *   **统计操作数**: 需要一些技巧来简化：
        *   忽略常数项系数。
        *   省略所有系数。
        *   嵌套循环的操作数按乘法计算。
    *   **取最高阶**: 只保留操作数量表达式中的最高阶项。
6.  **常见复杂度类型**: 笔记中列举了几种常见的复杂度，并给出了对应的例子：
    *   常数阶 \(O(1)\)
    *   线性阶 \(O(n)\) - 单层循环
    *   平方阶 \(O(n^2)\) - 嵌套循环 (如冒泡排序)
    *   指数阶 \(O(2^n)\) - 递归 (如未优化的斐波那契)
    *   对数阶 \(O(\log n)\) - (通常出现在分治或特定循环中)
    *   线性对数阶 \(O(n \log n)\) - 高效排序算法 (快排、归并、堆排)
    *   阶乘阶 \(O(n!)\) - 全排列
7.  **复杂度非万能**:
    *   相同时间复杂度的算法，实际运行时间可能因常数项、低阶项或具体实现而不同 🐢 vs 🐇。
    *   复杂度更高的算法在输入规模 `n` 较小时，可能反而更快 🤔。
    *   输入数据的分布也可能影响实际运行效率 🎲。

总的来说，时间复杂度是衡量算法效率的重要工具，它帮助我们理解算法性能如何随数据规模扩展，但它是一种**渐进趋势**的度量，而非精确时间的预测器 👍。


how toestimate the runtime of a piece of an algorithm?
1. determining the running platform:hardware, programming language, system environment
2. counting the number of various operations: arithmetic operations, assignments, comparisons, function calls, etc.
3. calculate the total runtime: sum up the computational operations in the code.
But it is not practical to do this.

So we need to simplify the problem.

1. ignore the running platform.
2. ignore the run time for each type of operation.

Actually, we only need to focus on the growth trend of the running time as the data volume increases.

The characteristics of time complexity analysis?
1. Time complexity effectively assesses algorithm efficiency.
2. 简单地将所有计算操作的执行时间视为相同的“单位时间”，从而将“计算操作运行时间统计”简化为“计算操作数量统计”
3. 尽管算法 A 和 C 的时间复杂度相同，但实际运行时间差别很大。同样，尽管算法 B 的时间复杂度比 C 高，但在输入数据大小 较小时，算法 B 明显优于算法 C

Asymptotic upper bound f(n)

Once f(n) is determined, we obtain the time complexity O(f(n)).
how to determine f(n)?
two steps:
1. counting the number of operations.
three simplification techniques:
1.1 ignore constant coefficients.
1.2 Omit all coefficients.
1.3 use multiplication for nested loops.

2. determining the asymptotic upper bound.
find the highest order term.

common types of time complexity:
常数阶
线性阶 单层循环
平方阶 嵌套循环 冒泡排序
指数阶 2的n次方 递归函数
对数阶 log(n) 递归函数
线性对数阶 嵌套循环 一层log(n) 和 一层n 主流排序算法：快速排序、归并排序、堆排序
阶乘阶 全排列 递归


https://www.hello-algo.com/chapter_computational_complexity/time_complexity.assets/time_complexity_common_types.png


同样的时间复杂度、但输入数据的分布不同，很可能有着不一样的时间效率。


"""
import random


def logarithmic(n: int) -> int:
    """对数阶（循环实现）"""
    count = 0
    while n > 1:
        n = n / 2
        count += 1
    return count

def random_numbers(n:int) -> list[int]:
    """生成一个数组，元素为: 1, 2, ..., n ，顺序被打乱"""
    nums = [i for i in range(1, n + 1)]
    random.shuffle(nums)
    return nums

if __name__ == "__main__":
    # print(logarithmic(200))
    print(random_numbers(5))