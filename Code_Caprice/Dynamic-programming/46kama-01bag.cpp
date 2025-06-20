/*
46. 携带研究材料（第六期模拟笔试）
题目描述
小明是一位科学家，他需要参加一场重要的国际科学大会，以展示自己的最新研究成果。他需要带一些研究材料，但是他的行李箱空间有限。这些研究材料包括实验设备、文献资料和实验样本等等，它们各自占据不同的空间，并且具有不同的价值。

小明的行李空间为
N，问小明应该如何抉择，才能携带最大价值的研究材料，每种研究材料只能选择一次，并且只有选与不选两种选择，不能进行切割。

输入描述
第一行包含两个正整数，第一个整数 M 代表研究材料的种类，第二个正整数
N，代表小明的行李空间。

第二行包含 M 个正整数，代表每种研究材料的所占空间。

第三行包含 M 个正整数，代表每种研究材料的价值。

输出描述
输出一个整数，代表小明能够携带的研究材料的最大价值。
输入示例
6 1
2 2 3 1 5 2
2 3 1 5 4 3
输出示例
5
提示信息
小明能够携带 6 种研究材料，但是行李空间只有 1，而占用空间为 1 的研究材料价值为
5，所以最终答案输出 5。

数据范围：
1 <= N <= 5000
1 <= M <= 5000
研究材料占用空间和价值都小于等于 1000
*/
#include <iostream>
#include <vector>

// int main() {
//     int n, bagweight;
//     std::cin >> n >> bagweight;
//     std::vector<int> weight(n, 0);
//     std::vector<int> value(n, 0);
//     for (int i = 0; i < n; i++) {
//         std::cin >> weight[i];
//     }
//     for (int j = 0; j < n; j++) {
//         std::cin >> value[j];
//     }
//     std::vector<std::vector<int>> dp(n, std::vector<int>(bagweight + 1, 0));
//     for (int j = weight[0]; j < bagweight + 1; j++) {
//         dp[0][j] = value[0];
//     }
//     for (int i = 1; i < n; i++) {
//         for (int j = 1; j < bagweight + 1; j++) {
//             if (j < weight[i])
//                 dp[i][j] = dp[i - 1][j];
//             else {
//                 dp[i][j] =
//                     std::max(dp[i - 1][j], dp[i - 1][j - weight[i]] +
//                     value[i]);
//             }
//         }
//     }
//     // 输出小明能够携带的研究材料的最大价值
//     std::cout << dp[n - 1][bagweight] << std::endl;
//     return 0;
// }

int main() {
    int n, bagweight;
    std::cin >> n >> bagweight;
    std::vector<int> weight(n, 0);
    std::vector<int> value(n, 0);
    // 读取研究材料的重量（占用空间）
    for (int i = 0; i < n; i++) {
        std::cin >> weight[i];
    }
    // 读取研究材料的价值
    for (int j = 0; j < n; j++) {
        std::cin >> value[j];
    }

    // 定义一维dp数组，dp[j] 表示容量为j的背包所能装载的最大价值
    // 这里的dp数组其实就是滚动数组，它省去了表示物品的维度i
    // dp数组的初始化在C++中全局或静态变量默认为0，局部变量需要手动初始化。
    // 这里因为是局部变量，所以初始化为n个0，但实际需要的容量是bagweight + 1
    // 应该初始化为 std::vector<int> dp(bagweight + 1, 0);
    // 来表示所有背包容量的最大价值
    std::vector<int> dp(bagweight + 1, 0);

    // 遍历每一个研究材料（物品）
    for (int i = 0; i < n; i++) { // i 表示当前考虑的是第 i 个物品
        // 逆序遍历背包容量j
        // 为什么要逆序？
        // 如果正序遍历 j，比如计算 dp[j] 时，dp[j - weight[i]] 已经被当前物品 i
        // 更新过，
        // 这样会导致同一个物品被重复放入背包，违背了0/1背包每种物品只能选择一次的原则。
        // 逆序遍历可以确保 dp[j - weight[i]] 引用的是上一轮（即未考虑当前物品 i
        // 时）的状态， 从而保证每个物品只被选择一次。
        for (int j = bagweight; j >= weight[i]; j--) { // j 表示背包当前的容量
            // 状态转移方程：
            // dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
            // dp[j] 代表两种情况：
            // 1. 不放入当前物品 i：此时背包容量 j 的最大价值就是 dp[j]
            // (沿用上一轮的值)
            // 2. 放入当前物品 i：此时背包容量 j 的最大价值是 dp[j - weight[i]]
            // (剩余容量的最大价值) + value[i] (当前物品的价值)
            // 我们取这两种情况的最大值
            dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    // 最终 dp[bagweight] 就是小明能够携带的研究材料的最大价值
    std::cout << dp[bagweight] << std::endl;
    return 0; // 添加 return 0; 使 main 函数完整
}