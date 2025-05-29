/*
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。
*/

#include <algorithm>
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
二叉树的最小深度可以转化为根节点的最小高度。
*/

int gethMinHeight(TreeNode* node){ // 获取当前节点的最小高度
    if(node == nullptr) return 0; // 空节点的最小高度为0

    // 单层递归逻辑
    int leftminheight = gethMinHeight(node->left); //当前节点左子树的最小高度 
    int rightminheight = gethMinHeight(node->right); // 当前节点右子树的最小高度
    if(leftminheight == 0 && rightminheight != 0){ 
    // 对于一个子树是空节点另一个子树是非空节点，那么最小高度应从非空节点计算。
    // 为什么？因为题目要求是根节点到最近叶子节点，叶子节点及左右子树都为空才是叶子节点。
        return rightminheight + 1;
    }
    if(leftminheight != 0 && rightminheight == 0){ // 对于一个子树是空节点另一个子树是非空节点，那么最小高度应从非空节点计算
        return leftminheight + 1;
    }
    int result = 1 + std::min(leftminheight, rightminheight); // 任意一个非空节点。其最小高度为其左右两个子树的最小高度的较小的那个+1
    return result;

}


int minDepth(TreeNode* root) {
    return gethMinHeight(root);
}

int main(){}