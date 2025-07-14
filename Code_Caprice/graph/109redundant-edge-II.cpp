/*
有一种有向树,该树只有一个根节点，所有其他节点都是该根节点的后继。该树除了根节点之外的每一个节点都有且只有一个父节点，而根节点没有父节点。有向树拥有
n 个节点和 n - 1 条边。如图：
现在有一个有向图，有向图是在有向树中的两个没有直接链接的节点中间添加一条有向边。如图：
输入一个有向图，该图由一个有着 n 个节点(节点编号 从 1 到 n)，n
条边，请返回一条可以删除的边，使得删除该条边之后该有向图可以被当作一颗有向树。
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> father(1001, 0);

// 初始化并查集
void init(int n) {
    for (int i = 1; i <= n; i++) {
        father[i] = i;
    }
}

// 查找根节点（路径压缩）
int find(int u) { return father[u] == u ? u : father[u] = find(father[u]); }

// 判断两个节点是否在同一连通分量
bool isSame(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}

// 合并两个连通分量
void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    father[v] = u;
}

// 检查删除指定边后是否能形成有向树
bool isRedundant(vector<pair<int, int>> &edges, int skipIndex, int n) {
    init(n); // 重新初始化并查集
    for (int i = 0; i < edges.size(); i++) {
        if (i == skipIndex)
            continue; // 跳过指定边
        if (isSame(edges[i].first, edges[i].second)) {
            return false; // 发现环，不能形成树
        } else {
            join(edges[i].first, edges[i].second);
        }
    }
    return true; // 能形成树
}

int main() {
    int n, s, t;
    cin >> n;
    vector<pair<int, int>> edges;   // 不预分配大小
    vector<int> indegree(n + 1, 0); // 入度数组

    // 读取边并计算入度
    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        edges.push_back({s, t});
        indegree[t]++;
    }

    // 查找入度为2的节点对应的边
    vector<int> redundant_edges;
    for (int i = 0; i < n; i++) {
        if (indegree[edges[i].second] == 2) {
            redundant_edges.push_back(i);
        }
    }

    // 情况1：存在入度为2的节点
    if (redundant_edges.size() > 0) {
        // 优先删除后出现的边
        if (redundant_edges.size() >= 2) {
            if (isRedundant(edges, redundant_edges[1], n)) {
                cout << edges[redundant_edges[1]].first << " "
                     << edges[redundant_edges[1]].second << endl;
                return 0;
            } else {
                cout << edges[redundant_edges[0]].first << " "
                     << edges[redundant_edges[0]].second << endl;
                return 0;
            }
        } else {
            // 只有一条边指向入度为2的节点
            cout << edges[redundant_edges[0]].first << " "
                 << edges[redundant_edges[0]].second << endl;
            return 0;
        }
    }

    // 情况2：没有入度为2的节点，直接查找形成环的边
    init(n);
    for (int i = 0; i < edges.size(); i++) {
        if (isSame(edges[i].first, edges[i].second)) {
            cout << edges[i].first << " " << edges[i].second << endl;
            return 0;
        } else {
            join(edges[i].first, edges[i].second);
        }
    }

    return 0;
}