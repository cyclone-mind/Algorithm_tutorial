// 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    // 初始化一个 n×n 的矩阵，所有元素初始为0
    vector<vector<int>> res(n, vector<int>(n, 0));

    // 定义四个方向：右、下、左、上
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // 当前方向索引，0表示向右
    int cur_direction = 0;

    // 当前位置
    int cur_x = 0, cur_y = 0;

    // 填充矩阵，从1开始到n²
    for (int num = 1; num <= n * n; num++)
    {
        // 在当前位置填入当前数字
        res[cur_x][cur_y] = num;

        // 计算下一个预期位置
        int next_x = cur_x + directions[cur_direction][0];
        int next_y = cur_y + directions[cur_direction][1];

        // 判断下一个位置是否越界或已被填充（不为0）
        if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n || res[next_x][next_y] != 0)
        {
            // 改变方向 (右->下->左->上 循环)
            cur_direction = (cur_direction + 1) % 4;

            // 重新计算下一个位置
            next_x = cur_x + directions[cur_direction][0];
            next_y = cur_y + directions[cur_direction][1];
        }

        // 移动到下一个位置
        cur_x = next_x;
        cur_y = next_y;
    }

    return res;
}

// 也可以实现边界收缩法
vector<vector<int>> generateMatrix_boundary(int n)
{
    vector<vector<int>> res(n, vector<int>(n, 0));

    // 定义四个边界
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    // 当前要填入的数字
    int num = 1;

    while (left <= right && top <= bottom)
    {
        // 从左到右填充上边界
        for (int j = left; j <= right; j++)
        {
            res[top][j] = num++;
        }
        top++; // 上边界下移

        // 从上到下填充右边界
        for (int i = top; i <= bottom; i++)
        {
            res[i][right] = num++;
        }
        right--; // 右边界左移

        // 检查是否还有剩余行和列
        if (top <= bottom)
        {
            // 从右到左填充下边界
            for (int j = right; j >= left; j--)
            {
                res[bottom][j] = num++;
            }
            bottom--; // 下边界上移
        }

        if (left <= right)
        {
            // 从下到上填充左边界
            for (int i = bottom; i >= top; i--)
            {
                res[i][left] = num++;
            }
            left++; // 左边界右移
        }
    }

    return res;
}

int main()
{
    int n = 5; // 可以修改为任意正整数

    // 使用模拟行走法生成螺旋矩阵
    vector<vector<int>> matrix = generateMatrix(n);

    // 打印螺旋矩阵
    cout << "模拟行走法生成的螺旋矩阵：" << endl;
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << "\t";
        }
        cout << endl;
    }

    // 使用边界收缩法生成螺旋矩阵
    vector<vector<int>> matrix2 = generateMatrix_boundary(n);

    // 打印螺旋矩阵
    cout << "\n边界收缩法生成的螺旋矩阵：" << endl;
    for (const auto &row : matrix2)
    {
        for (int val : row)
        {
            cout << val << "\t";
        }
        cout << endl;
    }

    return 0;
}