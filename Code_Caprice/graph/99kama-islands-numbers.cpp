#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
/*
深搜
void dfs(const vector<vector<int>> &gird, vector<vector<bool>> &visited,
         int x, int y) {
            //
以这个x，y这个陆地为起点进行搜索，做什么？将相连的并且是陆地的并且没有访问过的陆地标记为已访问
    for (int current = 0; current < 4; current++) {
        int next_x = x + dir[current][0];
        int next_y = y + dir[current][1];
        if (next_x < 0 || next_y < 0 || next_x == gird.size() ||
            next_y == gird[0].size()) {
            continue;
        }
        if (visited[next_x][next_y] == false && gird[next_x][next_y] == 1) { 
        //相连的并且是陆地的并且没有访问过的陆地才进入下一步搜索 
        visited[next_x][next_y] = true; 
        // 搜索之前先把陆地标记了 
        dfs(gird, visited, next_x, next_y);
        }
    }
}
*/

// 广搜
void bfs(const vector<vector<int>> &gird, vector<vector<bool>> &visited, int x,
         int y) {
    queue<pair<int, int>> que;
    que.push({x, y});
    while (!que.empty()) {
        pair<int, int> cur = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int next_x = cur.first + dir[i][0];
            int next_y = cur.second + dir[i][1];
            if (next_x < 0 || next_y < 0 || next_x == gird.size() ||
                next_y == gird[0].size()) {
                continue;
            }
            if (visited[next_x][next_y] == false && gird[next_x][next_y] == 1) {
                que.push({next_x,next_y});
                visited[next_x][next_y] = true;
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> gird(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> gird[i][j];
        }
    }
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (gird[i][j] == 1 &&
                visited[i][j] == false) { // 是陆地，且没有访问过
                result++;
                visited[i][j] = true;
                bfs(gird, visited, i, j); // 以这个陆地为起点进行搜索，做什么？
            }
        }
    }
    cout << result << endl;
    return 0;
}