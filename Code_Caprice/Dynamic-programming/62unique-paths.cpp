/*
62. 不同路径
中等
相关标签
premium lock icon
相关企业
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 "Start" ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为
"Finish" ）。

问总共有多少条不同的路径？

示例 1：


输入：m = 3, n = 7
输出：28
示例 2：

输入：m = 3, n = 2
输出：3
解释：
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右
3. 向下 -> 向右 -> 向下
示例 3：

输入：m = 7, n = 3
输出：28
示例 4：

输入：m = 3, n = 3
输出：6


提示：

1 <= m, n <= 100
题目数据保证答案小于等于 2 * 109
*/

#include <vector>
using namespace std;
#include <iostream>

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        dp[0][i] = 1;
    }
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

int uniquePathsOptimized(int m, int n) {
    // dp[j] 表示到达当前行第 j 列的路径数
    // 初始化 dp 数组，第一行的所有位置都只有 1 条路径
    vector<int> dp(n, 1);

    // 从第二行开始遍历
    for (int i = 1; i < m; ++i) {
        // 对于每一行，从第二列开始遍历
        // 因为 dp[0] （第一列）始终为 1，无需更新
        for (int j = 1; j < n; ++j) {
            // dp[j] （当前位置）的路径数 =
            // 1. 从左边过来的路径数 (dp[j-1]，此时 dp[j-1]
            // 已经更新为当前行的值)
            // 2. 从上面下来的路径数 (dp[j]，此时 dp[j] 仍是上一行的值)
            dp[j] = dp[j] + dp[j - 1];
        }
    }
    // 返回右下角的路径数
    return dp[n - 1];
}

int main() {
    int result = uniquePaths(7, 3);
    std::cout << "Original uniquePaths result: " << result << std::endl;

    int result_optimized = uniquePathsOptimized(7, 3);
    std::cout << "Optimized uniquePaths result: " << result_optimized
              << std::endl;
}