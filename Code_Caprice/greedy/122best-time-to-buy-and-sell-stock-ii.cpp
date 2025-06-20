/*
122. 买卖股票的最佳时机 II
中等
相关标签
premium lock icon
相关企业
给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。

返回 你能获得的 最大 利润 。

示例 1：

输入：prices = [7,1,5,3,6,4]
输出：7
解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4。
随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3。
最大总利润为 4 + 3 = 7 。
示例 2：

输入：prices = [1,2,3,4,5]
输出：4
解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4。
最大总利润为 4 。
示例 3：

输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 交易无法获得正利润，所以不参与交易可以获得最大利润，最大利润为 0。
 

提示：

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104
这道题就是把股票价格的波动图画出来，然后只要求所有上升的那段长度就可以了。
贪心的核心思想是只要明天的价格比今天高。我们就今天买入明天卖出。我们不关心后天 的价格怎么样。 
哪怕后天的价格再高 我们也要等明天再说 
*/
#include <algorithm>
#include <vector>
#include <iostream>

int maxProfit(std::vector<int>& prices) {
    int result = 0;
    for(int i = 1;i < prices.size();i++){
        result += std::max(prices[i] - prices[i - 1],0);
    }
    return result;
}
int main(){
    std::vector<int> prices = {7,1,5,3,6,4};
    int result = maxProfit(prices);
    std::cout << result << std::endl;
}


