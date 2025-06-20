/*
139. 单词拆分
中等
相关标签
premium lock icon
相关企业
给你一个字符串 s 和一个字符串列表 wordDict
作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。

注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。



示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
     注意，你可以重复使用字典中的单词。
示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false


提示：

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s 和 wordDict[i] 仅由小写英文字母组成
wordDict 中的所有字符串 互不相同
*/
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// bool wordBreak(string s, vector<string> &wordDict) {
//     unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
//     int n = s.length();
//     // 1. dp[i]代表长度为i的字符串能否由单词字典中的单词拼接而成
//     vector<bool> dp(n + 1, false);
//     dp[0] = true; // 3 初始化，没有实际意义，只是为了满足递推公式的进行

//     // 打印初始状态
//     cout << "字符串: \"" << s << "\"" << endl;
//     cout << "字典: [";
//     for (int k = 0; k < wordDict.size(); k++) {
//         cout << "\"" << wordDict[k] << "\"";
//         if (k < wordDict.size() - 1)
//             cout << ", ";
//     }
//     cout << "]" << endl << endl;

//     cout << "初始状态: dp = [";
//     for (int k = 0; k <= n; k++) {
//         cout << (dp[k] ? "true" : "false");
//         if (k < n)
//             cout << ", ";
//     }
//     cout << "]" << endl;
//     cout << "位置索引:      [";
//     for (int k = 0; k <= n; k++) {
//         cout << k;
//         if (k < n)
//             cout << ",    ";
//     }
//     cout << "]" << endl << endl;

//     for (int j = 1; j <= n; j++) {
//         cout << "=== 计算 dp[" << j << "] (字符串前" << j << "位: \""
//              << s.substr(0, j) << "\") ===" << endl;

//         for (int i = 0; i < j; i++) {
//             string subStr = s.substr(i, j - i);
//             bool inDict = wordSet.count(subStr);

//             cout << "  分割点 i=" << i << ": ";
//             cout << "dp[" << i << "]=" << (dp[i] ? "true" : "false");
//             cout << " && \"" << subStr
//                  << "\"在字典中=" << (inDict ? "true" : "false");

//             // 2.
//             //
//             递归公式，dp[j],要想拼成长度为j的字符串，就依次在j的前面找分割点，如果分割点的前面的字符串能够拼接成，并且剩余的字符串恰好还在单词字典中，则认为能拼成长度为j的字符串
//             if (dp[i] && inDict) {
//                 dp[j] = true;
//                 cout << " → dp[" << j << "] = true ✓" << endl;
//                 break;
//             } else {
//                 cout << " → 不满足条件" << endl;
//             }
//         }

//         // 打印当前dp数组状态
//         cout << "  结果: dp[" << j << "] = " << (dp[j] ? "true" : "false")
//              << endl;
//         cout << "  当前dp = [";
//         for (int k = 0; k <= n; k++) {
//             cout << (dp[k] ? "true" : "false");
//             if (k < n)
//                 cout << ", ";
//         }
//         cout << "]" << endl << endl;
//     }

//     cout << "最终结果: " << (dp[n] ? "可以拆分" : "无法拆分") << endl;
//     return dp[n];
// }

bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int j = 0; j < wordDict.size(); j++) {                // 物品
        for (int i = wordDict[j].size(); i <= s.size(); i++) { // 背包
            string word = s.substr(i - wordDict[j].size(), wordDict[j].size());
            cout << word << endl;
            if (word == wordDict[j] && dp[i - wordDict[j].size()]) {
                dp[i] = true;
            }
            for (int k = 0; k <= s.size(); k++) cout << dp[k] << " ";
            // 这里打印 dp数组的情况 
            cout << endl;
        }
    }
    return dp[s.size()];
}

int main() {
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    std::cout << wordBreak(s, wordDict) << std::endl;
}