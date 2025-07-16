#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, u, v, w, q, start, end;
    cin >> n >> m;
    vector<vector<vector<int>>> grid(
        n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 10006)));
    for (int i = 1; i <= n; i++) {
        grid[i][i][0] = 0;
    }
    while (m--) {
        cin >> u >> v >> w;
        grid[u][v][0] = w;
        grid[v][u][0] = w;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                grid[i][j][k] = min(grid[i][k][k - 1] + grid[k][j][k - 1],
                                    grid[i][j][k - 1]);
            }
        }
    }
    cin >> q;
    while (q--) {
        cin >> start >> end;
        if (grid[start][end][n] == 10006)
            cout << -1 << endl;
        else
            cout << grid[start][end][n] << endl;
    }
}