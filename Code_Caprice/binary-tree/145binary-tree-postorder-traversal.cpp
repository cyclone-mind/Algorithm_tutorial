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

void postorder(TreeNode *root, std::vector<int> &result){
    if(root == nullptr) return ;
    postorder(root->left,result);
    postorder(root->right, result);
    result.push_back(root->val);
}
std::vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> result;
    postorder(root, result);
    return  result;
}

int main(){}