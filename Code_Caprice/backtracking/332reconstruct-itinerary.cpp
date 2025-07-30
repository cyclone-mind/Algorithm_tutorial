#include <unordered_map>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution  {
private:
    unordered_map<string, map<string, int>> graph;
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        graph.clear();
        
        // 构建图，map确保字典序
        for (const auto& ticket : tickets) {
            graph[ticket[0]][ticket[1]]++;
        }
        
        vector<string> result;
        dfs("JFK", result);
        
        // 由于是后序遍历，需要反转结果
        reverse(result.begin(), result.end());
        return result;
    }
    
private:
    // 使用DFS + 后序遍历的思想
    void dfs(const string& from, vector<string>& path) {
        while (!graph[from].empty()) {
            // 获取字典序最小的目的地
            auto it = graph[from].begin();
            string to = it->first;
            
            // 使用这张机票
            if (--it->second == 0) {
                graph[from].erase(it);
            }
            
            // 继续DFS
            dfs(to, path);
        }
        
        // 后序遍历：在回溯时添加到路径
        path.push_back(from);
    }
};