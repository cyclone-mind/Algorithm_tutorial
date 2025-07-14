/*
题目描述
在世界的某个区域，有一些分散的神秘岛屿，每个岛屿上都有一种珍稀的资源或者宝藏。国王打算在这些岛屿上建公路，方便运输。
不同岛屿之间，路途距离不同，国王希望你可以规划建公路的方案，如何可以以最短的总公路距离将 所有岛屿联通起来（注意：这是一个无向图）。 
给定一张地图，其中包括了所有的岛屿，以及它们之间的距离。以最小化公路建设长度，确保可以链接到所有岛屿。
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int v, e, v1, v2, val;
    cin >> v >> e;
    vector<vector<int>> gird(v + 1, vector<int>(v + 1, 10001));
    while (e--) {
        cin >> v1 >> v2 >> val;
        gird[v1][v2] = val;
        gird[v2][v1] = val;
    }
    vector<bool> isTree(v + 1, false);
    vector<int> minDist(v + 1, 10001);

    // 初始化：选择节点1作为起始节点
    isTree[1] = true;
    for (int i = 1; i <= v; i++) {
        minDist[i] = gird[1][i];
    }

    // Prim算法主循环：需要添加v-1个节点
    for (int k = 1; k < v; k++) {
        int cur = -1; // 初始化为无效值
        int minDistance = 10001;

        // 找到未加入MST且距离最小的节点
        for (int i = 1; i <= v; i++) { 
            if (isTree[i] == false && minDist[i] < minDistance) {
                minDistance = minDist[i];
                cur = i;
            }
        }

        // 将选中的节点加入MST
        isTree[cur] = true;

        // 更新剩余节点到MST的最短距离
        for (int i = 1; i <= v; i++) { 
            if (isTree[i] == false && gird[cur][i] < minDist[i]) {
                minDist[i] = gird[cur][i];
            }
        }
    }

    // 计算MST的总权重
    int result = 0;
    for (int i = 2; i <= v; i++) { 
        result += minDist[i];
    }
    cout << result << endl;
    return 0;
}