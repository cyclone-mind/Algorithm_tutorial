/*
718. 最长重复子数组
中等
相关标签
premium lock icon
相关企业
提示
给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。

 

示例 1：

输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
输出：3
解释：长度最长的公共子数组是 [3,2,1] 。
示例 2：

输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
输出：5
 

提示：

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 100
*/

// 解法可以参考https://leetcode.cn/problems/maximum-length-of-repeated-subarray/solutions/310509/zhe-yao-jie-shi-ken-ding-jiu-dong-liao-by-hyj8/

#include <vector>
using namespace std;
int findLength(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    int result = 0;
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            if(nums1[i - 1] == nums2[j - 1]){ // 
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            if(dp[i][j] > result) result = dp[i][j];
        }
    }
    return result;
}

int main(){}