/*
763. 划分字母区间
中等
相关标签
premium lock icon
相关企业
提示
给你一个字符串 s
。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。例如，字符串
"ababcc" 能够被分为 ["abab", "cc"]，但类似 ["aba", "bcc"] 或 ["ab", "ab", "cc"]
的划分是非法的。

注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。

返回一个表示每个字符串片段的长度的列表。

示例 1：
输入：s = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。
示例 2：

输入：s = "eccbbbbdec"
输出：[10]

提示：

1 <= s.length <= 500
s 仅由小写英文字母组成
*/

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 该函数用于将字符串划分为尽可能多的片段，每个字母最多出现在一个片段中
// 贪心思想：每次尽量扩展当前片段的右边界，直到遇到所有当前片段内字母的最远出现位置
vector<int> partitionLabels(string s) {
    int hash[27] = {0}; // 记录每个字母最后一次出现的位置
    vector<int> result; // 存储每个片段的长度
    // 第一次遍历，记录每个字母最后出现的位置
    for (int i = 0; i < s.size(); i++) {
        hash[s[i] - 'a'] = i;
    }
    int left = 0, right = 0; // left为当前片段的起始，right为当前片段的最远边界
    // 第二次遍历，贪心地扩展区间
    for (int i = 0; i < s.size(); i++) {
        right = max(right, hash[s[i] - 'a']); // 更新当前片段的最远边界
        if (right == i) { // 如果当前下标等于最远边界，说明可以分割
            result.push_back(right - left + 1); // 记录当前片段长度
            left = i + 1;                       // 更新下一个片段的起始位置
        }
    }
    return result;
}


int main() {
    // 示例：
    string s = "ababcbacadefegdehijhklij";
    vector<int> res = partitionLabels(s);
    for(int len : res) cout << len << " "; // 输出: 9 7 8
}