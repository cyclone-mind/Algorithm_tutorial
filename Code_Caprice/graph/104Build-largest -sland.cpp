#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void dfs(vector<vector<int>> &gird, vector<vector<bool>> &visited, int x, int y,
         int mark, int &count) {
    if (visited[x][y] == true)
        return;
    visited[x][y] = true;
    gird[x][y] = mark;
    count++;
    for (int i = 0; i < 4; i++) {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if (nextx < 0 || nexty < 0 || nextx >= gird.size() ||
            nexty >= gird[0].size())
            continue;
        if (gird[nextx][nexty] == 0)
            continue;
        dfs(gird, visited, nextx, nexty, mark, count);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> gird(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> gird[i][j];
        }
    }
    unordered_map<int, int> girdNum;
    int mark = 2;
    bool hasWater = false; // 标记是否有海水

    // 第一步：给每个岛屿编号并记录面积
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (gird[i][j] == 0) {
                hasWater = true; // 发现海水
            } else if (gird[i][j] == 1 && visited[i][j] == false) {
                int count = 0;
                dfs(gird, visited, i, j, mark, count);
                girdNum[mark] = count;
                mark++;
            }
        }
    }

    // 边界情况：如果没有海水，整个网格都是陆地
    if (!hasWater) {
        cout << N * M << endl;
        return 0;
    }

    int maxArea = 0;
    // 第二步：尝试填海造陆
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (gird[i][j] == 0) {
                unordered_set<int> islandNum;
                int icount = 1; // 当前位置变为陆地，面积+1
                for (int k = 0; k < 4; k++) {
                    int nextx = i + dir[k][0];
                    int nexty = j + dir[k][1];
                    if (nextx < 0 || nexty < 0 || nextx >= gird.size() ||
                        nexty >= gird[0].size())
                        continue;
                    if (islandNum.count(gird[nextx][nexty]))
                        continue;
                    islandNum.insert(gird[nextx][nexty]);
                    icount += girdNum[gird[nextx][nexty]];
                }
                maxArea = maxArea > icount ? maxArea : icount;
            }
        }
    }
    cout << maxArea << endl;
}