#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    std::unordered_map<int, int> record;
    for (int i = 0; i < nums.size(); i++)
    {
        int s = target - nums[i];
        if (record.find(s) != record.end()){
            return {i, record[s]};
        }
        record[nums[i]] = i;
    }
    return {};
}
int main()
{
    vector<int> nums = {2, 3, 7, 6};
    vector<int> result = twoSum(nums, 9);
    for (int i : result)
    {
        std::cout << i << " " << std::endl;
    }
}