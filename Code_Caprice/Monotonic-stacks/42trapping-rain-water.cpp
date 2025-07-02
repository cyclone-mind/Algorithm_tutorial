/*
42. 接雨水
困难
相关标签
premium lock icon
相关企业
给定 n 个非负整数表示每个宽度为 1
的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

示例 1：

输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接
6 个单位的雨水（蓝色部分表示雨水）。 示例 2：

输入：height = [4,2,0,3,2,5]
输出：9


提示：

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

#include <stack>
#include <vector>

using namespace std;

int trap(vector<int>& height) {
    stack<int> st;
    int sum = 0;
    st.push(0);
    for (int i = 1; i < height.size(); i++) {
        while (!st.empty() && height[i] > height[st.top()]) {
            int mid = st.top();
            st.pop();
            if (!st.empty()) {
                int h = min(height[st.top()], height[i]) - height[mid];
                int w = i - st.top() - 1;
                sum += h * w;
            }
        }
        st.push(i);
    }
    return sum;
}
int main(){}