#include <string>
#include <iostream>
using namespace std;

void removeExtraSpaces(string& s) {
    int slow = 0; // 慢指针，用于构建新字符串
    for (int fast = 0; fast < s.size(); fast++) {
        // 如果当前字符不是空格，或者当前是空格但前一个字符不是空格（避免连续空格）
        if (s[fast] != ' ') {
            // 处理非空格字符
            s[slow++] = s[fast];
        } else if (slow > 0 && s[slow - 1] != ' ') {
            // 处理第一个空格（避免连续空格）
            s[slow++] = s[fast];
        }
    }
    // 移除末尾可能的多余空格
    if (slow > 0 && s[slow - 1] == ' ') {
        slow--;
    }
    s.resize(slow);
}


void reverse(string& s,int strat,int end){
    for(int i = strat,j = end;i < j;i++,j--){
        swap(s[i],s[j]);
    }
}
string reverseWords(string s) {
    removeExtraSpaces(s);
    reverse(s,0,s.size() - 1);
    int left = 0;
    for(int right = 0;right <= s.size();right++){
        if(s[right] == ' ' || right == s.size()){
            reverse(s,left,right - 1);
            left = right + 1;
        }
    }
    return s;
}

int main()
{
    string s = "  hello world  ";
    string news = reverseWords(s);
    std::cout << news << std::endl;
}