// 版本二
#include <iostream>
#include <vector>
#include <list>
#include <climits>
using namespace std;

int main() {
    int src, dst,k ,p1, p2, val ,m , n;
    
    cin >> n >> m;

    vector<vector<int>> grid;

    for(int i = 0; i < m; i++){
        cin >> p1 >> p2 >> val;
        grid.push_back({p1, p2, val});
    }

    cin >> src >> dst >> k;

    vector<int> minDist(n + 1 , INT_MAX);
    minDist[src] = 0;
    vector<int> minDist_copy(n + 1); // 用来记录上一次遍历的结果
    for (int i = 1; i <= k + 1; i++) {
        minDist_copy = minDist; // 获取上一次计算的结果
        for (vector<int> &side : grid) {
            int from = side[0];
            int to = side[1];
            int price = side[2];
            // 注意使用 minDist_copy 来计算 minDist 
            if (minDist_copy[from] != INT_MAX && minDist[to] > minDist_copy[from] + price) {  
                minDist[to] = minDist_copy[from] + price;
            }
        }
    }
    if (minDist[dst] == INT_MAX) cout << "unreachable" << endl; // 不能到达终点
    else cout << minDist[dst] << endl; // 到达终点最短路径

}
