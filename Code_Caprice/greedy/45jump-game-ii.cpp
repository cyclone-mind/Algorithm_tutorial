#include <vector>
using namespace std;

/*
45. 跳跃游戏 II
中等
相关标签
premium lock icon
相关企业
给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。

每个元素 nums[i] 表示从索引 i 向后跳转的最大长度。换句话说，如果你在 nums[i]
处，你可以跳转到任意 nums[i + j] 处:

0 <= j <= nums[i]
i + j < n
返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。



示例 1:

输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3
步到达数组的最后一个位置。 示例 2:

输入: nums = [2,3,0,1,4]
输出: 2


提示:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
题目保证可以到达 nums[n-1]
*/

/**
 * 使用贪心算法解决跳跃游戏II
 * 贪心策略：在每一步中，尽可能探索更远的位置，当必须跳跃时选择最优方案
 *
 * 算法思路：
 * 1. curEnd: 当前跳跃次数下能到达的边界位置
 * 2. farthest: 在遍历过程中发现的能到达的最远位置
 * 3. 当遍历到当前边界时，说明必须增加一次跳跃才能继续前进
 * 4. 此时将边界更新为目前发现的最远位置
 *
 * 核心思想：把问题分层，每一层代表相同跳跃次数能到达的位置范围
 *
 * @param nums 输入数组
 * @return 最小跳跃次数
 */
int jump(vector<int> &nums) {
    int n = nums.size();

    // 如果只有一个元素，不需要跳跃
    if (n <= 1)
        return 0;

    int jumps = 0;    // 跳跃次数
    int curEnd = 0;   // 当前跳跃次数下的边界位置
    int farthest = 0; // 遍历过程中发现的最远可达位置

    // 遍历数组，注意不需要遍历最后一个元素
    // 因为题目保证能到达最后一个位置
    for (int i = 0; i < n - 1; i++) {
        // 更新在遍历过程中发现的最远可达位置
        // 从位置i可以跳到i + nums[i]的位置
        farthest = max(farthest, i + nums[i]);

        // 如果遍历到了当前跳跃次数的边界
        // 说明必须增加一次跳跃才能继续前进
        if (i == curEnd) {
            jumps++;           // 跳跃次数+1
            curEnd = farthest; // 更新新的边界位置

            // 如果新边界已经能够到达最后一个位置，提前结束
            if (curEnd >= n - 1) {
                break;
            }
        }
    }

    return jumps;
}