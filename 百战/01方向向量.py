# -*- coding: utf-8 -*-

"""
演示如何在二维网格中使用四方向和八方向向量查找邻居坐标
"""

# 定义四方向向量 (上, 下, 左, 右) - 假设 Y 轴向上增加
# 注意：根据你的坐标系定义（例如，图像处理中 Y 通常向下增加），向量可能会不同
four_directions = [
    (0, 1),  # 上
    (0, -1), # 下
    (-1, 0), # 左
    (1, 0)   # 右
]

# 定义八方向向量 (包括对角线)
eight_directions = [
    (0, 1), (0, -1), (-1, 0), (1, 0), # 上, 下, 左, 右
    (-1, 1), (1, 1), (-1, -1), (1, -1) # 左上, 右上, 左下, 右下
]

def find_neighbors(x: int, y: int, directions: list[tuple[int, int]]) -> list[tuple[int, int]]:
    """
    根据给定的方向向量查找一个点的邻居坐标

    Args:
        x (int): 当前点的 x 坐标
        y (int): 当前点的 y 坐标
        directions (list[tuple[int, int]]): 方向向量列表 (例如 four_directions 或 eight_directions)

    Returns:
        list[tuple[int, int]]: 邻居坐标列表
    """
    neighbors = []
    for dx, dy in directions:
        neighbor_x = x + dx
        neighbor_y = y + dy
        neighbors.append((neighbor_x, neighbor_y))
    return neighbors

# --- 示例用法 ---
current_pos = (3, 4) # 假设当前点在 (3, 4)

# 查找四方向邻居
four_way_neighbors = find_neighbors(current_pos[0], current_pos[1], four_directions)
print(f"点 {current_pos} 的四方向邻居是: {four_way_neighbors} 🧭")

# 查找八方向邻居
eight_way_neighbors = find_neighbors(current_pos[0], current_pos[1], eight_directions)
print(f"点 {current_pos} 的八方向邻居是: {eight_way_neighbors} ✨")

# --- 考虑边界的示例 (可选) ---
def find_valid_neighbors(x: int, y: int, directions: list[tuple[int, int]], grid_width: int, grid_height: int) -> list[tuple[int, int]]:
    """
    查找网格内的有效邻居坐标，排除越界的点

    Args:
        x (int): 当前点的 x 坐标
        y (int): 当前点的 y 坐标
        directions (list[tuple[int, int]]): 方向向量列表
        grid_width (int): 网格宽度
        grid_height (int): 网格高度

    Returns:
        list[tuple[int, int]]: 有效邻居坐标列表
    """
    valid_neighbors = []
    for dx, dy in directions:
        neighbor_x = x + dx
        neighbor_y = y + dy
        # 检查邻居是否在网格边界内
        if 0 <= neighbor_x < grid_width and 0 <= neighbor_y < grid_height:
            valid_neighbors.append((neighbor_x, neighbor_y))
    return valid_neighbors

grid_w, grid_h = 5, 5 # 假设一个 5x5 的网格 (x 从 0 到 4, y 从 0 到 4)
edge_pos = (0, 0) # 边界上的点

# 查找边界点 (0, 0) 的有效八方向邻居
valid_neighbors_at_edge = find_valid_neighbors(edge_pos[0], edge_pos[1], eight_directions, grid_w, grid_h)
print(f"网格 {grid_w}x{grid_h} 中，点 {edge_pos} 的有效八方向邻居是: {valid_neighbors_at_edge} 🗺️")
