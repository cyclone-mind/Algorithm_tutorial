// 给定一个二叉树 root ，返回其最大深度。

// 二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。

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

int getheight(TreeNode *node) { // 对于任意一个节点，返回其高度。
  if (node == nullptr)
    return 0; // 对于空节点，高度为0。

  // 对于任意一个非空节点，其高度等于左孩子的高度和右孩子高度的最大值+1。
  // 因此需要求出其孩子的高度，其孩子本身也是一个节点，因此可以使用递归。
  int leftheight = getheight(node->left); // 左
  int rightheight = getheight(node->right); // 右
  int height = 1 + std::max(leftheight, rightheight); // 中，将高度信息返回给上一层
  return height;
}

/*
自底向上: 高度的计算需要先知道左右子树的高度，才能计算当前节点的高度。
这种“先处理孩子节点，再处理父节点”的思路，正是后序遍历的特点。它是一种“自底向上”解决问题的方式。
而像查找节点这种问题，可能用前序遍历（“自顶向下”）更自然。
*/

int maxDepth(TreeNode *root) { return getheight(root); }

int main() {}