/*
47. 全排列 II
中等
相关标签
premium lock icon
相关企业
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

示例 1：

输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
示例 2：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 
提示：

1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/

#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> result;
vector<int> path;

void backtracking(vector<int>& nums, vector<bool>used){
    if(path.size() == nums.size()){
        result.push_back(path);
        return;
    }
    for (int i = 0;i<nums.size();i++){
        if(i >0 && nums[i] == nums[i - 1] && used[i - 1] == false){
            continue;
        }
        if(used[i] == false){
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    result.clear();
    path.clear();
    sort(nums.begin(), nums.end());
    vector<bool> used(nums.size(), false);
    backtracking(nums, used);
    return result;
}

int main(){}