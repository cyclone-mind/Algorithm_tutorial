/*
216. 组合总和 III
中等
相关标签
premium lock icon
相关企业
找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：

只使用数字1到9
每个数字 最多使用一次 
返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。
*/
#include <vector>

std::vector<std::vector<int>> result;
std::vector<int> path;
void backtracking(int targetSum, int k, int sum, int startIndex){
    if(path.size() == k){
        if (sum == targetSum) {
            result.push_back(path);
        }
        return;
    }
    for (int i = startIndex; i <= 9; i++) {
        sum += i;
        path.push_back(i);
        backtracking(targetSum,k,sum, i+1);
        sum -= i;
        path.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum3(int k, int n) {
    backtracking(n, k, 0, 1);
    return result;
}

int main(){}