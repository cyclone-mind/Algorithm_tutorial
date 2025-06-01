/*
给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

假设二叉树中至少有一个节点。

*/

#include <algorithm>
#include <cstdint>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

// 全局变量设计
int result;               // 存储最终结果
int maxDepth = INT16_MIN; // 记录最大深度，初始化为最小整数值

// 递归函数设计
void traversal(TreeNode *node, int depth) {
    // 思考：如何判断叶子节点？
    // 实现：当节点的左右子树都为空时，说明到达叶子节点
    if (node->left == nullptr && node->right == nullptr) {
        // 思考：如何更新结果？
        // 实现：只有当当前深度大于最大深度时才更新
        if (depth > maxDepth) {
            maxDepth = depth;
            result = node->val;
        }
        return;
    }

    // 思考：如何遍历左子树？
    // 实现：先检查左子树是否存在，然后递归遍历
    if (node->left) {
        depth++; // 进入下一层，深度+1
        traversal(node->left, depth);
        depth--; // 回溯，恢复深度
    }

    // 思考：如何遍历右子树？
    // 实现：检查右子树是否存在，然后递归遍历
    if (node->right) {
        depth++;
        traversal(node->right, depth);
        depth--;
    }
    return;
}

// 主函数设计
int findBottomLeftValue(TreeNode *root) {
    // 思考：如何开始遍历？
    // 实现：从根节点开始，初始深度为0
    traversal(root, 0);
    return result;
}

int main() {}