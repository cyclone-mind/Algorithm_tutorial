/*
376. 摆动序列 - 递归+记忆化解法
思路：对于每个位置，尝试选择或不选择，并记录前一个选择的元素和趋势
*/
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class WiggleSequenceMemo {
  private:
    // 记忆化缓存：key = (当前位置 << 16) | (上一个位置 << 1) | 趋势
    unordered_map<long long, int> memo;
    vector<int> nums;

    /**
     * 递归求解摆动序列
     * @param pos 当前位置
     * @param prevPos 上一个选择的位置（-1表示没有）
     * @param ascending 上一次变化是否为上升（true=上升，false=下降）
     * @return 从当前位置开始的最长摆动序列长度
     */
    int dfs(int pos, int prevPos, bool ascending) {
        if (pos >= nums.size())
            return 0;

        // 构造缓存key
        long long key = ((long long)pos << 16) |
                        ((long long)(prevPos + 1) << 1) | (ascending ? 1 : 0);
        if (memo.count(key)) {
            return memo[key];
        }

        int result = 0;

        // 选择1：不选择当前元素
        result = max(result, dfs(pos + 1, prevPos, ascending));

        // 选择2：选择当前元素（如果可以的话）
        if (prevPos == -1) {
            // 第一个元素，可以直接选择
            result =
                max(result, 1 + dfs(pos + 1, pos, true)); // 假设下一次是上升
            result =
                max(result, 1 + dfs(pos + 1, pos, false)); // 假设下一次是下降
        } else {
            // 检查是否满足摆动条件
            if (nums[pos] > nums[prevPos] && !ascending) {
                // 当前是上升，且之前是下降，满足摆动条件
                result = max(result, 1 + dfs(pos + 1, pos, true));
            } else if (nums[pos] < nums[prevPos] && ascending) {
                // 当前是下降，且之前是上升，满足摆动条件
                result = max(result, 1 + dfs(pos + 1, pos, false));
            }
        }

        memo[key] = result;
        return result;
    }

  public:
    /**
     * 求摆动序列最大长度
     * @param nums 输入数组
     * @return 最长摆动序列长度
     */
    int wiggleMaxLength(vector<int> &nums) {
        if (nums.size() <= 1)
            return nums.size();

        this->nums = nums;
        memo.clear();

        return dfs(0, -1, true);
    }
};

/**
 * 递归辅助函数
 * @param nums 数组
 * @param pos 当前位置
 * @param needUp 下一个变化是否需要上升
 * @return 从当前位置开始能形成的最长摆动序列长度
 */
int helper(vector<int> &nums, int pos, bool needUp) {
    int maxLen = 0;

    for (int i = pos + 1; i < nums.size(); i++) {
        if ((needUp && nums[i] > nums[pos]) ||
            (!needUp && nums[i] < nums[pos])) {
            maxLen = max(maxLen, 1 + helper(nums, i, !needUp));
        }
    }

    return maxLen;
}

/**
 * 简化版递归解法（不用记忆化）
 * @param nums 输入数组
 * @return 最长摆动序列长度
 */
int wiggleMaxLengthRecursive(vector<int> &nums) {
    if (nums.size() <= 1)
        return nums.size();

    // 分别尝试第一个摆动是上升和下降
    return max(1 + helper(nums, 0, true), 1 + helper(nums, 0, false));
}

int main() {
    vector<int> nums1 = {1, 7, 4, 9, 2, 5};
    vector<int> nums2 = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    WiggleSequenceMemo solution;

    cout << "测试用例1: [1,7,4,9,2,5]" << endl;
    cout << "递归+记忆化: " << solution.wiggleMaxLength(nums1) << endl;
    cout << "简单递归: " << wiggleMaxLengthRecursive(nums1) << endl;

    cout << "\n测试用例2: [1,17,5,10,13,15,10,5,16,8]" << endl;
    cout << "递归+记忆化: " << solution.wiggleMaxLength(nums2) << endl;
    cout << "简单递归: " << wiggleMaxLengthRecursive(nums2) << endl;

    cout << "\n测试用例3: [1,2,3,4,5,6,7,8,9]" << endl;
    cout << "递归+记忆化: " << solution.wiggleMaxLength(nums3) << endl;
    cout << "简单递归: " << wiggleMaxLengthRecursive(nums3) << endl;

    return 0;
}