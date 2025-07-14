// 给定一个包含 n 个节点的无向图中，节点编号从 1 到 n （含 1 和 n ）。
// 你的任务是判断是否有一条从节点 source 出发到节点 destination 的路径存在。
#include <vector>
#include <iostream>
using namespace std;

vector<int> father(101,0);

void init(){
    for(int i = 0;i < father.size();i++){
        father[i] = i;
    }
}

int find(int u){
    return u == father[u] ? u : father[u] = find(father[u]);
}

bool isSame(int u,int v){
    u  = find(u);
    v = find(v);
    return u == v;
}

void join(int u,int v){
    u  = find(u);
    v = find(v);
    if(u == v) return;
    father[v] = u;
}

int main(){
    int n,m,s,t,source,destination;
    cin >> n >> m;
    init();
    while(m--){
        cin >> s >> t;
        join(s,t);
    }
    cin >> source >> destination;
    if (isSame(source, destination)) cout << 1 << endl;
    else cout << 0 << endl;

}