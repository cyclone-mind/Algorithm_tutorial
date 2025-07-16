#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int p1;
    int p2;
    int val;

    Edge(int p1, int p2, int val) : p1(p1), p2(p2), val(val) {}
};

int main() {
    int n, m, s, t, v;
    cin >> n >> m;

    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        cin >> s >> t >> v;
        edges.push_back(Edge(s, t, v));
    }

    vector<int> minDist(n + 1, INT32_MAX);
    minDist[1] = 0;
    bool flag = false;
    // Bellman-Ford算法：进行n-1轮松弛，添加提前终止条件
    for (int i = 1; i <= n; i++) {
        bool updated = false; // 标记本轮是否有更新

        for (auto edge : edges) {
            int start = edge.p1;
            int end = edge.p2;
            int val = edge.val;
            if (i < n) {
                // 松弛操作
                if (minDist[start] != INT32_MAX &&
                    minDist[end] > minDist[start] + val) {
                    minDist[end] = minDist[start] + val;
                    updated = true; // 标记发生了更新
                }
            } else {
                if (minDist[start] != INT32_MAX &&
                    minDist[end] > minDist[start] + val) {
                    flag = true;
                }
            }
        }
        for(int j = 0;j < minDist.size();j++){
            cout << "minDist:" << minDist[j] << " ";
        }
        cout << endl;
        // 提前终止条件：如果本轮没有任何更新，说明已经收敛
        if (!updated) {
            cout << "算法在第 " << i << " 轮提前收敛" << endl;
            break;
        }
    }
    if (flag) {
        cout << "circle" << endl;
        return 0;
    }
    if (minDist[n] == INT32_MAX)
        cout << "unconnected" << endl;
    else
        cout << minDist[n] << endl;
}