/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。
*/
#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> result;
    // 先对数组进行排序，方便后续去重和双指针查找
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        // 如果当前数字大于0，后面不可能有三数之和为0，直接结束
        if (nums[i] > 0)
            break;
        // 跳过重复的第一个数，避免三元组重复
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int left = i + 1, right = nums.size() - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0)
            {
                result.push_back({nums[i], nums[left], nums[right]});
                // 跳过重复的 left
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                // 跳过重复的 right
                while (left < right && nums[right] == nums[right - 1])
                    right--;
                left++;
                right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return result;
}

int main()
{
    // 简单测试用例
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = threeSum(nums);
    cout << "三数之和为0的三元组有：" << endl;
    for (auto &triplet : res)
    {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    return 0;
}