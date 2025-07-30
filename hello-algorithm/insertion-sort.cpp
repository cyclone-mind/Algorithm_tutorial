
#include <vector>
using namespace std;
// 时间复杂度O(n^2)、原地排序、自适应排序、稳定排序
void insertSort(vector<int>& nums){
    for(int i = 1;i < nums.size();i++){
        int base = nums[i],j = i - 1;
        while(j >= 0 && nums[j] > base){
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = base;
    }
}