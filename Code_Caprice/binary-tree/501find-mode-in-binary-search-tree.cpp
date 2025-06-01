/*
给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有
众数（即，出现频率最高的元素）。

如果树中有不止一个众数，可以按 任意顺序 返回。

假定 BST 满足如下定义：

结点左子树中所含节点的值 小于等于 当前节点的值
结点右子树中所含节点的值 大于等于 当前节点的值
左子树和右子树都是二叉搜索树
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
TreeNode *pre = nullptr;
int count = 0;
int maxCount = 0;
std::vector<int> result;
void traversal(TreeNode *cur) {
    if (cur == nullptr)
        return;
    traversal(cur->left);
    if (pre == nullptr) {
        count = 1;
    } else if (cur->val == pre->val) {
        count++;
    } else {
        count = 1;
    }
    pre = cur;
    if (count == maxCount)
        result.push_back(cur->val);
    if (count > maxCount) {
        result.clear();
        maxCount = count;
        result.push_back(cur->val);
    }
    traversal(cur->right);
    return;
}

std::vector<int> findMode(TreeNode *root) {
    traversal(root);
    return result;
}

int main(){}