#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
{
    unordered_map<int, int> record;

    for (int a : nums1)
    {
        for (int b : nums2)
        {
            record[a + b]++;
        }
    }
    int count = 0;
    for (int c : nums3)
    {
        for (int d : nums4)
        {
            if (record.find(0 - (c + d)) != record.end())
            {
                count += record[0 - (c + d)];
            }
        }
    }
    return count;
}

int main()
{
    // 测试用例1：所有数组都为[1,2]
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {-2, -1};
    vector<int> nums3 = {-1, 2};
    vector<int> nums4 = {0, 2};
    // 期望输出2
    cout << "测试用例1结果: " << fourSumCount(nums1, nums2, nums3, nums4) << endl;

    // 测试用例2：所有数组都为[0]
    vector<int> nums5 = {0};
    vector<int> nums6 = {0};
    vector<int> nums7 = {0};
    vector<int> nums8 = {0};
    // 期望输出1
    cout << "测试用例2结果: " << fourSumCount(nums5, nums6, nums7, nums8) << endl;

    return 0;
}