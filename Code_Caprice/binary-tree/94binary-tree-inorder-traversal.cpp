#include <cstddef>
#include <stack>
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

void inorder(TreeNode *root, std::vector<int> &result) {
    if (root == nullptr)
        return;
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
}
std::vector<int> inorderTraversal(TreeNode *root) {
    std::stack<TreeNode *> st;
    std::vector<int> result;
    TreeNode *cur = root;
    while (cur != NULL || !st.empty()) {
        if (cur != NULL) {
            st.push(cur);    // 记录遍历过的节点，应该是当前节点本身
            cur = cur->left; // 往下遍历 左
        } else {
            TreeNode *node =
                st.top(); // 取出遍历节点，命名为node以避免和外部cur冲突
            st.pop();     // 从栈：记录中删除正在遍历的节点
            result.push_back(node->val); // 处理节点   中
            cur = node->right;           // 右
        }
    }
    return result;
}

int main() {}