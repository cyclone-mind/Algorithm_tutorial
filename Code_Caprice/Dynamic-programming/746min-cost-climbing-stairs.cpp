/*
746. 使用最小花费爬楼梯
简单
相关标签
premium lock icon
相关企业
提示
给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。

你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。

请你计算并返回达到楼梯顶部的最低花费。


示例 1：

输入：cost = [10,15,20]
输出：15
解释：你将从下标为 1 的台阶开始。
- 支付 15 ，向上爬两个台阶，到达楼梯顶部。
总花费为 15 。
示例 2：

输入：cost = [1,100,1,1,1,100,1,1,100,1]
输出：6
解释：你将从下标为 0 的台阶开始。
- 支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
- 支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
- 支付 1 ，向上爬一个台阶，到达楼梯顶部。
总花费为 6 。
 

提示：

2 <= cost.length <= 1000
0 <= cost[i] <= 999
*/
#include <vector>
using namespace std;
#include <iostream>
// 爬到楼顶所需最小花费是 爬到n-1层所需最小花费加上从这层出发所需要的花费 与 爬到n-2层所需最小花费加上从这层出发所需要的花费
int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size() + 1);
    dp[0] = 0,dp[1] = 0;
    for(int i = 2;i < cost.size() + 1;i++){
    dp[i] = min(dp[i - 1] + cost[i - 1],dp[i - 2] + cost[ i - 2]);
    }
    return dp.back();
}
int main(){
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    std::cout << minCostClimbingStairs(cost) << std::endl;
}