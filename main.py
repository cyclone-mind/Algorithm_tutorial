# 一个 list 是 iterable
nums = [1, 2, 3]

# 用 for 循环遍历
for n in nums:
    print(n)

# 用 iter() 得到一个 iterator
it = iter(nums)

# 用 next() 逐个取值
print(next(it))  # 输出 1
print(next(it))  # 输出 2
print(next(it))  # 输出 3
# print(next(it))  # 再 next 会报 StopIteration

class CountToN:
    """
    一个自定义的迭代器，实现从1数到n
    """
    def __init__(self, n):
        self.n = n      # 终止数字
        self.current = 1  # 当前数字，初始为1

    def __iter__(self):
        # 返回自身，因为迭代器对象需要有 __iter__ 方法
        return self

    def __next__(self):
        # 实现迭代逻辑
        if self.current <= self.n:
            result = self.current
            self.current += 1
            return result
        else:
            # 没有更多元素时抛出 StopIteration
            raise StopIteration

# 创建一个从1数到5的迭代器
counter = CountToN(5)

# 用 for 循环遍历
for num in counter:
    print(num)
