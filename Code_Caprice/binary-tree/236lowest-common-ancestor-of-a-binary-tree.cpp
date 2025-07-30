/*
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：
“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，
满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
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


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    if(root == nullptr) return nullptr; // 遍历到空节点返回空节点
    if(root == p || root == q) return root; // 遍历到 p 或 q 节点返回 p 或 q 节点
    TreeNode* left = lowestCommonAncestor(root->left, p, q); // 向左递归拿到 p 或 q 或空节点
    TreeNode* right = lowestCommonAncestor(root->right, p, q); // 向右递归拿到 p 或 q 或空节点
    if(left != nullptr && right != nullptr){ // 如果左右子节点不是空节点，那么就是 p 和 q 节点， 那么返回该节点，就是公共祖先
        return root;
    } else if (left != nullptr && right == nullptr) { // 如果右节点是空节点，左节点是 p 或 q 节点，那么把 p 或 q 节点向上返回
        return left;
    } else if (right != nullptr && left == nullptr) { // 如果左节点是空节点，右节点是 p 或 q 节点，那么把 p 或 q 节点向上返回
        return right;
    } else {
        return nullptr;
    }

}

int main(){}