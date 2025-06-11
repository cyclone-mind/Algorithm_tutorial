/*
332. 重新安排行程
困难
相关标签
premium lock icon
相关企业
给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi] 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。

所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。

例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前。
假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次。

1 <= tickets.length <= 300
tickets[i].length == 2
fromi.length == 3
toi.length == 3
fromi 和 toi 由大写英文字母组成
fromi != toi

算法图解：https://g.co/gemini/share/af2a42ac005c
*/

#include <vector>
using namespace std;
#include <string>
#include <unordered_map>
#include <map>

unordered_map<string, map<string, int>> targets;

bool backtracking(int ticketsNum, vector<string>& result){
    if(result.size() == ticketsNum +1){
        return true;
    }
    string from = result.back(); // 取出来当前出发地 

    for(auto& target:targets[from]){ // 当前出发地所有的目的地
        if(target.second > 0){ // 如果目的地还有票 则飞过去,往下遍历
            result.push_back(target.first); // 飞过去
            target.second--; // 票被消耗
            if(backtracking(ticketsNum, result)) return true; // 目的地还有去往其他地方的机票，结束循环 
            target.second++; 
            result.pop_back(); // 目的地没有去往其它地方的机票,则向上回溯 
        }
    }
    return false;
}

vector<string> findItinerary(vector<vector<string>>& tickets) {
    targets.clear();
    vector<string> result;
    for(const vector<string>& vec:tickets){
        targets[vec[0]][vec[1]]++;
    }
    result.push_back("JFK");
    backtracking(tickets.size(), result);
    return result;
}

// 声明后在main函数中初始化
int main() {

}