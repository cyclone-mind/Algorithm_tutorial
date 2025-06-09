/*
46. 全排列
中等
相关标签
premium lock icon
相关企业
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

示例 1：
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

示例 2：
输入：nums = [0,1]
输出：[[0,1],[1,0]]

示例 3：
输入：nums = [1]
输出：[[1]]
 
提示：

1 <= nums.length <= 6
-10 <= nums[i] <= 10
nums 中的所有整数 互不相同
*/

#include <vector>
using namespace std;

vector<vector<int>> result;
vector<int> path;

void backtracking(vector<int>& nums, vector<bool>& used){
    if(path.size() == nums.size()){
        result.push_back(path);
        return;
    }
    for(int i = 0; i <nums.size();i++){
        if(used[i] == true){
            continue;
        }
        used[i] = true;
        path.push_back(nums[i]);
        backtracking(nums, used);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    result.clear();
    path.clear();
    vector<bool> used(nums.size(), false);
    backtracking(nums, used);
    return result; 
}

int main(){}