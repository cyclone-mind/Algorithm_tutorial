/*
84. 柱状图中最大的矩形
已解答
困难
相关标签
premium lock icon
相关企业
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1
。

求在该柱状图中，能够勾勒出来的矩形的最大面积。
*/
#include <stack>
#include <vector>

using namespace std;

int largestRectangleArea(vector<int> &heights) {
    stack<int> st;
    int res = 0;
    heights.push_back(0);
    st.push(0);
    for (int i = 1; i < heights.size(); i++) {
        // 如果当前柱子高度小于栈顶柱子的高度，说明栈顶柱子的右边界找到了
        while (!st.empty() && heights[i] < heights[st.top()]) {
            int mid = st.top();
            st.pop();
            // 如果栈为空，说明左边没有比 mid_height
            // 更矮的柱子，宽度可以延伸到开头
            // 否则，左边界就是新的栈顶元素所在的位置
            int left_idx = st.empty() ? -1 : st.top();
            int right = heights[i];
            // 宽度 = 右边界 - 左边界 - 1
            int w = i - left_idx - 1;
            res = max(w * heights[mid], res);
        }
        st.push(i);
    }
    return res;
}

int main() {}