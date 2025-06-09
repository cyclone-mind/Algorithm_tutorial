/*
131. 分割回文串
中等
相关标签
premium lock icon
相关企业
给你一个字符串 s，请你将 s 分割成一些 子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
*/

#include <vector>
#include <string>
using namespace std;

vector<vector<string>> result;
vector<string> path;

bool isPlainDrome(const string&s,int start, int end){
    for(int i =start,j = end;i<j;i++,j--){
        if(s[i] != s[j]){
            return false;
        }
    }
    return true;
}

void backtracking(const string& s,int startIndex){
    // 终止条件: 起始位置是最后是说明已经遍历到叶子节点，找到了一组分割方案
    if(startIndex >= s.size()){
        result.push_back(path);
        return;
    }
    for(int i = startIndex;i<s.size();i++){ // 一个for循环就是一层
        if(isPlainDrome(s,startIndex,i)){
            string substr = s.substr(startIndex, i-startIndex +1); // 取出回文子串
            path.push_back(substr);
        } else {
            continue; // 不是回文子串就没必要向下遍历，在当前层往右移动即可
        }
        backtracking(s,  i + 1); // 向下遍历
        path.pop_back();
    }
}


vector<vector<string>> partition(string s) {
    result.clear();
    path.clear();
    backtracking(s, 0);
    return result;
}

int main(){}