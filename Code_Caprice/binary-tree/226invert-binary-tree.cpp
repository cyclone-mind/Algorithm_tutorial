// 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
#include <algorithm>
#include <cstddef>
#include <stack>
#include <utility>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

/*
递归法，前序
TreeNode* invertTree(TreeNode* root) {
    if(root == nullptr) return nullptr;
    std::swap(root->left,root->right); // 中
    invertTree(root->left); // 左
    invertTree(root->right); // 右
    return root;
}
*/
/*
迭代法，前序遍历
TreeNode* invertTree(TreeNode* root) {
    std::stack<TreeNode*> st;
    if(root == nullptr) return nullptr;
    st.push(root);
    while(!st.empty()){
        TreeNode *node = st.top();
        st.pop();
        std::swap(node->left, node->right); // 这里交换的是指针本身的值，并不是指针指向的内容。
        // 交换两个 nullptr 或者一个有效指针和一个 nullptr 都是合法的操作，不会引发运行时错误。
        if(node->left) st.push(node->left);
        if(node->right) st.push(node->right);
    }
    return root;
}
*/


int main(){}