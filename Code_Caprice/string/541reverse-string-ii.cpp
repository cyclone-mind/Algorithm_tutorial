/*

给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

*/
#include <string>
#include <algorithm>
using namespace std;

string reverseStr(string s, int k)
{
    for (int i = 0; i < s.size(); i += (2 * k))
    {
        if (i + k <= s.size())
        {
            reverse(s.begin() + i, s.begin() + i + k);
        }
        else
        {
            reverse(s.begin() + i, s.end());
        }
    }
    return s;
}
int main(){}