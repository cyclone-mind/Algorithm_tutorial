/*
583. 两个字符串的删除操作
中等
相关标签
premium lock icon
相关企业
给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。

每步 可以删除任意一个字符串中的一个字符。

 

示例 1：

输入: word1 = "sea", word2 = "eat"
输出: 2
解释: 第一步将 "sea" 变为 "ea" ，第二步将 "eat "变为 "ea"
示例  2:

输入：word1 = "leetcode", word2 = "etco"
输出：4
 

提示：

1 <= word1.length, word2.length <= 500
word1 和 word2 只包含小写英文字母
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;
int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i = 1;i < m+1;i++){
        for(int j = 1;j < n+1;j++){
            if(word1[i - 1] == word2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1],dp[i - 1][j]);
            }
        }
    }
    return m + n - dp[m][n]*2;
}
int main(){
    string str1 = "sea";
    string str2 = "eat";
    cout << minDistance(str1, str2) << endl;
}