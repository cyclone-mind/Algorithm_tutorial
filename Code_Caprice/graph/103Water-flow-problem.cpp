#include <iostream>
#include <vector>
using namespace std;

int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

void dfs(vector<vector<int>>& gird,vector<vector<bool>>& visited,int x,int y){
    if(visited[x][y] == true) return;
    visited[x][y] = true;
    for(int i = 0;i < 4;i++){
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if(nextx < 0 || nexty < 0 || nextx >= gird.size() || nexty >= gird[0].size()) continue;
        if(gird[nextx][nexty] < gird[x][y]) continue;
        dfs(gird,visited,nextx,nexty);
    }
    return;
}

int main(){
    int N,M;
    cin>>N>>M;
    vector<vector<int>> gird(N,vector<int>(M,0));
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            int num;
            cin >> num;
            gird[i][j] = num;
        }
    }
    vector<vector<bool>> firstborder(N,vector<bool>(M,false));
    vector<vector<bool>> secondborder(N,vector<bool>(M,false));
    for(int i = 0;i < N;i++){
        dfs(gird,firstborder,i,0);
        dfs(gird,secondborder,i,M-1);
    }
    for(int j = 0;j < M;j++){
        dfs(gird,firstborder,0,j);
        dfs(gird,secondborder,N-1,j);
    }
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            if(firstborder[i][j] && secondborder[i][j]){
                cout << i << " " << j << endl;
            }
        }
    }
}