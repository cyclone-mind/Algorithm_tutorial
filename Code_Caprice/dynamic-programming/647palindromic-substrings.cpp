/*
647. 回文子串
中等
相关标签
premium lock icon
相关企业
提示
给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。

回文字符串 是正着读和倒过来读一样的字符串。

子字符串 是字符串中的由连续字符组成的一个序列。
*/
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#if 0
// 动态规划方法
int countSubstrings(string s) {
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    int result = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        for (int j = i; j < s.size(); j++) {
            if (s[i] == s[j]) {
                if (j - i <= 1) {
                    result++;
                    dp[i][j] = true;
                } else if (dp[i + 1][j - 1]) {
                    result++;
                    dp[i][j] = true;
                }
            }
        }
    }
    return result;
}
#endif
int extend(const string& s,int l,int r){
    int count = 0;
    while(l >=0 && r < s.size() && s[l] == s[r]){
        count++;
        l--;
        r++;
    }
    return count;
}
int countSubstrings(string s) {
    int result = 0;
    for(int i = 0;i < s.size();i++){
        result += extend(s,i,i);
        result += extend(s,i,i+1);
    }
    return result;
}

