/*
738. 单调递增的数字
中等
相关标签
premium lock icon
相关企业
提示
当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。

给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。

示例 1:

输入: n = 10
输出: 9
示例 2:

输入: n = 1234
输出: 1234
示例 3:

输入: n = 332
输出: 299

提示:

0 <= n <= 10^9
*/

#include <iostream>
#include <string>

int monotoneIncreasingDigits(int n) {
    std::string str = std::to_string(n);
    int flag = str.size();
    for(int i = str.size() - 1;i > 0;i--){
        if(str[i - 1] > str[i]){
            str[i - 1]--;
            flag = i;
        }
    }
    for(int i = flag;i < str.size();i++){
        str[i] = '9';
    }
    return std::stoi(str);
}

int main(){
    int xx = monotoneIncreasingDigits(1234);
    std::cout << xx << std::endl;
}