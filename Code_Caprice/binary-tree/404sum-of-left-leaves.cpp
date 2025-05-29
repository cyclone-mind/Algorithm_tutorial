/*
给定二叉树的根节点 root ，返回所有左叶子之和。

一个节点的左子节点不为空，且左子节点没有子节点，则该左子节点是一个左叶子节点。
判断当前节点是不是左叶子是无法判断的，必须要通过节点的父节点来判断其左孩子是不是左叶子。

使用递归：任意一个节点的左叶子之和等于其左节点和右节点的左叶子之和。凭借这句话，确定使用后序遍历，左右中。
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

int sumOfLeftLeaves(TreeNode *root) { // 返回节点的所有左叶子值的和
    if (root == nullptr)
        return 0; // 空节点的左叶子之和为0
    if (root->left == nullptr && root->right == nullptr)
        return 0; // 叶子节点的左叶子之和为0

    int leftValue = sumOfLeftLeaves(root->left); // 左 向左遍历，求左节点的左叶子之和
    if (root->left && !root->left->left &&!root->left->right) { // 左子树就是一个左叶子的情况
        leftValue = root->left->val; // 条件判断，当前节点的左孩子是否是左叶子，如果是记录此值为左节点的左叶子之和
    }
    int rightValue = sumOfLeftLeaves(root->right); // 右 向右遍历， 求右节点的左叶子之和

    int sum = leftValue + rightValue; // 中 左右节点的左叶子之和加起来就是当前节点的左叶子之和。
    return sum;
}

int main() {}