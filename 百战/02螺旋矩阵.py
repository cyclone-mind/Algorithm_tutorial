# -*- coding: utf-8 -*-
from typing import List # 建议加上类型提示

def spiralOrder(matrix: List[List[int]]): # 模拟行走 + 转向
    """
    模拟行走路径并转向的方法

    Args:
        matrix (List[List[int]]): 输入的 m x n 矩阵

    Returns:
        List[int]: 按螺旋顺序排列的元素列表
    """
    res = []
    if not matrix or not matrix[0]: # 更简洁的判空
        return res
    n = len(matrix)
    m = len(matrix[0])

    # 定义四个方向 (右, 下, 左, 上)
    directions = [[0,1],[1,0],[0,-1],[-1,0]]
    # 定义当前方向索引
    cur_direction = 0
    # 定义当前位置
    cur_x,cur_y = 0,0
    # 定义访问矩阵
    visited = [[False] * m for _ in range(n)]
    # 遍历矩阵
    for _ in range(n * m):
        res.append(matrix[cur_x][cur_y])
        visited[cur_x][cur_y] = True
        # 计算下一个预期位置
        next_x = cur_x + directions[cur_direction][0]
        next_y = cur_y + directions[cur_direction][1]
        # 判断下一个位置是否越界或已访问
        if next_x < 0 or next_x >= n or next_y < 0 or next_y >= m or visited[next_x][next_y]:
            # 改变方向 (右->下->左->上 循环)
            cur_direction = (cur_direction + 1) % 4
            # 重新计算下一个位置
            next_x = cur_x + directions[cur_direction][0]
            next_y = cur_y + directions[cur_direction][1]
        # 前进到下一个位置
        cur_x = next_x
        cur_y = next_y
    return res


def spiralOrder_boundary(matrix: List[List[int]]): # 边界收缩法
    """
    通过不断收缩边界来模拟螺旋遍历的方法

    Args:
        matrix (List[List[int]]): 输入的 m x n 矩阵

    Returns:
        List[int]: 按螺旋顺序排列的元素列表
    """
    res = []
    if not matrix or not matrix[0]:
        return res
    rows, cols = len(matrix), len(matrix[0])
    top, bottom = 0, rows - 1
    left, right = 0, cols - 1

    while left <= right and top <= bottom:
        # ➡️ 从左到右 (遍历上边界)
        for j in range(left, right + 1):
            res.append(matrix[top][j])
        top += 1 # 上边界下移

        # ⬇️ 从上到下 (遍历右边界)
        for i in range(top, bottom + 1):
            res.append(matrix[i][right])
        right -= 1 # 右边界左移

        # 检查是否还有剩余行和列需要处理 (防止单行或单列时重复添加)
        if left <= right and top <= bottom:
            # ⬅️ 从右到左 (遍历下边界)
            for j in range(right, left - 1, -1):
                res.append(matrix[bottom][j])
            bottom -= 1 # 下边界上移

            # ⬆️ 从下到上 (遍历左边界)
            for i in range(bottom, top - 1, -1):
                res.append(matrix[i][left])
            left += 1 # 左边界右移

    return res


# --- 测试 ---
matrix1 = [[1,2,3],[4,5,6],[7,8,9]]
matrix2 = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]

print("--- 测试 matrix1 ---")
print("方法1 (模拟行走):", spiralOrder(matrix1))
print("方法2 (边界收缩):", spiralOrder_boundary(matrix1))
print("-" * 20)

print("--- 测试 matrix2 ---")
print("方法1 (模拟行走):", spiralOrder(matrix2))
print("方法2 (边界收缩):", spiralOrder_boundary(matrix2))
print("-" * 20)