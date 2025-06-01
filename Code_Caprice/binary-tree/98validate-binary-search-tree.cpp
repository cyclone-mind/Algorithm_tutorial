#include <climits>

/*
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
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

long long maxVal = LONG_MIN; // 因为后台测试数据中有int最小值
bool isValidBST(TreeNode *root) {
    // 空节点也可以是二叉搜索树
    if (root == NULL)
        return true;
    // 左节点树是否是二叉搜索树
    bool left = isValidBST(root->left);
    // 中序遍历，验证遍历的元素是不是从小到大
    if (maxVal < root->val)
        maxVal = root->val;
    else
        return false;
    bool right = isValidBST(root->right);

    return left && right;
}
int main() {}