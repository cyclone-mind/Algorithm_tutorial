/*
给你一个字符串 s ，请你反转字符串中 单词 的顺序。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。



示例 1：

输入：s = "the sky is blue"
输出："blue is sky the"
示例 2：

输入：s = "  hello world  "
输出："world hello"
解释：反转后的字符串中不能存在前导空格和尾随空格。
示例 3：

输入：s = "a good   example"
输出："example good a"
解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。


提示：

1 <= s.length <= 104
s 包含英文大小写字母、数字和空格 ' '
s 中 至少存在一个 单词
*/
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

void removeExtraSpaces(string &s)
{
    int slow = 0; // 慢指针，用于构建处理后的字符串，指向下一个要写入的位置
    for (int fast = 0; fast < s.size(); fast++) // 快指针，遍历原始字符串
    {
        // 核心逻辑：如果快指针遇到了一个非空格字符 (即一个单词的开始)
        if (s[fast] != ' ')
        {
            // 步骤1：在单词前添加一个空格 (如果它不是第一个单词的话)
            // 只有当 slow > 0 时 (说明前面已经有单词被复制了)，才会在当前单词前面添加一个空格。
            // 这确保了单词之间只有一个空格，并且不会在字符串开头添加多余的空格。
            if (slow != 0)
                s[slow++] = ' '; // 写入一个空格，并移动慢指针

            // 步骤2：复制当前单词
            // fast 指针继续前进，逐个字符地将当前单词复制到 slow 指针指向的位置
            while (fast < s.size() && s[fast] != ' ')
            {
                s[slow++] = s[fast++]; // 复制字符，同时移动快慢指针
            }
            // 注意：当内层 while 循环结束时，fast 会停在当前单词后面的第一个空格 (或字符串末尾)
            // 外层 for 循环的 fast++ 会进一步将 fast 移动到下一个位置
        }
        // 如果 s[fast] 是空格，那么外层 for 循环会直接跳过这个 if 块，
        // 从而有效地跳过所有连续的空格，直到 fast 再次遇到一个非空格字符 (新单词的开始)。
    }
    // 步骤3：调整字符串大小
    // 循环结束后，slow 指针会指向处理后字符串的有效长度。
    // 使用 resize 截断字符串，移除所有多余的字符 (包括原字符串末尾可能有的多余空格)。
    s.resize(slow);
}

void reverse(string &s, int start, int end)
{ // 翻转，区间写法：左闭右闭 []
    for (int i = start, j = end; i < j; i++, j--)
    {
        swap(s[i], s[j]);
    }
}

string reverseWords(string s)
{
    removeExtraSpaces(s);
    reverse(s, 0, s.size() - 1);
    int left = 0;
    for (int right = 0; right <= s.size(); right++)
    {
        if (s[right] == ' ' || right == s.size())
        {
            reverse(s, left, right - 1);
            left = right + 1;
        }
    }
    return s;
}

int main()
{
    string s = "  hello   wordddld  ";
    string news = reverseWords(s);
    std::cout << news << std::endl;
}