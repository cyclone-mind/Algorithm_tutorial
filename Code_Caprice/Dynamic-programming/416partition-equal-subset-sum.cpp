/*
416. 分割等和子集
中等
相关标签
premium lock icon
相关企业
给你一个 只包含正整数 的 非空 数组 nums
。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

示例 1：

输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。
示例 2：

输入：nums = [1,2,3,5]
输出：false
解释：数组不能分割成两个元素和相等的子集。


提示：

1 <= nums.length <= 200
1 <= nums[i] <= 100
思路：
是否有一个集合的和等于sum/2，也就是从整个集合中取值，求和，看看和是否等于sum/2
"我们能在 nums 数组中，找到一个子集，使得这个子集的元素加起来正好等于 target
吗？" "从数组中挑选一些数，让它们的和恰好等于 target"。这听起来是不是有点耳熟？

0/1 背包问题	分割等和子集问题
背包的容量 (Capacity)	➡️	目标和 target (我们想要凑出的那个数)
物品 (Item)	➡️	数组 nums 里的每个数字 num (我们可以选择的数)
物品的重量 (Weight)	➡️	数字 num 的值 (每个数的大小就是它的"重量")
物品的价值 (Value)	➡️	数字 num 的值
(我们把一个数放进子集，得到的"价值"就是这个数本身)

> 我们有一个容量为 target 的背包，和一堆物品（nums
数组中的数字）。每个物品的重量和价值都等于它自身的数值。
问：我们能否选择若干物品，恰好把背包装满？
"恰好装满"就意味着，装入背包的物品，它们的总重量（也就是总和）正好等于背包的容量 target。
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int> &nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
        sum += nums[i];

    if (sum % 2)
        return false;
    int target = sum / 2;

    vector<int> dp(target + 1, 0);

    for (int i = 0; i < nums.size(); i++) {
        for (int j = target; j >= nums[i]; j--) {
            dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }
    return dp[target] == target;
}

int main() {
    vector<int> nums = {1, 5, 11, 5};
    bool result = canPartition(nums);
    std::cout << result << std::endl;
}