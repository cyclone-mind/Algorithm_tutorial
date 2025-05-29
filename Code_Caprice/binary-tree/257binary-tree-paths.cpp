/*
给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。

叶子节点 是指没有子节点的节点。
输入：root = [1,2,3,null,5]
输出：["1->2->5","1->3"]

解题思路：
1. 使用深度优先搜索(DFS)遍历二叉树
2. 使用vector记录当前路径上的所有节点值
3. 当到达叶子节点时，将路径转换为字符串并加入结果集
4. 回溯时需要移除当前节点，以便继续探索其他路径

时间复杂度：O(N)，其中N是二叉树的节点数
空间复杂度：O(H)，其中H是树的高度，最坏情况下为O(N)
*/

#include <string>
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

/**
 * @brief 递归遍历二叉树，收集所有从根到叶子的路径
 * @param node 当前节点
 * @param path 当前路径上的所有节点值
 * @param result 存储所有路径的结果集
 */
void traversal(TreeNode *node, std::vector<int> &path,
               std::vector<std::string> &result) {
    // 将当前节点值加入路径
    path.push_back(node->val);

    // 如果是叶子节点，将当前路径转换为字符串并加入结果集
    if (node->left == nullptr && node->right == nullptr) {
        std::string spath;
        // 将路径中的数字转换为字符串，并用"->"连接
        for (int s : path) {
            spath += std::to_string(s);
            spath += "->";
        }
        // 移除最后多余的"->"
        spath.pop_back();
        spath.pop_back();
        result.push_back(spath);
        return;
    };

    // 递归遍历左子树
    if (node->left) {
        traversal(node->left, path, result);
        // 回溯：移除当前节点
        path.pop_back();
    }
    // 递归遍历右子树
    if (node->right) {
        traversal(node->right, path, result);
        // 回溯：移除当前节点
        path.pop_back();
    }
}

/**
 * @brief 获取二叉树所有从根到叶子的路径
 * @param root 二叉树的根节点
 * @return 包含所有路径的字符串数组
 */
std::vector<std::string> binaryTreePaths(TreeNode *root) {
    std::vector<std::string> result;
    std::vector<int> path;
    traversal(root, path, result);
    return result;
}

int main() {}