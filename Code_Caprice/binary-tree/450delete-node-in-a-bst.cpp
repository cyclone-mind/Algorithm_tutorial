/*
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key
对应的节点，并保证二叉搜索树的性质不变
。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

首先找到需要删除的节点；
如果找到了，删除它。
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr)
        return nullptr;
    if (root->val == key) {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        } else if (root->left != nullptr && root->right == nullptr) {
            auto node = root->left;
            delete root;
            return node;
        }  else if (root->right != nullptr && root->left == nullptr) {
            auto node = root->right;
            delete root;
            return node;
        } else {
            TreeNode* cur = root->right;
            while (cur->left !=nullptr) {
                cur = cur->left;
            }
            cur->left = root->left;
            auto tmp = root;
            root = root->right;
            delete tmp;
            return root;
        }
    }

    if (key > root->val) {
        root->right = deleteNode(root->right, key);
    }
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    }
    return root;
}

int main(){}