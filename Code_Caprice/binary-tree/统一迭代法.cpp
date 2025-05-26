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

std::vector<int> inorderTraversal(TreeNode *root) {
  std::stack<TreeNode *> st;
  std::vector<int> result;
  if (root == NULL) {
    return result;
  } else {
    st.push(root);
  }
  while (!st.empty()) {
    TreeNode *node = st.top();
    if (node != nullptr) {
      st.pop();
      if (node->right)
        st.push(node->right); // 右
      st.push(node);          // 这里不是访问中节点
      st.push(NULL);          // 使用null标记一下这个中节点
      if (node->left)
        st.push(node->left); // 左
    } else {
      st.pop(); // 弹出 NULL
      TreeNode *node =
          st.top(); // 获取 NULL 后面的节点 ，这里是真正访问节点的地方
      st.pop();     // 弹出该节点
      result.push_back(node->val); // 处理该节点（加入结果集）
    }
  }
  return result;
}

std::vector<int> preorderTraversal(TreeNode *root) {
  std::vector<int> result;
  std::stack<TreeNode *> st;
  if (root != NULL)
    st.push(root);
  while (!st.empty()) {
    TreeNode *node = st.top();
    if (node != NULL) {
      st.pop();
      if (node->right)
        st.push(node->right); // 右
      if (node->left)
        st.push(node->left); // 左
      st.push(node);         // 中
      st.push(NULL);
    } else {
      st.pop();
      node = st.top();
      st.pop();
      result.push_back(node->val);
    }
  }
  return result;
}
std::vector<int> postorderTraversal(TreeNode *root) {
  std::vector<int> result;
  std::stack<TreeNode *> st;
  if (root != NULL)
    st.push(root);
  while (!st.empty()) {
    TreeNode *node = st.top();
    if (node != NULL) {
      st.pop();
      st.push(node); // 中
      st.push(NULL);
      if (node->right)
        st.push(node->right); // 右
      if (node->left)
        st.push(node->left); // 左
    } else {
      st.pop();
      node = st.top();
      st.pop();
      result.push_back(node->val);
    }
  }
  return result;
}

int main() {}