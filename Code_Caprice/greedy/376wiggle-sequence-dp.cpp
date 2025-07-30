/*
376. 摆动序列 - 动态规划解法
思路：
dp[i][0] 表示以nums[i]结尾的最长摆动序列长度，且nums[i-1] < nums[i]（上升）
dp[i][1] 表示以nums[i]结尾的最长摆动序列长度，且nums[i-1] > nums[i]（下降）
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 动态规划解法求摆动序列最大长度
 * @param nums 输入数组
 * @return 最长摆动序列长度
 */
int wiggleMaxLengthDP(vector<int> &nums) {
    if (nums.size() < 2)
        return nums.size();

    // dp[i][0]: 以第i个元素结尾，且第i-1到第i是上升的最长摆动序列长度
    // dp[i][1]: 以第i个元素结尾，且第i-1到第i是下降的最长摆动序列长度
    vector<vector<int>> dp(nums.size(), vector<int>(2, 1));

    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                // 当前是上升，之前应该是下降
                dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            } else if (nums[i] < nums[j]) {
                // 当前是下降，之前应该是上升
                dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }
        }
    }

    int result = 1;
    for (int i = 0; i < nums.size(); i++) {
        result = max(result, max(dp[i][0], dp[i][1]));
    }

    return result;
}

/**
 * 优化的动态规划解法（O(n)时间复杂度）
 * @param nums 输入数组
 * @return 最长摆动序列长度
 */
int wiggleMaxLengthDPOptimized(vector<int> &nums) {
    if (nums.size() < 2)
        return nums.size();

    // up: 当前位置结尾且最后一段上升的最长摆动序列长度
    // down: 当前位置结尾且最后一段下降的最长摆动序列长度
    int up = 1, down = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1]) {
            // 上升：可以在之前下降序列基础上+1
            up = down + 1;
        } else if (nums[i] < nums[i - 1]) {
            // 下降：可以在之前上升序列基础上+1
            down = up + 1;
        }
        // 如果相等，up和down都不变
    }

    return max(up, down);
}

int main() {
    vector<int> nums1 = {1, 7, 4, 9, 2, 5};
    vector<int> nums2 = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "测试用例1: [1,7,4,9,2,5]" << endl;
    cout << "DP解法: " << wiggleMaxLengthDP(nums1) << endl;
    cout << "优化DP: " << wiggleMaxLengthDPOptimized(nums1) << endl;

    cout << "\n测试用例2: [1,17,5,10,13,15,10,5,16,8]" << endl;
    cout << "DP解法: " << wiggleMaxLengthDP(nums2) << endl;
    cout << "优化DP: " << wiggleMaxLengthDPOptimized(nums2) << endl;

    cout << "\n测试用例3: [1,2,3,4,5,6,7,8,9]" << endl;
    cout << "DP解法: " << wiggleMaxLengthDP(nums3) << endl;
    cout << "优化DP: " << wiggleMaxLengthDPOptimized(nums3) << endl;

    return 0;
}