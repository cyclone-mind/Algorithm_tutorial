#include <cstddef>  // For size_t, which is the type returned by sizeof
#include <iostream> // For std::cout if you want to print
#include <vector>

int removeElement(std::vector<int> &nums, int val)
{
    int slow = 0;
    for (int fast = 0; fast < nums.size(); fast++)
    {
        if (nums[fast] != val)
        {
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}
int removeElement2(std::vector<int> &nums, int val)
{
    int n = nums.size();
    int left = 0;
    for (int right = 0; right < n; right++)
    {
        if (nums[right] != val)
        {
            nums[left] = nums[right];
            left++;
        }
    }
    return left;
}
int removeElement3(std::vector<int> &nums, int val)
{
    // 当左指针 left 指向的元素是我们想要移除的 val 时，我们尝试用右指针 right 指向的元素去覆盖它。
    // 这样做的目的是尽量把“有效”的元素往前挪，把“无效”的元素（或者暂时不关心的元素）往后挪。
    int left = 0, right = nums.size();
    while (left < right)
    {
        if (nums[left] == val)
        {
            nums[left] = nums[right - 1];
            right--;
        }
        else
        {
            left++;
        }
    }
    return left;
}

int main()
{
    int nums[8]{0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;

    size_t array_size = sizeof(nums) / sizeof(nums[0]);

    int i = 0;

    int current_size = array_size; // Corrected line and added semicolon

    while (i < current_size)
    {
        /* code */
        if (nums[i] == val)
        {
            /* code */
            for (int j = i + 1; j < current_size; j++)
            {
                nums[j - 1] = nums[j];
            }
            current_size--;
        }
        else
        {
            i++;
        }
    }
    std::cout << current_size << std::endl;
    std::vector<int> nums1 = {0, 1, 2, 2, 3, 0, 4, 2};
    std::vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    std::vector<int> nums3 = {0, 1, 2, 2, 3, 0, 4, 2};
    std::cout << removeElement(nums1, 2) << std::endl;
    std::cout << removeElement2(nums2, 2) << std::endl;
    std::cout << removeElement2(nums3, 2) << std::endl;
}
