/*
题意：给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例： 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。 满足要求的四元组集合为： [ [-1, 0, 0, 1], [-2, -1, 1, 2], [-2, 0, 0, 2] ]

*/

#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int k = 0; k < nums.size(); k++)
    {
        if (nums[k] > target && nums[k] > 0)
        {
            break;
        }
        if (k > 0 && nums[k] == nums[k - 1])
        {
            continue;
        }
        for (int i = k + 1; i < nums.size(); i++)
        {
            // 2级剪枝处理
            if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0)
            {
                break;
            }

            // 对nums[i]去重
            if (i > k + 1 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                long sum = (long)nums[k] + nums[i] + nums[left] + nums[right];
                if (sum == target)
                {
                    result.push_back({nums[k],nums[i], nums[left], nums[right]});
                    // 跳过重复的 left
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    // 跳过重复的 right
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
                else if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        
    }
    return result;
}

int main(){
    vector<int> nums =  {2,2,2,2,2};
    int target = 8;
    vector<vector<int>> result = fourSum(nums,target);

    for(vector<int> vec:result){
        std::cout << "[";
        for (int v:vec){
            std::cout << v << ", ";
        }
        std::cout << "]";
    
    }
}