// 给你一个二叉树的根节点 root ， 检查它是否轴对称。

#include <cstddef>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

bool compare(TreeNode* left, TreeNode*right){ // 当前左右节点树对称吗？
    if(left == NULL && right != NULL) return false; // 左空树 右非空树，不对称
    else if (left != NULL && right == NULL) return false; // 左非空树 右空树，不对称
    else if (left == NULL && right == NULL) return true; // 左右都空树，对称
    else if (left->val != right->val) return false; // 左右树的根节点值不相等，不对称
    // 如果左右节点树本身值相等，那么是否对称取决于其各自孩子是否对称。
    bool outside = compare(left->left, right->right); // 左树的左子树和右树的右子树是否对称？
    bool inside = compare(left->right, right->left); // 左树的右子树和右树的左子树是否对称？
    bool result = outside && inside; // 左树和右树对称吗？
    return result;
}

bool isSymmetric(TreeNode* root) {
    return compare(root->left, root->right);
}

int main(){}