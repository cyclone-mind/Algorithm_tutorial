/*
56. 携带矿石资源（第八期模拟笔试）
题目描述
你是一名宇航员，即将前往一个遥远的行星。在这个行星上，有许多不同类型的矿石资源，每种矿石都有不同的重要性和价值。你需要选择哪些矿石带回地球，但你的宇航舱有一定的容量限制。

给定一个宇航舱，最大容量为 C。现在有 N 种不同类型的矿石，每种矿石有一个重量
w[i]，一个价值 v[i]，以及最多 k[i]
个可用。不同类型的矿石在地球上的市场价值不同。你需要计算如何在不超过宇航舱容量的情况下，最大化你所能获取的总价值。

输入描述
输入共包括四行，第一行包含两个整数 C 和
N，分别表示宇航舱的容量和矿石的种类数量。

接下来的三行，每行包含 N 个正整数。具体如下：

第二行包含 N 个整数，表示 N 种矿石的重量。

第三行包含 N 个整数，表示 N 种矿石的价格。

第四行包含 N 个整数，表示 N 种矿石的可用数量上限。

输出描述
输出一个整数，代表获取的最大价值。
输入示例
10 3
1 3 4
15 20 30
2 3 2
输出示例
90
提示信息
数据范围：
1 <= C <= 2000;
1 <= N <= 100;
1 <= w[i], v[i], k[i] <= 1000;
*/
#include <iostream>
#include <vector>
int main() {
    int C, N;
    std::cin >> C >> N;
    std::vector<int> weight(N, 0);
    std::vector<int> price(N, 0);
    std::vector<int> nums(N, 0);
    for (int i = 0; i < N; i++) {
        std::cin >> weight[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> price[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> nums[i];
    }

    for (int i = 0; i < N; i++) {
        while (nums[i] > 1) {
            weight.push_back(weight[i]);
            price.push_back(price[i]);
            nums[i]--;
        }
    }
    std::vector<int> dp(C+1,0);
    for(int i = 0;i< weight.size();i++){
        for(int j = C; j >= weight[i]; j--){
            dp[j] = std::max(dp[j],dp[j - weight[i]] + price[i]);
        }
    }
    std::cout << dp[C] << std::endl;
}