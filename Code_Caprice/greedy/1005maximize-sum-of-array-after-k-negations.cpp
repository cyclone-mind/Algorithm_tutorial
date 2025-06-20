/*
1005. K 次取反后最大化的数组和
简单
相关标签
premium lock icon
相关企业
给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：

选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
重复这个过程恰好 k 次。可以多次选择同一个下标 i 。

以这种方式修改数组后，返回数组 可能的最大和 。



示例 1：

输入：nums = [4,2,3], k = 1
输出：5
解释：选择下标 1 ，nums 变为 [4,-2,3] 。
示例 2：

输入：nums = [3,-1,0,2], k = 3
输出：6
解释：选择下标 (1, 2, 2) ，nums 变为 [3,1,0,2] 。
示例 3：

输入：nums = [2,-3,-1,5,-4], k = 2
输出：13
解释：选择下标 (1, 4) ，nums 变为 [2,3,-1,5,4] 。
 

提示：

1 <= nums.length <= 104
-100 <= nums[i] <= 100
1 <= k <= 104
*/
#include <algorithm>
#include <vector>

/*
这道题贪心的思想是
把最大的负数扭转过来
把最小的正数扭转过来 
*/
int largestSumAfterKNegations(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    int i = 0;
    // 先处理所有负数 
    while (i < nums.size() && nums[i] < 0 && k > 0) {
        nums[i] = -nums[i];
        i++;
        k--;
    }
    // 如果k还有剩余，在绝对值最小的元素上操作
    if (k > 0) {
        // 重新排序找到绝对值最小的元素
        std::sort(nums.begin(), nums.end());
        if (k % 2 == 1) {
            nums[0] = -nums[0];  // 只有奇数次时才需要变号
        }
    }

    int result = 0;
    for(int num:nums){
        result +=num;
    }
    return result;
}
int main(){}