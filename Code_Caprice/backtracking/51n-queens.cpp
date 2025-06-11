/*
51. N皇后
困难
相关标签
premium lock icon
相关企业
按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。

n 皇后问题 研究的是如何将 n 个皇后放置在 n×n
的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.'
分别代表了皇后和空位。

示例 1：

输入：n = 4
输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
解释：如上图所示，4 皇后问题存在两个不同的解法。
示例 2：

输入：n = 1
输出：[["Q"]]

提示：

1 <= n <= 9
*/

#include <vector>
using namespace std;
#include <string>

// 全局变量：存储所有合法的棋盘布局
vector<vector<string>> result;

// 检查当前位置 (row, col) 是否可以放置皇后
bool isValid(int row, int col, vector<string> chessboard, int n) {
    // 检查列：从第 0 行到当前行，是否有其他皇后在同一列
    for (int i = 0; i < row; i++) {
        if (chessboard[i][col] == 'Q') {
            return false;
        }
    }
    // 检查 45 度对角线（左上到右下）：从当前位置向左上方遍历
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (chessboard[i][j] == 'Q') {
            return false;
        }
    }
    // 检查 135 度对角线（右上到左下）：从当前位置向右上方遍历
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (chessboard[i][j] == 'Q') {
            return false;
        }
    }
    // 如果以上检查都通过，说明当前位置可以放置皇后
    return true;
}

// 回溯函数：尝试在棋盘的每一行放置皇后
void backtracking(int n, int row, vector<string> &chessboard) {
    // 如果当前行等于棋盘大小 n，说明已经找到一种合法布局
    if (row == n) {
        result.push_back(chessboard); // 将当前棋盘布局加入结果
        return;
    }
    // 在当前行的每一列尝试放置皇后
    for (int col = 0; col < n; col++) {
        // 检查当前位置是否可以放置皇后
        if (isValid(row, col, chessboard, n)) {
            chessboard[row][col] = 'Q';           // 放置皇后
            backtracking(n, row + 1, chessboard); // 递归处理下一行
            chessboard[row][col] = '.'; // 回溯：移除皇后，尝试其他位置
        }
    }
}

// 主函数：初始化棋盘并调用回溯函数
vector<vector<string>> solveNQueens(int n) {
    result.clear();                               // 清空全局结果
    vector<string> chessboard(n, string(n, '.')); // 初始化棋盘，全部填充为 '.'
    backtracking(n, 0, chessboard);               // 从第 0 行开始回溯
    return result;                                // 返回所有合法布局
}

// 主函数（未实现）
int main() {}