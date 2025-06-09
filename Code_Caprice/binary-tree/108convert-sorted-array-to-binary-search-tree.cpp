/*
108. 将有序数组转换为二叉搜索树
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 平衡 二叉搜索树。

*/
#include <iostream>
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

TreeNode* traversal(std::vector<int>& nums, int left, int right){
    if(left > right) return nullptr; // 左闭右闭区间
    int mid = left + ((right - left) /2);
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = traversal(nums, left, mid - 1);
    root->right = traversal(nums, mid + 1, right);
    return root;
}
TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    return traversal(nums, 0, nums.size()-1);
}