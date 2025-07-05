
#include <iostream>
#include <vector>
using namespace std;
int island_count;

vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
void dfs(vector<vector<int>> &gird, int x,
         int y) {
            gird[x][y] = 0;
    for (int current = 0; current < 4; current++) {
        int next_x = x + dir[current][0];
        int next_y = y + dir[current][1];
        if (next_x < 0 || next_y < 0 || next_x == gird.size() ||
            next_y == gird[0].size()) {
            continue;
        }
        if (gird[next_x][next_y] == 0) {
            continue;
        }
        dfs(gird, next_x, next_y);
    }
    return;
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
    for(int i = 0;i < N;i++){
        if(gird[i][0] == 1) dfs(gird,i,0);
        if(gird[i][M-1] == 1) dfs(gird,j,M-1);
    }
    for(int j = 0;j < M;j++){
        if(gird[0][j] == 1) dfs(gird,0,j);
        if(gird[N-1][j] == 1) dfs(gird,N-1,j);
    }
    int S = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (gird[i][j] == 1) {
                S++;
            }
        }
    }
    cout << S << endl;
}