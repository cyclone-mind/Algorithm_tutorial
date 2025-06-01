/*
给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。

完全二叉树的定义如下：
在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。
若最底层为第h 层（从第 0 层开始），则该层包含 1~ 2h 个节点。

*/
#include <cerrno>
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

/*
这个遍历对任何一个二叉树都有效,时间复杂度和空间复杂度都是O(n)
层序遍历
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
迭代遍历，后序写法
int countNodes(TreeNode *root) {
    if(root == nullptr) return 0; // 遍历到空节点，空节点的节点个数为0
    int left = countNodes(root->left);
    int right = countNodes(root->right);
    int result = left + right + 1;
    return result;
}
*/

// 考虑到利用完全二叉树的特性，完全二叉树有两种情况，一种情况是满二叉树，另一种情况是最底层的节点没有填满。满二叉树是公式就能求出来

// 那么我们需要找到完全二叉树中满足满二叉树的条件的子树，利用公式简化计算

int countNodes(TreeNode *root) {
    // 递归写法
    if (root == nullptr)
        return 0; // 遍历到空节点，空节点树的节点个数为0
    // 如果不是空节点树，那么要判断左、右子树是不是满二叉树？如果是，利用特性计算，如果不是，则继续向下递归
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    int leftdepth = 0, rightdepth = 0;
    while (left) {
        left = left->left;
        leftdepth++;
    }
    while (right) {
        right = right->right;
        rightdepth++;
    }
    if (leftdepth == rightdepth) {
        return (2 << leftdepth) - 1;
    }

    // 如果左右子树的左右深度不相同,那么该节点不是一个满二叉树,那么该节点继续向下递归，计算下一个树的数量。
    int leftTreeNum = countNodes(root->left);    // 左
    int rightTreeNum = countNodes(root->right);  // 右
    int result = leftTreeNum + rightTreeNum + 1; // 中
    return result;
}

int main() {}
