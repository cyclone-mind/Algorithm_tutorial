/*
96. 不同的二叉搜索树
中等
相关标签
premium lock icon
相关企业
给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树
有多少种？返回满足题意的二叉搜索树的种数。

示例 1：

输入：n = 3
输出：5
示例 2：

输入：n = 1
输出：1


提示：

1 <= n <= 19
*/
#include <vector>
using namespace std;
#include <iostream>

int numTrees(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;                         // 0个节点，一种情况（空树）
    for (int i = 1; i <= n; i++) {     // 遍历节点数 i
        for (int j = 1; j <= i; j++) { // 遍历以 j 为根节点的情况
            // 当 j 为根节点时，左子树有 j-1 个节点，右子树有 i-j 个节点
            // 结果是左子树数量 * 右子树数量，并累加到 dp[i]
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    for(int i = 0;i < dp.size();i++){
        std::cout << dp[i];
    }
    return dp.back();
}
int main() {
    int num = numTrees(3) ;
    // std::cout << numTrees(3) << std::endl;
}