/*
给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。

完全二叉树
的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第
h 层（从第 0 层开始），则该层包含 1~ 2h 个节点。

*/
#include <queue>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

int countNodes(TreeNode *root) {
    std::queue<TreeNode *> que;
    if (root != NULL)
        que.push(root);
    int result = 0;
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; i++) {
            TreeNode *node = que.front();
            que.pop();
            result++; // 记录节点数量
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
        }
    }
    return result;
}
