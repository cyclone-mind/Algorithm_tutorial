#include <climits>
#include <iostream>
#include <list>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class mycompare {
  public:
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
        return lhs.second > rhs.second;
    }
};

struct Edge {
    int to;
    int val;
    Edge(int to, int val) : to(to), val(val) {}
};

int main() {
    int n, m, p1, p2, val;
    cin >> n >> m;
    vector<list<Edge>> grah(n + 1); // 初始化大小为 n+1
    while (m--) {
        cin >> p1 >> p2 >> val;
        grah[p1].push_back(Edge(p2, val));
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycompare> pq;
    int start = 1;
    int end = n;
    pq.push({start, 0});
    vector<int> minDist(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);
    minDist[start] = 0;
    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        if (visited[cur.first] == true)
            continue;
        visited[cur.first] = true;
        for (auto edge : grah[cur.first]) {
            if (visited[edge.to] == false &&
                edge.val + minDist[cur.first] < minDist[edge.to]) {
                minDist[edge.to] = edge.val + minDist[cur.first];
                pq.push({edge.to, minDist[edge.to]});
            }
        }
    }
    if (minDist[end] == INT_MAX)
        cout << -1 << endl;
    else
        cout << minDist[end] << endl;
}