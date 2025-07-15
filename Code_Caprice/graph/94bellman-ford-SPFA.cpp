/*
Bellman_ford 队列优化算法 ，也叫SPFA算法（Shortest Path Faster Algorithm）
*/

#include <cstdint>
#include <iostream>
#include <list>
#include <queue>
#include <stdint.h>
#include <vector>

using namespace std;

struct Edge {
    int p2;
    int val;
};

int main() {
    int n, m, s, t, v;
    cin >> n >> m;

    vector<list<Edge>> grah(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> s >> t >> v;
        grah[s].push_back({t, v});
    }

    queue<int> que;
    int start = 1;
    int end = n;
    que.push(start);
    vector<int> minDist(n + 1, INT32_MAX);
    vector<bool> inQue(n + 1, false);
    minDist[start] = 0;
    inQue[start] = true;

    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        inQue[cur] = false;
        for (auto edge : grah[cur]) {
            int to = edge.p2;
            int price = edge.val;
            if (minDist[to] > minDist[cur] + price) {
                minDist[to] = minDist[cur] + price;
                if(inQue[to] == false){
                    que.push(to);
                    inQue[to] = true;
                }
            }
        }
    }

    if (minDist[end] == INT32_MAX)
        cout << "unconnected" << endl;
    else
        cout << minDist[end] << endl;
}