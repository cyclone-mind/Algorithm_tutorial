/*
968. 监控二叉树
困难
相关标签
premium lock icon
相关企业
给定一个二叉树，我们在树的节点上安装摄像头。

节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。

计算监控树的所有节点所需的最小摄像头数量。

示例 1：

输入：[0,0,null,0,0]
输出：1
解释：如图所示，一台摄像头足以监控所有节点。
示例 2：

输入：[0,0,null,0,null,0,null,null,0]
输出：2
解释：需要至少两个摄像头来监视树的所有节点。
上图显示了摄像头放置的有效位置之一。

提示：

给定树的节点数的范围是 [1, 1000]。
每个节点的值都是 0。

思路：
摄像头数量少，应该使每个摄像头覆盖范围尽可能大，那么
放到叶子节点肯定是不行的，范围明显小了，那么放到哪？
每个摄像头可以覆盖上中下三层，如果把摄像头放在叶子节点上，就浪费的一层的覆盖。
所以把摄像头放在叶子节点的父节点位置，才能充分利用摄像头的覆盖面积。
如果确定了叶子节点上放摄像头的话，就可以从下往上的决定是否需要装摄像头了.
每个节点都有三种状态，我们分别用
0代表未被覆盖
1代表安装摄像头
2代表被覆盖
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
int result;
int traversal(TreeNode *node) { // 这个函数接受一个节点，返回该节点的状态
    if (node == nullptr)
        return 2;
    int left = traversal(node->left);
    int right = traversal(node->right);
    // 情况1
    // 左右节点都有覆盖
    if (left == 2 && right == 2)
        return 0;

    // 情况2
    // left == 0 && right == 0 左右节点无覆盖
    // left == 1 && right == 0 左节点有摄像头，右节点无覆盖
    // left == 0 && right == 1 左节点有无覆盖，右节点摄像头
    // left == 0 && right == 2 左节点无覆盖，右节点覆盖
    // left == 2 && right == 0 左节点覆盖，右节点无覆盖
    if (left == 0 || right == 0) {
        result++;
        return 1;
    }

    // 情况3
    // left == 1 && right == 2 左节点有摄像头，右节点有覆盖
    // left == 2 && right == 1 左节点有覆盖，右节点有摄像头
    // left == 1 && right == 1 左右节点都有摄像头
    // 其他情况前段代码均已覆盖
    if (left == 1 || right == 1)
        return 2;
    return -1; // 这个return -1 不会走到这里，这么写只是为了编译通过。
}

int minCameraCover(TreeNode *root) {
    result = 0;
    int rootVal = traversal(root);
    if (rootVal == 0)
        result++;
    return result;
}
int main() {}