/*
115. 不同的子序列
困难
相关标签
premium lock icon
相关企业
给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数。

测试用例保证结果在 32 位有符号整数范围内。

 

示例 1：

输入：s = "rabbbit", t = "rabbit"
输出：3
解释：
如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
rabbbit
rabbbit
rabbbit
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int numDistinct(string s, string t) {
    vector<vector<unsigned int>> dp(s.size() + 1, vector<unsigned int>(t.size() + 1,0));
    for(int j = 0;j < t.size() + 1;j++) dp[0][j] = 0;
    for(int i = 0;i < s.size() + 1;i++) dp[i][0] = 1;
    for(int i = 1;i < s.size() + 1;i++){
        for(int j = 1;j < t.size() + 1;j++){
            if(s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; 
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[s.size()][t.size()]; 
}
int main(){
    string s = "rabbbit", t = "rabbit";
    cout << numDistinct(s, t) << endl;
}
