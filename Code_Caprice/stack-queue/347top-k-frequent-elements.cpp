#include <algorithm> // for std::sort (though not strictly needed for heap approach now)
#include <map>
#include <queue> // for std::priority_queue
#include <vector>


/*
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按
任意顺序 返回答案。
*/

std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
    // 1. 统计每个数字的频率
    std::map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }

    // 2. 构建一个大小为 k 的小顶堆
    // 堆中存储的是 pair<频率, 数字>，priority_queue 默认是大顶堆，
    // 要实现小顶堆，需要传入 third 参数 std::greater<std::pair<int, int>>
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        minHeap;

    for (auto const &[num, freq] : freqMap) {
        minHeap.push({freq, num}); // 将 (频率, 数字) 对推入堆中
        if (minHeap.size() > k) {
            minHeap.pop(); // 如果堆的大小超过 k，则弹出堆顶元素（频率最小的）
        }
    }

    // 3. 从小顶堆中提取结果
    std::vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second); // 获取数字
        minHeap.pop();
    }
    // 注意：由于小顶堆弹出的是从小到大，这里可能需要反转一下结果，
    // 但题目要求“任意顺序”，所以不反转也行。为了符合高频在前，可以反转。
    std::reverse(result.begin(), result.end());

    return result;
}