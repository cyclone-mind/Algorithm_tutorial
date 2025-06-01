/*
给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:

创建一个根节点，其值为 nums 中的最大值。
递归地在最大值 左边 的 子数组前缀上 构建左子树。
递归地在最大值 右边 的 子数组后缀上 构建右子树。
返回 nums 构建的 最大二叉树 。


TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

    }
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

/*
每次构建新数组
TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
    TreeNode* node = new TreeNode(0);
    if(nums.size() == 1){
        node->val = nums[0];
        return node;
    }

    int maxValue = 0;
    int maxValueIndex = 0;
    for(int i; i < nums.size(); i++){
        if(nums[i] > maxValue){
            maxValue = nums[i];
            maxValueIndex = i;
        }
    }
    node->val = maxValue;
    if(maxValueIndex > 0){
        std::vector<int> leftNums(nums.begin(),nums.begin() + maxValueIndex);
        node->left = constructMaximumBinaryTree(leftNums);
    }
    if(maxValueIndex < (nums.size() - 1)){
        std::vector<int> rightNums(nums.begin() + maxValueIndex +1 ,nums.end());
        node->right = constructMaximumBinaryTree(rightNums);
    }
    return node;
}
*/

TreeNode *traversal(std::vector<int> &nums, int left, int right) {
    if (left >= right) // 采用左闭右开区间，因此>=
        return nullptr;
    int maxValueIndex = left;
    for (int i = left + 1; i < right; i++) {
        if (nums[i] > nums[maxValueIndex]) {
            maxValueIndex = i;
        }
    }
    TreeNode *root = new TreeNode(nums[maxValueIndex]);
    root->left = traversal(nums, left, maxValueIndex);
    root->right = traversal(nums, maxValueIndex + 1, right);

    return root;
}

// 添加内存释放函数
void deleteTree(TreeNode *root) {
    if (root == nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// 添加打印树的辅助函数
void printTree(TreeNode *root) {
    if (root == nullptr)
        return;
    std::cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

TreeNode *constructMaximumBinaryTree(std::vector<int> &nums) {
    if (nums.empty())
        return nullptr;
    return traversal(nums, 0, nums.size());
}

int main() {
    // 测试用例1
    std::vector<int> nums1 = {3, 2, 1, 6, 0, 5};
    TreeNode *root1 = constructMaximumBinaryTree(nums1);
    std::cout << "测试用例1结果: ";
    printTree(root1);
    std::cout << std::endl;
    deleteTree(root1);

    // 测试用例2
    std::vector<int> nums2 = {3, 2, 1};
    TreeNode *root2 = constructMaximumBinaryTree(nums2);
    std::cout << "测试用例2结果: ";
    printTree(root2);
    std::cout << std::endl;
    deleteTree(root2);

    return 0;
}