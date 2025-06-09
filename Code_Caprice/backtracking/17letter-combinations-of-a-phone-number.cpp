/*
17. 电话号码的字母组合
中等
相关标签
premium lock icon
相关企业
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序
返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/
#include <iostream>
#include <string>
#include <vector>

// 全局变量
std::vector<std::string> result;
std::string s;
std::vector<std::string> letterMap = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
};

// 回溯函数
void backtracking(int index, std::string digits) {
    if (index == digits.size()) {
        result.push_back(s);
        return;
    }
    int digit = digits[index] - '0';
    std::string letters = letterMap[digit];
    for (int i = 0; i < letters.size(); i++) {
        s.push_back(letters[i]);
        backtracking(index + 1, digits);
        s.pop_back();
    }
}

// 主函数
std::vector<std::string> letterCombinations(std::string digits) {
    result.clear(); // 清空结果
    s.clear();      // 清空当前字符串
    if (digits.size() == 0) {
        return result;
    }
    backtracking(0, digits);
    return result;
}

int main() {
    std::string digits = "234";
    std::vector<std::string> resulta = letterCombinations(digits);
    for (std::string s : resulta) {
        std::cout << s << std::endl;
    }
    return 0;
}