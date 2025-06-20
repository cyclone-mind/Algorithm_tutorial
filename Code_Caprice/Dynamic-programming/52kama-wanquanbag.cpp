/*
52. 携带研究材料（第七期模拟笔试）
题目描述
小明是一位科学家，他需要参加一场重要的国际科学大会，以展示自己的最新研究成果。他需要带一些研究材料，但是他的行李箱空间有限。这些研究材料包括实验设备、文献资料和实验样本等等，它们各自占据不同的重量，并且具有不同的价值。

小明的行李箱所能承担的总重量是有限的，问小明应该如何抉择，才能携带最大价值的研究材料，每种研究材料可以选择无数次，并且可以重复选择。

输入描述
第一行包含两个整数，n，v，分别表示研究材料的种类和行李所能承担的总重量

接下来包含 n 行，每行两个整数 wi 和 vi，代表第 i 种研究材料的重量和价值

输出描述
输出一个整数，表示最大价值。
输入示例
4 5
1 2
2 4
3 4
4 5
输出示例
10
提示信息
第一种材料选择五次，可以达到最大值。

数据范围：

1 <= n <= 10000;
1 <= v <= 10000;
1 <= wi, vi <= 10^9.
*/

#include <algorithm>
#include <iostream>
#include <vector>
// 二维dp数组
// int main() {
//     int n, bagWeight;
//     std::cin >> n >> bagWeight;
//     std::vector<int> weight(n, 0);
//     std::vector<int> value(n, 0);
//     for (int i = 0; i < n; i++) {
//         std::cin >> weight[i] >> value[i];
//     }
//     std::vector<std::vector<int>> dp(n, std::vector<int>(bagWeight + 1, 0));
//     for (int j = weight[0]; j <= bagWeight; j++) {
//         dp[0][j] = dp[0][j - weight[0]] + value[0];
//     }
//     for (int i = 1; i < n; i++) {
//         for (int j = 0; j <= bagWeight; j++) {
//             if(j < weight[i]) dp[i][j] = dp[i - 1][j];
//             else 
//             dp[i][j] = std::max(dp[i - 1][j], dp[i][j - weight[i]] + value[i]);
//         }
//     }
//     std::cout << dp[n - 1][bagWeight] << std::endl;
// }

// 一维dp数组
int main(){
    int n,bagWeight;
    std::cin >> n >> bagWeight;
    std::vector<int> weight(n,0);
    std::vector<int> value(n,0);
    for(int i = 0;i < n;i++){
        std::cin >> weight[i] >> value[i];
    }
    std::vector<int> dp(bagWeight + 1,0);
    for(int i = 0;i < n;i++){
        for(int j = weight[i];j <= bagWeight;j++){
            dp[j] = std::max(dp[j],dp[j - weight[i]] + value[i]);
        }
    }
    std::cout << dp[bagWeight] << std::endl;
    return 0;
}
