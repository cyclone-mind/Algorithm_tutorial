/*
给定二叉搜索树（BST）的根节点 root 和一个整数值 val。

你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。
*/
#include <vector>

// 二叉树节点结构体定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

// 递归
/*

TreeNode* searchBST(TreeNode* root, int val) {
    if(root == nullptr || root->val == val) return root;
    TreeNode* result;
    if(val < root->val) result = searchBST(root->left, val);        
    if(val > root->val) result = searchBST(root->right, val);
    return result;        
}
*/
// 迭代
TreeNode* searchBST(TreeNode* root, int val) {
    while (root != nullptr) {
        if (val < root->val) {
            root = root->left;
        } else if (val > root->val) {
            root = root->right;
        } else {
            return root;
        }
    }     
    return nullptr; 
}


int main(){}