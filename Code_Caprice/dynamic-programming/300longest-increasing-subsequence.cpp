/*
300. 最长递增子序列
中等
相关标签
premium lock icon
相关企业
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

 
示例 1：

输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    if (nums.size() <= 1) return 1;
    vector<int> dp(nums.size(),1);
    int result = 0;
    for(int i = 1;i < nums.size();i++){
        for(int j = 0;j < i;j++){
            if(nums[i] > nums[j]) dp[i] = max(dp[j] + 1,dp[i]);
        }
        result = max(result,dp[i]);
    }
    return result;
}

int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    std::cout << lengthOfLIS(nums) << std::endl;
}