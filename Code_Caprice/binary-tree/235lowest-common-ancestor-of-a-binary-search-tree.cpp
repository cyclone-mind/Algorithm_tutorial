/*
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：
"对于有根树 T 的两个结点 p、q，
最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x
的深度尽可能大（一个节点也可以是它自己的祖先）。"
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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr)
        return nullptr;

    if (root->val > p->val &&
        root->val > q->val) { // 如果p和q都小于root，说明LCA在左子树
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        if (left != nullptr) {
            return left;
        }
    } else if (root->val < p->val &&
               root->val < q->val) { // 如果p和q都大于root，说明LCA在右子树
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (right != nullptr) {
            return right;
        }
    }
    // 其他情况，root就是LCA
    return root;
}

/*
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // 如果p和q都小于root，说明LCA在左子树
    if (root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    }
    // 如果p和q都大于root，说明LCA在右子树
    else if (root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    }
    // 其他情况，root就是LCA
    else return root;
}
*/
int main() {}
