/*
给定一个二叉树，判断它是否是 平衡二叉树

平衡二叉树 是指该树所有节点的左右子树的高度相差不超过 1。
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

int getheight(TreeNode *node) { // 获得当前节点高度，或者获得当前节点树不是平衡树（-1）相当于两者结合
    if (node == nullptr)
        return 0; // 空节点数的高度为0

    int leftheight = getheight(node->left); // 获得当前节点左子树高度
    if (leftheight == -1) // 如果左子树高度为-1，则表明这个节点树不是平衡树，相应的也返回-1  
        return -1; 
    int rightheight = getheight(node->right); // 获得当前节点右子树高度
    if (rightheight == -1) // 如果右子树高度为-1，则表明这个节点树不是平衡树，相应的也返回-1  
        return -1;
    int diff = std::abs(leftheight - rightheight); // 左右子树高度差值，绝对值
    return diff > 1 ? -1 : 1 + std::max(leftheight, rightheight); // 如果大于1，则返回-1表明不平衡，否则将高度+1作为当前节点树的高度
}

bool isBalanced(TreeNode *root) { return getheight(root) == -1 ? false : true; }

int main() {}
