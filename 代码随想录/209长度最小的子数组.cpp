// 给定一个含有 n 个正整数的数组和一个正整数 target 。
// 找出该数组中满足其总和大于等于 target 的长度最小的 子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。
// 如果不存在符合条件的子数组，返回 0 。

#include <vector>
#include <iostream>

int minSubArrayLen(int target, std::vector<int> &nums)
{
    int result = INT_MAX;
    int sum = 0;
    int sublength = 0;
    int left = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        sum += nums[right];
        while (sum >= target)
        {
            sublength = right - left + 1;
            result = result < sublength ? result : sublength;
            sum -= nums[left++];
        }
    }
    return result == INT_MAX ? 0 : result;
}

int main()
{
    std::vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    // std::cout << INT_MAX << std::endl;
    std::cout << minSubArrayLen(target, nums) << std::endl;
}