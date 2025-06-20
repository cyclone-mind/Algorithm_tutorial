/*
63. 不同路径 II
中等
相关标签
premium lock icon
相关企业
提示
给定一个 m x n 的整数数组 grid。一个机器人初始位于 左上角（即 grid[0][0]）。
机器人尝试移动到 右下角（即 grid[m - 1][n -
1]）。机器人每次只能向下或者向右移动一步。

网格中的障碍物和空位置分别用 1 和 0 来表示。机器人的移动路径中不能包含 任何
有障碍物的方格。

返回机器人能够到达右下角的不同路径数量。

测试用例保证答案小于等于 2 * 10^9。

示例 1：


输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
输出：2
解释：3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右
示例 2

输入：obstacleGrid = [[0,1],[0,0]]
输出：1

提示：

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] 为 0 或 1
*/

#include <vector>
using namespace std;
#include <iostream>

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    // 如果起点就是障碍物，则无法移动，返回 0
    if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
        return 0;
    }
    for (int i = 0; i < n && obstacleGrid[0][i] != 1; i++) {
        dp[0][i] = 1;
    }
    for (int i = 0; i < m && obstacleGrid[i][0] != 1; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] != 1) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1];
}

// 优化版：使用一维数组
int uniquePathsWithObstaclesOptimized(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    // 如果起点就是障碍物，则无法移动，返回 0
    if (obstacleGrid[0][0] == 1) {
        return 0;
    }

    // dp[j] 表示到达当前行第 j 列的路径数
    // 初始化 dp 数组，所有元素为 0
    vector<int> dp(n, 0);

    // 初始化第一行
    // dp[0] 只能从起点到达，如果起点不是障碍物，则 dp[0] 为 1
    dp[0] = 1;
    for (int j = 1; j < n; ++j) {
        // 如果当前位置是障碍物，或者左边的位置不可达，则当前位置不可达
        if (obstacleGrid[0][j] == 1 || dp[j - 1] == 0) {
            dp[j] = 0;
        } else {
            dp[j] = 1;
        }
    }

    // 从第二行开始遍历
    for (int i = 1; i < m; ++i) {
        // 处理当前行的第一列 (dp[0])
        // 如果当前位置 (i, 0) 是障碍物，则 dp[0] 变为 0
        // 否则，dp[0] 保持不变 (即继承上一行 dp[0] 的值，如果上一行 dp[0] 是
        // 0，则当前 dp[0] 也会是 0)
        if (obstacleGrid[i][0] == 1) {
            dp[0] = 0;
        }

        // 遍历当前行的其他列
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[i][j] == 1) {
                // 如果当前位置是障碍物，则路径数为 0
                dp[j] = 0;
            } else {
                // 路径数 = 从上方来的路径数 (dp[j]) + 从左方来的路径数
                // (dp[j-1])
                dp[j] = dp[j] + dp[j - 1];
            }
        }
    }

    // 返回右下角的路径数
    return dp[n - 1];
}

int main() {
    // 示例 1
    vector<vector<int>> obstacleGrid1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int result1_original = uniquePathsWithObstacles(obstacleGrid1);
    std::cout << "Original Example 1 Result: " << result1_original
              << std::endl; // 预期输出 2
    int result1_optimized = uniquePathsWithObstaclesOptimized(obstacleGrid1);
    std::cout << "Optimized Example 1 Result: " << result1_optimized
              << std::endl; // 预期输出 2

    // 示例 2
    vector<vector<int>> obstacleGrid2 = {{0, 1}, {0, 0}};
    int result2_original = uniquePathsWithObstacles(obstacleGrid2);
    std::cout << "Original Example 2 Result: " << result2_original
              << std::endl; // 预期输出 1
    int result2_optimized = uniquePathsWithObstaclesOptimized(obstacleGrid2);
    std::cout << "Optimized Example 2 Result: " << result2_optimized
              << std::endl; // 预期输出 1

    // 示例 3: 起点是障碍物
    vector<vector<int>> obstacleGrid3 = {{1, 0}, {0, 0}};
    int result3_original = uniquePathsWithObstacles(obstacleGrid3);
    std::cout << "Original Example 3 Result: " << result3_original
              << std::endl; // 预期输出 0
    int result3_optimized = uniquePathsWithObstaclesOptimized(obstacleGrid3);
    std::cout << "Optimized Example 3 Result: " << result3_optimized
              << std::endl; // 预期输出 0

    // 示例 4: 只有一行有障碍物
    vector<vector<int>> obstacleGrid4 = {
        {0, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}};
    int result4_original = uniquePathsWithObstacles(obstacleGrid4);
    std::cout << "Original Example 4 Result: " << result4_original
              << std::endl; // 预期输出 4
    int result4_optimized = uniquePathsWithObstaclesOptimized(obstacleGrid4);
    std::cout << "Optimized Example 4 Result: " << result4_optimized
              << std::endl; // 预期输出 4

    return 0;
}