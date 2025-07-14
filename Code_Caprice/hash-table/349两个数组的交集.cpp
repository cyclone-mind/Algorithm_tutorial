#include <vector>
#include <unordered_set>

using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
    unordered_set<int> nums_set(nums1.begin(), nums1.end());
    for (int num : nums2)
    {
        // 发现nums2的元素 在nums_set里又出现过
        if (nums_set.find(num) != nums_set.end()) 
        // 返回值是一个迭代器（iterator）
        // 如果找到元素，返回指向该元素的迭代器
        // 如果没找到，返回 nums_set.end()
        {
            result_set.insert(num);
        }
    }
    return vector<int>(result_set.begin(), result_set.end());
}

int main(){}