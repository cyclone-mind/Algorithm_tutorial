/*
1049. 最后一块石头的重量 II
中等
相关标签
premium lock icon
相关企业
提示
有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。

每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。

示例 1：

输入：stones = [2,7,4,1,8,1]
输出：1
解释：
组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
示例 2：

输入：stones = [31,26,33,21,40]
输出：5
 
提示：

1 <= stones.length <= 30
1 <= stones[i] <= 100
*/
#include <vector>
using namespace std;
#include <iostream>

// 石头的质量除了湮灭，不会自行消失，因此只需要分出两堆中粮尽可能相似的石头就行，即从集合中选出石头，使重量尽可能接近sum/2
// 转化为背包问题，背包最大重量 sum/2，石头价值和重量均为stone[i]，求sum/2重量的背包所能放的石头的最大价值/最大重量。
// 有了最大价值后，就得出另外一对石头的价值/重量，两者求差值即可



int lastStoneWeightII(vector<int>& stones) {
    vector<int> dp(15001,0);
    int sum = 0;
    for(int i = 0;i< stones.size();i++) sum += stones[i];
    int target = sum / 2;
    for(int i = 0;i < stones.size();i++){
        for(int j = target;j >= stones[i]; j--){
            dp[j] = max(dp[j], dp[j - stones[i]]+stones[i]);
        }
    }
    return sum - dp[target] - dp[target];
}

int main(){
    vector<int> stones = {31,26,33,21,40};
    std:cout << lastStoneWeightII(stones) << std::endl;
}
