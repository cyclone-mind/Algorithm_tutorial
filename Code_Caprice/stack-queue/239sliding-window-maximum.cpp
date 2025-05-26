/*
给你一个整数数组 nums，有一个大小为 k
的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
个数字。滑动窗口每次只向右移动一位。

返回 滑动窗口中的最大值 。
*/
#include <deque>
#include <utility> // for std::pair
#include <vector>

/**
 * @brief 使用优先队列解决滑动窗口最大值问题
 *
 * 遍历数组，维护一个大小为 k 的滑动窗口。
 * 使用一个最大堆（优先队列）来存储窗口内的元素及其在原数组中的下标。
 * 每次窗口滑动时：
 * 1. 移除堆顶不在当前窗口范围内的元素。
 * 2. 将新进入窗口的元素加入堆。
 * 3. 堆顶元素即为当前窗口的最大值。
 *
 * 时间复杂度: O(N log k)，其中 N 是数组长度，k
 * 是窗口大小。每个元素入队出队一次。 空间复杂度: O(k)，优先队列中最多存储 k
 * 个元素。
 */

class Solution {
public:
  class myQue {
  public:
    std::deque<int> que;
    myQue() {};
    void pop(int val) {
      if (!que.empty() && val == que.front()) {
        que.pop_front();
      }
    }
    void push(int val) {
      while (!que.empty() && que.back() < val) {
        que.pop_back();
      }
      que.push_back(val);
    }
    int front() { return que.front(); }
  };
  std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
    myQue myque;
    std::vector<int> result;
    for (int i = 0; i < k; i++) {
      myque.push(nums[i]);
    }
    result.push_back(myque.front()); // result 记录前k的元素的最大值
    for (int i = k; i < nums.size(); i++) {
      myque.pop(nums[i - k]);
      myque.push(nums[i]);
      result.push_back(myque.front());
    }
    return result;
  }
};

// 主函数（可选，用于本地测试）
#include <iostream>
void printVector(const std::vector<int> &vec) {
  for (int x : vec) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
}

int main() {
  Solution sol;
  std::vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
  int k1 = 3;
  std::vector<int> result1 = sol.maxSlidingWindow(nums1, k1);
  printVector(result1); // 预期输出: 3 3 5 5 6 7

  std::vector<int> nums2 = {1};
  int k2 = 1;
  std::vector<int> result2 = sol.maxSlidingWindow(nums2, k2);
  printVector(result2); // 预期输出: 1

  std::vector<int> nums3 = {1, -1};
  int k3 = 1;
  std::vector<int> result3 = sol.maxSlidingWindow(nums3, k3);
  printVector(result3); // 预期输出: 1 -1

  std::vector<int> nums4 = {9, 11};
  int k4 = 2;
  std::vector<int> result4 = sol.maxSlidingWindow(nums4, k4);
  printVector(result4); // 预期输出: 11

  std::vector<int> nums5 = {4, -2};
  int k5 = 2;
  std::vector<int> result5 = sol.maxSlidingWindow(nums5, k5);
  printVector(result5); // 预期输出: 4

  std::vector<int> nums6 = {1, 3, 1, 2, 0, 5};
  int k6 = 3;
  std::vector<int> result6 = sol.maxSlidingWindow(nums6, k6);
  printVector(result6); // 预期输出: 3 3 2 5

  return 0;
}
