/*
72. 编辑距离
中等
相关标签
premium lock icon
相关企业
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符


示例 1：

输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
*/

#include <algorithm>
#include <string>
#include <vector>

/**
 * @brief 计算将 word1 转换成 word2 所使用的最少操作数 (编辑距离)
 *
 * 这是一个经典的动态规划问题。
 *
 * @param word1 第一个单词
 * @param word2 第二个单词
 * @return int 最少操作数
 */
int minDistance(std::string word1, std::string word2) {
    int m = word1.length();
    int n = word2.length();
    

    // dp[i][j] 表示 word1 中由前 i 个字符组成的子串 (word1[0...i-1])
    // 转换成 word2 中由前 j 个字符组成的子串 (word2[0...j-1])
    // 所用的最少操作数。 数组大小 +1 是因为我们需要包含一个空字符串的状态
    // (即长度为0的子串)。
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    // 初始化第0列: word1 的子串转换为 ""
    // word1 的前 i 个字符组成的子串要变成空串，需要 i 次删除
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i;
    }

    // 初始化第0行: "" 转换为 word2
    // 空串要变成 word2 的前 j 个字符，需要 j 次插入
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j;
    }

    // 通过递推公式填充 dp 表
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            // C++ 中字符串索引从 0 开始, dp 表中 i, j 代表长度, 所以要 -1
            if (word1[i - 1] == word2[j - 1]) {
                // 如果末尾字符相同，则不需要额外操作
                // 结果取决于 word1 前 i-1 个字符和 word2 前 j-1
                // 个字符的编辑距离
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // 如果末尾字符不同，需要进行一次操作
                // min of:
                // 1. 替换: dp[i-1][j-1] + 1 (将 word1[i-1] 替换为 word2[j-1])
                // 2. 删除: dp[i-1][j] + 1 (删除 word1[i-1])
                // 3. 插入: dp[i][j-1] + 1 (在 word1 末尾插入 word2[j-1])
                dp[i][j] =
                    std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) +
                    1;
            }
        }
    }

    // dp[m][n] 存储了 word1 转换为 word2 的最终结果
    return dp[m][n];
}