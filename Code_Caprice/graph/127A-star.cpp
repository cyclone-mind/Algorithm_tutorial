#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

// A*算法中的节点结构
struct Node {
    int x, y; // 当前位置
    int g;    // 从起点到当前点的实际距离
    int h;    // 启发式函数值（到终点的估计距离）
    int f;    // f = g + h，总评估值

    Node(int x, int y, int g, int h) : x(x), y(y), g(g), h(h), f(g + h) {}
};

// 自定义比较器：f值小的优先级高（小顶堆）
class NodeCompare {
  public:
    bool operator()(const Node &lhs, const Node &rhs) {
        if (lhs.f != rhs.f) {
            return lhs.f > rhs.f; // f值小的优先级高
        }
        return lhs.h > rhs.h; // f值相同时，h值小的优先级高
    }
};

// 启发式函数：计算从当前位置到目标位置的估计距离
int heuristic(int x1, int y1, int x2, int y2) {
    // 使用距离平方，避免开根号运算，提高性能
    double dx = abs(x1 - x2);
    double dy = abs(y1 - y2);
    // 直接返回距离平方除以5（因为马最大移动距离平方是5）
    return (dx * dx + dy * dy) / 5;
}

// 马的8个可能移动方向
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

// 检查坐标是否在棋盘范围内
bool isValid(int x, int y) {
    return x >= 1 && x <= 1000 && y >= 1 && y <= 1000;
}

// 将坐标转换为唯一的哈希值，用于visited集合
long long getHash(int x, int y) { return (long long)x * 1001 + y; }

int astar(int startX, int startY, int endX, int endY) {
    // 如果起点和终点相同，直接返回0
    if (startX == endX && startY == endY) {
        return 0;
    }

    // 优先队列，存储待探索的节点
    priority_queue<Node, vector<Node>, NodeCompare> pq;
    // 已访问的节点集合
    unordered_set<long long> visited;

    // 将起点加入队列
    int h = heuristic(startX, startY, endX, endY);
    pq.push(Node(startX, startY, 0, h));

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        // 生成当前节点的哈希值
        long long currentHash = getHash(current.x, current.y);

        // 如果已经访问过，跳过
        if (visited.find(currentHash) != visited.end()) {
            continue;
        }

        // 标记为已访问
        visited.insert(currentHash);

        // 如果到达目标，返回步数
        if (current.x == endX && current.y == endY) {
            return current.g;
        }

        // 尝试马的8个可能移动
        for (int i = 0; i < 8; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            // 检查新位置是否有效
            if (!isValid(newX, newY)) {
                continue;
            }

            long long newHash = getHash(newX, newY);

            // 如果已经访问过，跳过
            if (visited.find(newHash) != visited.end()) {
                continue;
            }

            // 计算新节点的g值和h值
            int newG = current.g + 1;
            int newH = heuristic(newX, newY, endX, endY);

            // 将新节点加入队列
            pq.push(Node(newX, newY, newG, newH));
        }
    }

    return -1; // 理论上不会到达这里
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        int result = astar(a1, a2, b1, b2);
        cout << result << endl;
    }

    return 0;
}

/*
算法复杂度分析：
时间复杂度：O(V log V)，其中V是搜索到的节点数量
空间复杂度：O(V)，用于存储优先队列和访问集合

A*算法的优势：
1. 启发式函数指导搜索方向，比普通BFS更高效
2. 保证找到最优解（如果启发式函数是可接受的）
3. 对于大规模问题，性能优于传统BFS
*/