/*
123. 买卖股票的最佳时机 III
困难
相关标签
premium lock icon
相关企业
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

输入：prices = [3,3,5,0,0,3,1,4]
输出：6
解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 =
3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。 随后，在第 7 天（股票价格 =
1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1
= 3 。
*/
#include <iostream>
#include <vector>
using namespace std;

// dp数组含义，每一天的5个状态：
/*
dp[i][0] 第i天时 还没有开始交易 dp[i][0] =
dp[i][1] 第i天时 第一次交易持有，可能是当天买的可能是前一天就已经买了 dp[i][1] =
dp[i - 1][0] -  prices[i], dp[i - 1][1] dp[i][2] 第i天时
第一次交易没持有，可能是这天卖出了，或者是前一天就已经卖出了 dp[i][2] = dp[i -
1][1] + prices[i],dp[i - 1][2] dp[i][3] 第i天时
第二次交易持有，可能是这天买入的或者是前一天就已经买入了 dp[i][4] 第i天时
第二次交易没持有，可能是这天卖出了，或者是前一天就已经卖出了
*/
int maxProfit(vector<int> &prices) {
    int maxProfit(vector<int> & prices) {
        if (prices.size() == 0)
            return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        return dp[prices.size() - 1][4];
    }
}

int main(){}