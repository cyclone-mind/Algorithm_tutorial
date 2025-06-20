/*
518. 零钱兑换 II
中等
相关标签
premium lock icon
相关企业
给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。

请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回
0 。

假设每一种面额的硬币有无限个。

题目数据保证结果符合 32 位带符号整数。


示例 1：

输入：amount = 5, coins = [1, 2, 5]
输出：4
解释：有四种方式可以凑成总金额：
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
示例 2：

输入：amount = 3, coins = [2]
输出：0
解释：只用面额 2 的硬币不能凑成总金额 3 。
示例 3：

输入：amount = 10, coins = [10]
输出：1


提示：

1 <= coins.length <= 300
1 <= coins[i] <= 5000
coins 中的所有值 互不相同
0 <= amount <= 5000
*/

#include <vector>
using namespace std;
#include <cstdint>
#include <iostream>

int change_2dp(int amount, vector<int> &coins) {
    vector<vector<uint64_t>> dp(coins.size(), vector<uint64_t>(amount + 1, 0));
    for (int i = 0; i < coins.size(); i++) {
        dp[i][0] = 1;
    }
    for (int j = 0; j <= amount; j++) {
        if (j % coins[0] == 0)
            dp[0][j] = 1;
    }
    for (int i = 1; i < coins.size(); i++) {
        for (int j = 0; j <= amount; j++) {
            if (j < coins[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
        }
    }
    return dp[coins.size() - 1][amount];
}

int change_1dp(int amount, vector<int> &coins) {
    vector<uint64_t> dp(amount + 1, 0);
    dp[0] = 1;
    for(int i = 0;i < coins.size();i++){
        for(int j = coins[i];j <= amount;j++){
            dp[j] += dp[j - coins[i]];
        }
        std::cout << "coin" << coins[i] << ": ";
        for(int zuhe:dp){
            std::cout << zuhe << " ";
        }
        std::cout << std::endl;
    }
    return dp[amount];
}

// 新增函数：使用金额在外层、硬币在内层的遍历顺序计算排列数，并打印dp数组
int change_1dp_permutation(int amount, vector<int> &coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    // 外层遍历金额，内层遍历硬币，用于计算排列数
    for (int j = 0; j <= amount; j++) {
        for (int i = 0; i < coins.size(); i++) {
            if (j - coins[i] >= 0)
                dp[j] += dp[j - coins[i]];
        }
        // 打印处理完当前金额后的dp数组状态
        std::cout << "处理完金额 " << j << " 后的dp数组: ";
        for (int val : dp) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    std::cout << change_1dp(5, coins) << std::endl;
    std::cout << change_1dp_permutation(5, coins) << std::endl;
}