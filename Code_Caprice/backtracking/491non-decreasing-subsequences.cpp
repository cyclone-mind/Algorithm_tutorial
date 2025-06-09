/*
491. 非递减子序列
中等
相关标签
premium lock icon
相关企业
给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。

数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。

 

示例 1：

输入：nums = [4,6,7,7]
输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
示例 2：

输入：nums = [4,4,3,2,1]
输出：[[4,4]]
 

提示：

1 <= nums.length <= 15
-100 <= nums[i] <= 100
*/

#include <vector>
using namespace std;

vector<vector<int>> result;
vector<int> path;

void backtracking(vector<int>& nums, int startIndex){
    if(path.size() > 1) {
        result.push_back(path);
    }
    int used[201] = {0}; 
    for(int i = startIndex;i < nums.size();i++){
        
        if(!path.empty()  && nums[i] < path.back() || used[nums[i] + 100] == 1){
            continue;
        }
        path.push_back(nums[i]);
        used[nums[i] + 100] = 1;
        backtracking(nums, i+1);
        path.pop_back();
    }
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    result.clear();
    path.clear();
    backtracking(nums, 0);
    return result;
}

int main(){}