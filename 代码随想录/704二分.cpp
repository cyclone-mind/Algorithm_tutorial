#include <vector> // 需要包含 vector 头文件
#include <iostream> // 用于 std::cout

class Solution {
public:
    // 二分查找函数
    // nums: 有序的整数向量
    // target: 需要查找的目标整数
    // 返回值: 如果找到 target，返回其在 nums 中的索引；否则返回 -1
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; // 定义target在[left, right]的闭区间

        while (left <= right) { // 当left == right时，区间[left, right]依然有效，所以用 <=
            // int middle = (left + right) / 2; // 这种写法在left和right都很大时可能导致溢出
            int middle = left + (right - left) / 2; // 防止溢出更安全的写法

            if (nums[middle] == target) {
                return middle; // 找到了目标值
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，所以搜索范围是 [middle + 1, right]
            } else { // nums[middle] > target
                right = middle - 1; // target 在左区间，所以搜索范围是 [left, middle - 1]
            }
        }
        
        return -1; // 未找到目标值
    }
};

// ---- main 函数用于测试 ----
int main() {
    Solution sol;
    std::vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;
    int result1 = sol.search(nums1, target1);
    if (result1 != -1) {
        std::cout << "Target " << target1 << " found at index: " << result1 << std::endl; // 找到: 4
    } else {
        std::cout << "Target " << target1 << " not found." << std::endl;
    }

    std::vector<int> nums2 = {-1, 0, 3, 5, 9, 12};
    int target2 = 2;
    int result2 = sol.search(nums2, target2);
    if (result2 != -1) {
        std::cout << "Target " << target2 << " found at index: " << result2 << std::endl;
    } else {
        std::cout << "Target " << target2 << " not found." << std::endl; // 未找到
    }

    std::vector<int> nums3 = {5};
    int target3 = 5;
    int result3 = sol.search(nums3, target3);
    if (result3 != -1) {
        std::cout << "Target " << target3 << " found at index: " << result3 << std::endl; // 找到: 0
    } else {
        std::cout << "Target " << target3 << " not found." << std::endl;
    }

    std::vector<int> nums4 = {5};
    int target4 = -5;
    int result4 = sol.search(nums4, target4);
    if (result4 != -1) {
        std::cout << "Target " << target4 << " found at index: " << result4 << std::endl;
    } else {
        std::cout << "Target " << target4 << " not found." << std::endl; // 未找到
    }

    return 0;
}