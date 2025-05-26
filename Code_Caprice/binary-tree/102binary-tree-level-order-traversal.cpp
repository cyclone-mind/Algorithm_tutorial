
#include <queue>

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

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::queue<TreeNode*> que;
    std::vector<std::vector<int>> result;
    if(root != NULL) que.push(root);
    while (!que.empty()) {
        int size = que.size();
        std::vector<int> vec;
        for (int i = 0; i < size; i++) {
            TreeNode *node = que.front();
            que.pop();
            vec.push_back(node->val);
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right); 
        }
        result.push_back(vec);
    }
    return result;   
}

int main(){}