/*
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

示例 1：

输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]

示例 2：

输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]
*/

#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        vector<int> result(n, 0);
        int k = n - 1; // 指针k，用于从后往前填充result数组

        while (left <= right)
        {
            // 使用long long避免平方后整数溢出，尽管对于此题int可能足够
            long long square_left = static_cast<long long>(nums[left]) * nums[left];
            long long square_right = static_cast<long long>(nums[right]) * nums[right];

            if (square_right >= square_left)
            {
                result[k] = square_right;
                right--; // 移动原始数组的右指针
            }
            else
            {
                result[k] = square_left;
                left++; // 移动原始数组的左指针
            }
            k--; // 结果数组的填充指针向前移动
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> nums{-4, -1, 0, 3, 10};

    vector<int> new_nums = solution.sortedSquares(nums);
    for (size_t i = 0; i < new_nums.size(); i++)
    {
        /* code */
        cout << new_nums[i] << " ";
    }
}