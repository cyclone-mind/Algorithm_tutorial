#include <iostream>
#include <vector>
#include <list>
using namespace std;

void dfs(vector<list<int>>& grah,vector<bool>& visit,int key){
    list<int> keys = grah[key];
    for(auto k:keys){
        if(visit[k] == true) continue;
        visit[k] = true;
        dfs(grah,visit,k);
    }
}

int main(){
    int N,K,s,t;
    cin >> N >> K;
    vector<list<int>> grah(N+1);
    for(int i = 0;i < K;i++){
        cin >> s >> t;
        grah[s].push_back(t);
    }

    vector<bool> visit(N + 1, false);

    visit[1] = true;
    dfs(grah,visit,1);
    for(int i = 1;i<visit.size();i++){
        if(visit[i] == false) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << 1 << endl;

}