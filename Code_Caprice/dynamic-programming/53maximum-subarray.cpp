/*
53. 最大子数组和
已解答
中等
相关标签
premium lock icon
相关企业
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组是数组中的一个连续部分。

 

示例 1：

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。*/


#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    int result = nums[0];
    for(int i = 1;i < nums.size();i++){
        dp[i] = max(dp[i - 1] + nums[i],nums[i]);
        if(dp[i] > result) result = dp[i];
    }
    return result;
}

int main(){

}
