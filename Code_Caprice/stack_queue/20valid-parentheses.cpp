#include <string>
using namespace std;
#include <stack>
bool isValid(string s) {
    stack<int> st;
    if(s.size() %2 != 0 ) return false;
    for(int i = 0; i<s.size();i++){
        if (s[i] == '('){
            st.push(')');
        } else if(s[i] == '['){
            st.push(']');
        } else if (s[i] == '{'){
            st.push('}');
        } else if (st.empty() || s[i] != st.top()){
            return false;
        } else {
            st.pop();
        }
    }
    return st.empty();
}

// 函数：isValid_positive_consideration
// 功能：判断给定的括号字符串是否有效（另一种解法，强调正向匹配逻辑）。
// 描述：
//   此方法遍历字符串中的每个字符：
//   - 如果遇到开括号（'(', '[', '{')，则将其压入栈中。
//   - 如果遇到闭括号（')', ']', '}')：
//     - 首先检查栈是否为空。如果为空，说明没有对应的开括号，字符串无效。
//     - 然后，获取栈顶的开括号，并与当前闭括号进行匹配：
//       - 如果它们是对应的配对（例如, ')' 和 '('），则从栈中弹出开括号。
//       - 如果不匹配，则字符串无效。
//   遍历字符串结束后，如果栈为空，表示所有括号都已正确匹配，字符串有效。
//   否则，栈中剩余的开括号未得到匹配，字符串无效。
// 参数：
//   s: string - 包含括号的输入字符串。
// 返回值：
//   bool - 如果字符串中的括号有效则返回 true，否则返回 false。
// 时间复杂度：O(n)，其中 n 是字符串 s 的长度。每个字符最多被压入和弹出栈一次。
// 空间复杂度：O(n)，在最坏的情况下（例如，字符串 "((((("），栈的大小可以达到 n。
bool isValid_positive_consideration(string s) {
    stack<char> st; // 使用 char 类型的栈来存储开括号

    // 优化：奇数长度的字符串必然无效
    if (s.length() % 2 != 0) {
        return false;
    }

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            // 如果是开括号，直接压入栈中
            st.push(c);
        } else {
            // 如果是闭括号
            // 1. 检查栈是否为空，如果为空，则没有开括号与之匹配，无效
            if (st.empty()) {
                return false;
            }

            // 2. 获取栈顶的开括号
            char top_char = st.top();

            // 3. 判断当前闭括号是否与栈顶的开括号匹配
            if ((c == ')' && top_char == '(') ||
                (c == ']' && top_char == '[') ||
                (c == '}' && top_char == '{')) {
                // 匹配成功，将栈顶的开括号弹出
                st.pop();
            } else {
                // 不匹配，无效
                return false;
            }
        }
    }

    // 遍历完所有字符后，如果栈为空，则表示所有括号都正确匹配
    return st.empty();
}

int main(){}