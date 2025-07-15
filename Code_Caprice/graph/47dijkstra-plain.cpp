#include <vector>
#include <climits>
#include <iostream>

using namespace std;

int main(){
    int n,m,p1,p2,val;
    cin >> n >> m;
    vector<vector<int>> gird(n+1,vector<int>(n+1,INT_MAX));
    while(m--){
        cin >> p1 >> p2 >> val;
        gird[p1][p2] = val;
    }
    int stat = 1,end = n;
    vector<int> minDist(n + 1,INT_MAX);
    vector<bool> visited(n + 1,false);
    minDist[stat] = 0;
    vector<int> parent(n + 1,-1);
    for(int i = 1;i <= n;i++){
        int cur = 1;
        int minVal = INT_MAX;
        for(int v = 1;v <= n;v++){
            if(visited[v] == false && minDist[v] < minVal){
                minVal = minDist[v];
                cur = v;
            }
        }
        visited[cur] = true;
        for(int v = 1;v <= n;v++){
            if(visited[v] == false && gird[cur][v] != INT_MAX && gird[cur][v] + minDist[cur] < minDist[v]){
                minDist[v] = gird[cur][v] + minDist[cur];
                parent[v] = cur;
            }
        }
    }
    for(int i = 1;i <= n;i++){
        cout << parent[i] << "->" << i << endl;
    }
    if(minDist[end] == INT_MAX) cout << -1 << endl; 
    else cout << minDist[end] << endl;
}