/*
90. 子集 II
中等
相关标签
premium lock icon
相关企业
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的 子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

示例 1：

输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
 
提示：

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/


#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> result;
vector<int> path;

void backtracking(vector<int>& nums, int startIndex, vector<bool>& used){
    result.push_back(path);
    for(int i = startIndex; i<nums.size();i++){
        if (i > 0 && nums[i] == nums[i - 1] &&
            used[i - 1] == false) {
            continue;
        }
        path.push_back(nums[i]);
        used[i] = true;
        backtracking(nums, i + 1, used);
        used[i] = false;
        path.pop_back();
    }
}


vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    result.clear();
    path.clear();
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());
    backtracking(nums, 0, used);
    return result;
}

int main(){}