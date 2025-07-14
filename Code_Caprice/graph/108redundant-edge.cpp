/*
有一个图，它是一棵树，他是拥有 n 个节点（节点编号1到n）和 n - 1
条边的连通无环无向图，例如如图：
现在在这棵树上的基础上，添加一条边（依然是n个节点，但有n条边），使这个图变成了有环图，如图：
先请你找出冗余边，删除后，使该图可以重新变成一棵树。
输入描述
第一行包含一个整数 N，表示图的节点个数和边的个数。
后续 N 行，每行包含两个整数 s 和 t，表示图中 s 和 t 之间有一条边。
输出描述
输出一条可以删除的边。如果有多个答案，请删除标准输入中最后出现的那条边。
输入示例
3
1 2
2 3
1 3
输出示例
1 3
提示信息
图中的 1 2，2 3，1 3 等三条边在删除后都能使原图变为一棵合法的树。但是 1 3
由于是标准输出里最后出现的那条边，所以输出结果为 1 3 数据范围： 1 <= N <= 1000.
*/

#include <iostream>
#include <queue>

#include <vector>

using namespace std;

// ===================== 解法一：并查集（推荐） =====================
class UnionFind {
  private:
    vector<int> parent;
    vector<int> rank;

  public:
    // 初始化并查集
    UnionFind(int n) : parent(n + 1), rank(n + 1, 0) {
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    // 查找根节点（带路径压缩）
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // 合并两个集合（按秩合并）
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return false; // 已经在同一集合中，说明会形成环
        }

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

vector<int> findRedundantConnection_UnionFind(vector<vector<int>> &edges) {
    int n = edges.size();
    UnionFind uf(n);

    // 按顺序处理每条边
    for (auto &edge : edges) {
        int u = edge[0], v = edge[1];
        // 如果两个节点已经连通，说明这条边是冗余的
        if (!uf.unite(u, v)) {
            return edge;
        }
    }
    return {};
}

// ===================== 解法二：深度优先搜索 =====================
class DFSSolution {
  private:
    // DFS检查图的连通性
    void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited) {
        visited[node] = true;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited);
            }
        }
    }

    // 检查移除指定边后图是否连通
    bool isConnected(vector<vector<int>> &edges, int skipIndex, int n) {
        vector<vector<int>> graph(n + 1);

        // 构建邻接表（跳过指定边）
        for (int i = 0; i < edges.size(); i++) {
            if (i == skipIndex)
                continue;
            int u = edges[i][0], v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // 从节点1开始DFS
        vector<bool> visited(n + 1, false);
        dfs(1, graph, visited);

        // 检查是否所有节点都被访问
        for (int i = 1; i <= n; i++) {
            if (!visited[i])
                return false;
        }
        return true;
    }

  public:
    vector<int> findRedundantConnection_DFS(vector<vector<int>> &edges) {
        int n = edges.size();

        // 从后往前检查每条边
        for (int i = n - 1; i >= 0; i--) {
            // 尝试移除第i条边，检查图是否仍然连通
            if (isConnected(edges, i, n)) {
                return edges[i];
            }
        }
        return {};
    }
};

// ===================== 解法三：广度优先搜索 =====================
class BFSSolution {
  private:
    // BFS检查图的连通性
    bool isConnected(vector<vector<int>> &edges, int skipIndex, int n) {
        vector<vector<int>> graph(n + 1);

        // 构建邻接表（跳过指定边）
        for (int i = 0; i < edges.size(); i++) {
            if (i == skipIndex)
                continue;
            int u = edges[i][0], v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // BFS遍历
        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int visitedCount = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                    visitedCount++;
                }
            }
        }

        return visitedCount == n;
    }

  public:
    vector<int> findRedundantConnection_BFS(vector<vector<int>> &edges) {
        int n = edges.size();

        // 从后往前检查每条边
        for (int i = n - 1; i >= 0; i--) {
            // 尝试移除第i条边，检查图是否仍然连通
            if (isConnected(edges, i, n)) {
                return edges[i];
            }
        }
        return {};
    }
};

// ===================== 测试函数 =====================
void testSolutions() {
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {1, 3}};

    cout << "输入边集: ";
    for (auto &edge : edges) {
        cout << "[" << edge[0] << "," << edge[1] << "] ";
    }
    cout << endl;

    // 测试并查集解法
    auto result1 = findRedundantConnection_UnionFind(edges);
    cout << "并查集解法结果: [" << result1[0] << "," << result1[1] << "]"
         << endl;

    // 测试DFS解法
    DFSSolution dfsObj;
    auto result2 = dfsObj.findRedundantConnection_DFS(edges);
    cout << "DFS解法结果: [" << result2[0] << "," << result2[1] << "]" << endl;

    // 测试BFS解法
    BFSSolution bfsObj;
    auto result3 = bfsObj.findRedundantConnection_BFS(edges);
    cout << "BFS解法结果: [" << result3[0] << "," << result3[1] << "]" << endl;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> edges(n);
    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        edges[i] = {s, t};
    }

    // 使用并查集解法（推荐）
    auto result = findRedundantConnection_UnionFind(edges);
    cout << result[0] << " " << result[1] << endl;

    // 取消注释下面这行来测试所有解法
    // testSolutions();

    return 0;
}