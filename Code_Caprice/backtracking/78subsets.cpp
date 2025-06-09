/*
78. 子集
中等
相关标签
premium lock icon
相关企业
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

示例 1：

输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
*/
#include <vector>
using namespace std;

vector<vector<int>> result;
vector<int> path;

void backtracking(vector<int>& nums, int startIndex){
    result.push_back(path);
    if(startIndex >= nums.size()){
        return;
    }
    for(int i = startIndex;i<nums.size();i++){
        path.push_back(nums[i]);
        backtracking(nums, i + 1);
        path.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    result.clear();
    path.clear();
    backtracking(nums, 0);
    return result;
}

int main(){}