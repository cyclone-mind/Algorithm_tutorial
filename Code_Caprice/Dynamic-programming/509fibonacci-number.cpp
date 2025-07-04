/*
509. 斐波那契数
简单
相关标签
premium lock icon
相关企业
斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1
开始，后面的每一项数字都是前面两项数字的和。也就是：

F(0) = 0，F(1) = 1
F(n) = F(n - 1) + F(n - 2)，其中 n > 1
给定 n ，请计算 F(n) 。


示例 1：

输入：n = 2
输出：1
解释：F(2) = F(1) + F(0) = 1 + 0 = 1
示例 2：

输入：n = 3
输出：2
解释：F(3) = F(2) + F(1) = 1 + 1 = 2
示例 3：

输入：n = 4
输出：3
解释：F(4) = F(3) + F(2) = 2 + 1 = 3

提示：

0 <= n <= 30
*/
#include <iostream>
#include <vector>
// 递归写法
// int fib(int n) {
//     if(n == 0) return 0;
//     if(n == 1) return 1;
//     return fib(n - 1) + fib(n - 2);
// }

// 动态规划写法
int fib(int n) {
    if(n == 0) return 0;
    // 1. 确定 dp 数组及下标含义
    // dp[i] 表示第 i 个斐波那契数的值
    std::vector<int> dp(n + 1);

    // 2. 初始化 dp 数组
    // 初始条件：dp[0] = 0, dp[1] = 1
    dp[0] = 0, dp[1] = 1;

    // 3. 递推公式
    // dp[i] = dp[i - 1] + dp[i - 2]

    // 4. 遍历顺序
    // 后一项依赖前一项，因此从前往后遍历
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // 5. 举例推导 dp 数组（验证）
    // 例如 n = 4 时：
    // dp[0] = 0, dp[1] = 1
    // dp[2] = 1, dp[3] = 2, dp[4] = 3
    return dp[n];
}

int main() { std::cout << fib(4) << std::endl; }