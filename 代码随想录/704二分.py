nums = [-1,0,3,5,9,12]
target = 9

# 二分查找函数
def binary_search(nums: list[int], target: int) -> int:
    """
    在有序列表 nums 中查找 target 元素。

    Args:
        nums: 有序的整数列表。
        target: 需要查找的目标整数。

    Returns:
        如果找到 target，返回其在 nums 中的索引；否则返回 -1。
    """
    left = 0
    right = len(nums) - 1 # 定义target在[left, right]的闭区间

    while left <= right: # 当left == right时，区间[left, right]依然有效
        # middle = left + (right - left) // 2 # 防止溢出，等同于 (left + right) // 2
        # 在 Python 中，(left + right) // 2 这种写法通常不会导致整数溢出，因为 Python 的整数类型支持任意精度。
        # (right - left) / 2 的写法在其他语言中（如 C++、Java）是为了防止 (left + right) 可能超过整数类型的最大值而导致溢出。
        # 在 Python 中，可以直接写 middle = (left + right) // 2
        middle = (left + right) // 2

        if nums[middle] == target:
            return middle # 找到了目标值，返回索引
        elif nums[middle] < target:
            left = middle + 1 # target 在右区间，所以[middle + 1, right]
        else: # nums[middle] > target
            right = middle - 1 # target 在左区间，所以[left, middle - 1]
    
    return -1 # 未找到目标值

# 测试
result = binary_search(nums, target)
if result != -1:
    print(f"目标 {target} 在列表中的索引是: {result} ✨")
else:
    print(f"目标 {target} 未在列表中找到 🙁")

# 另一种常见的写法是左闭右开区间 [left, right)
def binary_search_left_closed_right_open(nums: list[int], target: int) -> int:
    """
    在有序列表 nums 中查找 target 元素 (左闭右开区间写法)。

    Args:
        nums: 有序的整数列表。
        target: 需要查找的目标整数。

    Returns:
        如果找到 target，返回其在 nums 中的索引；否则返回 -1。
    """
    left = 0
    right = len(nums) # 定义target在[left, right)的左闭右开区间

    while left < right: # 当left == right时，区间[left, right)无效
        middle = left + (right - left) // 2

        if nums[middle] == target:
            return middle
        elif nums[middle] < target:
            left = middle + 1 # target 在右区间，所以[middle + 1, right)
        else: # nums[middle] > target
            right = middle # target 在左区间，所以[left, middle)
            # 注意这里是 right = middle，因为当前 nums[middle] 不等于 target，
            # 而且 nums[middle] > target，所以下一个搜索区间是 [left, middle)，
            # middle 本身是不包含在内的。
    
    return -1

# 测试左闭右开区间版本
# result_v2 = binary_search_left_closed_right_open(nums, target)
# if result_v2 != -1:
#     print(f"(左闭右开)目标 {target} 在列表中的索引是: {result_v2} ✅")
# else:
#     print(f"(左闭右开)目标 {target} 未在列表中找到 ❌")

# 你原来的代码片段修改 (基于左闭右开的思路，但仍有逻辑问题需要调整)
# 假设这是在一个函数内部或者你要直接运行
# left = 0
# right = len(nums) # 左闭右开 [left, right)
# found_index = -1
# while(left < right): # 当 left == right 时，区间为空，循环结束
#     # middle = (right-left) / 2 # 1. 应该用 // 整数除法 2. 建议 left + (right - left) // 2
#     middle = left + (right - left) // 2
#     # if target > nums(middle): # 1. 应该是 nums[middle] 2. 条件写反了
#     if nums[middle] < target: # 如果中间值小于目标值
#         left = middle + 1    # 目标在右侧，新的左边界是 middle + 1
#     elif target < nums[middle]: # 应该是 target < nums[middle]
#         right = middle       # 目标在左侧，新的右边界是 middle
#     else: # target == nums[middle]
#         found_index = middle
#         break # 找到了就跳出循环
# 
# if found_index != -1:
#     print(f"目标 {target} 的索引是: {found_index}")
# else:
#     print(f"未找到目标 {target}")
