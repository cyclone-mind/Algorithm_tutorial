/*
494. 目标和
中等
相关标签
premium lock icon
相关企业
给你一个非负整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-'
，然后串联起来得到表达式 "+2-1" 。 返回可以通过上述方法构造的、运算结果等于
target 的不同 表达式 的数目。



示例 1：

输入：nums = [1,1,1,1,1], target = 3
输出：5
解释：一共有 5 种方法让最终目标和为 3 。
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
示例 2：

输入：nums = [1], target = 1
输出：1


提示：

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000

*/

#include <vector>
using namespace std;
#include <cmath>
#include <iostream>

int findTargetSumWays(vector<int> &nums, int target) {
    int sum = 0;
    int zero_count = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (nums[i] == 0)
            zero_count++;
    };
    if (abs(target) > sum)
        return 0;
    // int target_sum = (sum + target) / 2;
    // if (target_sum % 2 != 0)
    //     return 0;
    //     这么写一定错，因为计算出target_sum的时候就已经进行了向下取整
    
    if ((sum + target) % 2 != 0)
        return 0; // 检查 (sum + target) 是否能被 2 整除
    int target_sum = (sum + target) / 2;
    vector<int> dp(target_sum + 1, 0);
    dp[0] = pow(2, zero_count);

    std::cout << "初始dp数组: ";
    for (int k = 0; k <= target_sum; k++) {
        std::cout << dp[k] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0)
            continue;
        for (int j = target_sum; j >= nums[i]; j--) {
            dp[j] += dp[j - nums[i]];
        }
        std::cout << "处理完 nums[" << i << "] = " << nums[i]
                  << " 后的dp数组: ";
        for (int k = 0; k <= target_sum; k++) {
            std::cout << dp[k] << " ";
        }
        std::cout << std::endl;
    }
    return dp[target_sum];
}

int main() {
    vector<int> nums = {1, 1,1,1,1};
    std::cout << findTargetSumWays(nums, 3) << std::endl;
}