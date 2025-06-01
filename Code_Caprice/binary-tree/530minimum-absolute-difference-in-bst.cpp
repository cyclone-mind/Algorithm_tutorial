/*
给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。

差值是一个正数，其数值等于两值之差的绝对值。
*/
#include <algorithm>
#include <cstddef>
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

int result = INT_MAX;
TreeNode* pre = nullptr;
void traversal(TreeNode* cur){
    if(cur == nullptr) return;
    traversal(cur->left);
    if(pre !=nullptr){
        result = std::min(result, cur->val - pre->val);
    }
    pre = cur;
    traversal(cur->right);
}

int getMinimumDifference(TreeNode* root) {
    traversal(root);
    return result;
}
int main(){}