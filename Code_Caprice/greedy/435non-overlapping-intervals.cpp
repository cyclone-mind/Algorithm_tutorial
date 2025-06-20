/*
435. 无重叠区间
中等
相关标签
premium lock icon
相关企业
给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回
需要移除区间的最小数量，使剩余区间互不重叠 。

注意 只在一点上接触的区间是 不重叠的。例如 [1, 2] 和 [2, 3] 是不重叠的。

示例 1:

输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。
示例 2:

输入: intervals = [ [1,2], [1,2], [1,2] ]
输出: 2
解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
示例 3:

输入: intervals = [ [1,2], [2,3] ]
输出: 0
解释: 你不需要移除任何区间，因为它们已经是无重叠的了。

提示:
1 <= intervals.length <= 105
intervals[i].length == 2
-5 * 104 <= starti < endi <= 5 * 104
*/

#include <algorithm>
#include <vector>
using namespace std;

static bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0];
}
int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    // 首先按照区间的起始位置进行排序，方便后续处理相邻区间
    sort(intervals.begin(), intervals.end(), cmp);
    int result = 0;
    for (int i = 1; i < intervals.size(); i++) {
        // 如果当前区间与前一个区间重叠
        if (intervals[i][0] < intervals[i - 1][1]) {
            result++;
            // 贪心策略：每次遇到重叠时，优先保留右端点更小的区间（这样更容易与后面的区间不重叠）
            // 通过更新当前区间的右端点为两个区间右端点的较小值，等价于移除右端点更大的那个区间
            intervals[i][1] = min(
                intervals[i - 1][1],
                intervals
                    [i]
                    [1]); // 这里的逻辑是更新为两者之间的靠左的右边界，相当于删除了那个靠右的右边界的区间。
        }
        // 如果不重叠，则什么都不做，继续遍历
    }
    return result;
}

int main() {}