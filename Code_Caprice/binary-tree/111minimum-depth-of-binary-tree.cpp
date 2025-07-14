/*
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。
*/

#include <algorithm>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

/*
计算二叉树的最小深度。
这里的核心思想是定义一个辅助函数，计算从**当前节点**到其**子树中最近叶子节点**的最短路径上的**节点数量**。
这个辅助值在概念上可以理解为“当前节点的最小深度”（区别于标准“节点的高度”）。
*/

int getMinDepthFromNode(
    TreeNode
        *node) { // 获取从当前节点开始的最小深度（到最近叶子节点的节点数量）
    if (node == nullptr)
        return 0; // 空节点，路径长度为 0

    // 单层递归逻辑
    int leftPathLength =
        getMinDepthFromNode(node->left); // 左子树的最小路径长度（节点数量）
    int rightPathLength =
        getMinDepthFromNode(node->right); // 右子树的最小路径长度（节点数量）

    // 处理特殊情况：当前节点只有一个子树（即单边子树）
    // 题目定义叶子节点是左右子节点都为空的节点。
    // 如果一个节点只有一个子节点，那么它到最近叶子节点的路径必须经过那个唯一的子节点。
    if (leftPathLength == 0 && rightPathLength != 0) {
        // 左子树为空，右子树不为空，最小深度来自右子树
        return rightPathLength + 1; // 加上当前节点
    }
    if (leftPathLength != 0 && rightPathLength == 0) {
        // 右子树为空，左子树不为空，最小深度来自左子树
        return leftPathLength + 1; // 加上当前节点
    }

    // 处理常规情况：左右子树都存在，或当前节点是叶子节点（左右子树都为空）
    // 此时，选择左右子树中较短的路径，并加上当前节点自身
    int result = 1 + std::min(leftPathLength, rightPathLength);
    return result;
}

int minDepth(TreeNode *root) {
    return getMinDepthFromNode(root); // 调用辅助函数计算根节点的最小深度
}

int main() {}