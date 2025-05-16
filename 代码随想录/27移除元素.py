# 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。
from typing import List
nums = [0, 1, 2, 2, 3, 0, 4, 2]
val =  2
def removeElement_corrected_brute_force(nums, val) -> int:
    i= 0
    current_size = len(nums)
    while i<current_size:
        if nums[i] == val:
            for j in range(i+1,current_size):
                nums[j-1] = nums[j]
            current_size -=1
            # 注意：此时 i 不需要增加，因为要检查新移动到 i 位置的元素
        else:
            i+=1
    return current_size
    
def removeElement(nums: List[int], val: int) -> int:
        while val in nums: # 1. 检查 val 是否还在 nums 中，这一步遍历nums O(n)
            nums.remove(val) # 2. 如果在，移除第一个找到的 val ，这一步遍历nums O(n) 实际上O(N²) 
        return len(nums)
    
def shuangremoveElement(nums: List[int], val: int) -> int:
    slow = 0
    for fast in range(len(nums)):
        if nums[fast]!=val:
            nums[slow]=nums[fast]
            slow+=1
    return slow
print(removeElement_corrected_brute_force(nums=nums,val=val))

print(shuangremoveElement(nums=nums,val=val))