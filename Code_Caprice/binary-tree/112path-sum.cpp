/*
给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。
判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和
targetSum 。 如果存在，返回 true ；否则，返回 false 。

叶子节点 是指没有子节点的节点。
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

// 遍历所有节点，每遍历一个值，目标值减去节点值，遍历完成就加上该节点值

bool traversal(TreeNode *node, int count) {
    if (node->left == nullptr && node->right == nullptr && count == 0) {
        return true;
    }
    if (node->left) {
        count -= node->left->val;
        bool result = traversal(node->left, count);
        if (result)
            return true;
        count += node->left->val;
    }
    if (node->right) {
        count -= node->right->val;
        bool result = traversal(node->right, count);
        if (result)
            return true;
        count += node->right->val;
    }
    return false;
}
bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr)
        return false;
    int sum = targetSum - root->val;
    return traversal(root, sum);
}

int main(){}
