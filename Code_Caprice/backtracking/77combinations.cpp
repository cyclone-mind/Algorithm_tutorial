/*
77. 组合
中等
相关标签
premium lock icon
相关企业
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。
*/
#include <vector>

std::vector<std::vector<int>> result;
std::vector<int> path;
void backtracking(int n, int k, int startIndex){
    if(path.size() == k){
        result.push_back(path);
        return;
    }
    for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
        path.push_back(i);
        backtracking(n,k, i+1);
        path.pop_back();
    }
}

std::vector<std::vector<int>> combine(int n, int k) {
    backtracking(n, k, 1);
    return result;
}

int main(){}