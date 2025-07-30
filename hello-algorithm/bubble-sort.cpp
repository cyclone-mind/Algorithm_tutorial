#include <utility>
#include <vector>
using namespace std;
// 时间复杂度O(n^2)、自适应排序、原地排序、稳定排序
void bubbleSort(vector<int>& nums){
    for(int i = nums.size()-1;i > 0;i--){
        bool flag = false;
        for(int j = 0;j < i;j++){
            if(nums[j] > nums[j + 1]){
                swap(nums[j],nums[j + 1]);
                flag = true;
            }
        }
        if(flag == false) break;
    }
}
