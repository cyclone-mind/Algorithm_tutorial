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

bool compare(TreeNode *left, TreeNode *right) {
    /**
     * @brief 比较两棵子树是否对称。
     *
     * 该函数采用递归的方式，从底部（子节点）开始向上（父节点）判断对称性。
     * 1.
     * 首先检查基本情况：如果一棵树为空而另一棵不为空，则不对称；如果两棵都为空，则对称。
     * 2. 如果两棵树的根节点值不相等，则不对称。
     * 3.
     * 递归地检查“外侧”子树（左树的左子树与右树的右子树）和“内侧”子树（左树的右子树与右树的左子树）是否对称。
     * 4. 只有当所有这些条件都满足时，当前两棵子树才被认为是轴对称的。
     *
     * 这种“先判断子树，再判断当前节点”的逻辑，类似于后序遍历的特性。
     *
     * @param left 左子树的根节点。
     * @param right 右子树的根节点。
     * @return 如果两棵子树对称，返回 true；否则返回 false。
     */
    if (left == NULL && right != NULL)
        return false; // 左空树 右非空树，不对称
    else if (left != NULL && right == NULL)
        return false; // 左非空树 右空树，不对称
    else if (left == NULL && right == NULL)
        return true; // 左右都空树，对称
    else if (left->val != right->val)
        return false; // 左右树的根节点值不相等，不对称
    // 如果左右节点树本身值相等，那么是否对称取决于其各自孩子是否对称。
    bool outside = compare(
        left->left, right->right); // 左树的左子树和右树的右子树是否对称？
    bool inside = compare(left->right,
                          right->left); // 左树的右子树和右树的左子树是否对称？
    bool result = outside && inside;    // 左树和右树对称吗？
    return result;
}

bool isSymmetric(TreeNode *root) { return compare(root->left, root->right); }

int main() {}