#include <type_traits>
#include <vector>
#include<stack>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void preorder(TreeNode *node, vector<int> &result) {
  if (node == nullptr) {
    return;
  }
  result.push_back(node->val);
  preorder(node->left, result);
  preorder(node->right, result);
}
vector<int> preorderTraversal(TreeNode *root) {
//   vector<int> result;
//   preorder(root, result);
//   return result; // 迭代法
    std::stack<TreeNode*> st;
    std::vector<int> result;
    if(root == nullptr) return result;
    st.push(root);
    while (!st.empty()) {
        TreeNode *node = st.top(); // 当前遍历的节点，从栈中取
        st.pop(); // 取到遍历节点后从栈中弹出
        result.push_back(node->val); // 处理节点，处理的节点和遍历的节点是一个节点
        if(node->right) st.push(node->right); // 将非空右子节点推入栈中 
        if(node->left) st.push(node->left); // 将非空左子节点推入栈中
    }
    return result;
}
int main(){}