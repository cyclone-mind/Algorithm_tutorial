/*
题目：根据中序遍历和后序遍历构造二叉树
给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历，
postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

解题思路：
1. 如果数组大小为零的话，说明是空节点了。
2. 如果不为空，那么取后序数组最后一个元素作为节点元素。
3. 找到后序数组最后一个元素在中序数组的位置，作为切割点。
4. 切割中序数组，切成中序左数组和中序右数组。
5. 切割后序数组，切成后序左数组和后序右数组。
6. 递归处理左区间和右区间。

时间复杂度：O(n)，其中 n 是树中节点的个数
空间复杂度：O(n)，需要存储递归调用的栈空间
*/

#include <vector>

// 二叉树节点结构体定义
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
 * @brief 递归构建二叉树的辅助函数
 * @param inorder 中序遍历数组
 * @param postorder 后序遍历数组
 * @return TreeNode* 返回构建的二叉树根节点
 */
TreeNode *traversal(std::vector<int> &inorder, std::vector<int> &postorder) {
    // 如果后序遍历数组为空，返回空节点
    if (postorder.size() == 0)
        return nullptr;

    // 获取后序遍历的最后一个元素作为当前子树的根节点
    int rootValue = postorder[postorder.size() - 1];
    TreeNode *root = new TreeNode(rootValue);

    // 在中序遍历中找到根节点的位置
    int index = 0;
    for (index = 0; index < inorder.size(); index++) {
        if (inorder[index] == rootValue) {
            break;
        }
    }

    // 切割中序遍历数组，得到左子树和右子树的中序遍历
    // 左闭右开区间[0,index)
    std::vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
    // 左闭右开区间[index+1,end)
    std::vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());

    // 移除后序遍历数组的最后一个元素（根节点）
    postorder.resize(postorder.size() - 1);

    // 切割后序遍历数组，得到左子树和右子树的后序遍历
    // 左子树的后序遍历长度等于左子树的中序遍历长度
    std::vector<int> leftPostorder(postorder.begin(),
                                   postorder.begin() + leftInorder.size());
    std::vector<int> rightPostorder(postorder.begin() + leftInorder.size(),
                                    postorder.end());

    // 递归构建左子树和右子树
    root->left = traversal(leftInorder, leftPostorder);
    root->right = traversal(rightInorder, rightPostorder);

    return root;
}

/**
 * @brief 根据中序遍历和后序遍历构建二叉树
 * @param inorder 中序遍历数组
 * @param postorder 后序遍历数组
 * @return TreeNode* 返回构建的二叉树根节点
 */
TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder) {
    // 如果输入数组为空，返回空树
    if (inorder.size() == 0 || postorder.size() == 0)
        return nullptr;
    return traversal(inorder, postorder);
}

// 测试代码
int main() {
    // 测试用例
    std::vector<int> inorder = {9, 3, 15, 20, 7};   // 中序遍历
    std::vector<int> postorder = {9, 15, 7, 20, 3}; // 后序遍历
    TreeNode *root = buildTree(inorder, postorder);
}