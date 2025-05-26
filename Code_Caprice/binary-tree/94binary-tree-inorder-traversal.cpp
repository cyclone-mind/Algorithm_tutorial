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

void inorder(TreeNode *root, std::vector<int> &result){
    if(root == nullptr) return ;
    inorder(root->left,result);
    result.push_back(root->val);
    inorder(root->right, result);
}
std::vector<int> inorderTraversal(TreeNode *root) {
    // std::vector<int> result;
    // inorder(root, result);
    // return  result;
    std::stack<TreeNode*> st;
    std::vector<int> result;
    TreeNode *cur = root;
    while (cur != NULL || !st.empty()) {
        if(cur != NULL){
            st.push(cur->left); // 记录遍历过的节点
            cur = cur->left; // 往下遍历 左
        } else {
            TreeNode *cur = st.top(); // 取出遍历节点
            st.pop(); // 从栈：记录中删除正在遍历的节点
            result.push_back(cur->val); // 处理节点   中
            cur = cur->right; // 右
        }
    }
    return result;
}

int main(){}