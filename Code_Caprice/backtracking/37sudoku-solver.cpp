/*
37. 解数独
困难
相关标签
premium lock icon
相关企业
编写一个程序，通过填充空格来解决数独问题。

数独的解法需 遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。

示例 1：

输入：board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
输出：[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
解释：输入的数独如上图所示，唯一有效的解决方案如下所示：

提示：

board.length == 9
board[i].length == 9
board[i][j] 是一位数字或者 '.'
题目数据 保证 输入数独仅有一个解
*/



#include <vector>
bool isValid(std::vector<std::vector<char>>& board, int row, int col, char num){
    // 是否行重复
    for(int i = 0;i < 9; i++){
        if(board[row][i] == num) return false;
    }
    // 是否列重复
    for(int i = 0;i < 9;i++){
        if(board[i][col] == num) return false;
    }
    // 检查当前3x3宫格是否重复
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j<3;j++){
            if(board[startRow + i][startCol + j] == num) return false;
        }
    }
    return true;
}

bool backtrack(std::vector<std::vector<char>>& board){
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') { // 找到空格
                for(char num = '1';num <= '9';num++){
                    if(isValid(board, row, col, num)){
                        board[row][col] = num;
                        if (backtrack(board)) return true;
                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}


void solveSudoku(std::vector<std::vector<char>>& board) {
    backtrack(board);
}
int  main(){}