#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> result;
vector<int> path;

void dfs(const vector<vector<int>> &graph, int x, int n) {
    if (x == n) {
        result.push_back(path);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (graph[x][i] == 1) {
            path.push_back(i);
            dfs(graph, i, n);
            path.pop_back();
        }
    }
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, 0));
    while (M--) {
        int s, t;
        cin >> s >> t;
        graph[s][t] = 1;
    }

    path.push_back(1);

    dfs(graph, 1, N);
    if (result.size() == 0)
        cout << -1 << endl;
    for (auto pa : result) {
        for (int i = 0; i < pa.size() - 1; i++) {
            cout << pa[i] << " ";
        }
        cout << pa[pa.size() - 1] << endl;
    }
}

/*
leetcode797 核心代码模式，邻接表形式
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void dfs(const vector<vector<int>>& graph, int x, int n) {
        if (x == n-1) { // 找到符合条件的一条路径
            result.push_back(path);
            return;
        }
        for (int i : graph[x]) { // 找到 x指向的节点
            path.push_back(i);   // 遍历到的节点加入到路径中来
            dfs(graph, i, n);    // 进入下一层递归
            path.pop_back();     // 回溯，撤销本节点
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(graph, 0, graph.size());
        return result;
    }
};
*/
