/*
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

叶子节点 是指没有子节点的节点。
*/
#include <vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

std::vector<std::vector<int>> result;
std::vector<int> path;
void traversal(TreeNode* node, int count){
    if (node->left == nullptr && node->right == nullptr && count == 0) {
        result.push_back(path);
        return;
    }
    if(node->left == nullptr && node->right == nullptr) return;
    if(node->left){
        path.push_back(node->left->val);
        count -= node->left->val;
        traversal(node->left, count);
        count += node->left->val;
        path.pop_back();
    }
    if(node->right){
        path.push_back(node->right->val);
        count -= node->right->val;
        traversal(node->right, count);
        count += node->right->val;
        path.pop_back();
    }
    return;
}

std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
    result.clear();
    path.clear();
    if(root == nullptr) return result;
    int count = targetSum - root->val;
    path.push_back(root->val);
    traversal(root, count);
    return result;
}

int main(){}