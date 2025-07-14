#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u,v,val;
};

vector<int> father(1001,-1);

void init(){
    for(int i = 0;i < 1001;i++){
        father[i] = i;
    }
}

int find(int u){
    return u == father[u] ? u : father[u] = find(father[u]);
}

bool isSame(int u,int v){
    u = find(u);
    v = find(v);
    return u == v;
}

void join(int u,int v){
    u = find(u);
    v = find(v);
    if(u == v) return;
    father[v] = u;
}

int main() {
    int v, e, v1, v2, val;
    cin >> v >> e;
    vector<Edge> edges;
    while(e--){
        cin >> v1 >> v2 >> val;
        edges.push_back({v1,v2,val});
    }
    init();
    int result = 0;
    sort(edges.begin(), edges.end(),[](const Edge& a, const Edge& b){return a.val < b.val;});
    for(auto edge:edges){
        if(isSame(edge.u,edge.v) == false) {
            result += edge.val;
            join(edge.u,edge.v);
        }
    }
    cout << result << endl;
}