//  给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

// 示例 1: 输入: s = "anagram", t = "nagaram" 输出: true

// 示例 2: 输入: s = "rat", t = "car" 输出: false

// 说明: 你可以假设字符串只包含小写字母。
#include <string>

using namespace std;

bool isAnagram(string s, string t)
{
    int nums[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        nums[s[i] - 'a']++;
    }
    for (int i = 0; i < t.size(); i++)
    {
        nums[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (nums[i] != 0)
        {
            return false;
        }
    }
    return true;
};

int main(){}
