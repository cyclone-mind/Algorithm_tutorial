/*
40. 组合总和 II
中等
相关标签
premium lock icon
相关企业
给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates
中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用 一次 。

注意：解集不能包含重复的组合。
*/

#include <algorithm>
#include <vector>

std::vector<std::vector<int>> result;
std::vector<int> path;

void backtracking(std::vector<int> &candidates, int target, int sum,
                  int startIndex, std::vector<bool> &used) {
    if (sum > target)
        return;
    if (sum == target) {
        result.push_back(path);
        return;
    }

    for (int i = startIndex; i < candidates.size(); i++) {
        if (i > 0 && candidates[i] == candidates[i - 1] &&
            used[i - 1] == false) {
            continue;
        }
        path.push_back(candidates[i]);
        sum += candidates[i];
        used[i] = true;
        backtracking(candidates, target, sum, i + 1, used);
        sum -= candidates[i];
        used[i] = false;
        path.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates,
                                              int target) {
    result.clear();
    path.clear();
    std::vector<bool> used(candidates.size(), false);
    sort(candidates.begin(), candidates.end());
    backtracking(candidates, target, 0, 0, used);
    return result;
}

int main() {}