/*
406. 根据身高重建队列
中等
相关标签
premium lock icon
相关企业
提示
假设有打乱顺序的一群人站成一个队列，数组 people
表示队列中一些人的属性（不一定按顺序）。每个 people[i] = [hi, ki] 表示第 i
个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。

请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue
，其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0]
是排在队列前面的人）。



示例 1：

输入：people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
输出：[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
解释：
编号为 0 的人身高为 5 ，没有身高更高或者相同的人排在他前面。
编号为 1 的人身高为 7 ，没有身高更高或者相同的人排在他前面。
编号为 2 的人身高为 5 ，有 2 个身高更高或者相同的人排在他前面，即编号为 0 和 1
的人。 编号为 3 的人身高为 6 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1
的人。 编号为 4 的人身高为 4 ，有 4 个身高更高或者相同的人排在他前面，即编号为
0、1、2、3 的人。 编号为 5 的人身高为 7 ，有 1
个身高更高或者相同的人排在他前面，即编号为 1 的人。 因此
[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] 是重新构造后的队列。 示例 2：

输入：people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
输出：[[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]


提示：

1 <= people.length <= 2000
0 <= hi <= 106
0 <= ki < people.length
题目数据确保队列可以被重建
*/
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

// 比较函数：先按身高降序，如果身高相同则按ki升序
static bool cmp(const vector<int> &a, const vector<int> &b) {
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] > b[0];
}

// 主函数：重建队列
vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    // 1. 先排序
    sort(people.begin(), people.end(), cmp);

    // 2. 用list方便在任意位置插入
    list<vector<int>> queue;

    // 3. 遍历每个人，插入到对应的位置
    for (int i = 0; i < people.size(); i++) {
        int position = people[i][1]; // 该人在队列中的位置
        // 获取插入位置的迭代器
        auto it = queue.begin();
        // 前进position步
        advance(it, position);
        // 插入到指定位置
        queue.insert(it, people[i]);
    }

    // 4. 把list转成vector返回
    return vector<vector<int>>(queue.begin(), queue.end());
}

int main(){}