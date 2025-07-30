#include <vector>
using namespace std;
// 时间复杂度O(n^2)原地排序、非稳定排序、非自适应性
void selectionSort(vector<int>& nums){
    for(int i = 0;i < nums.size()-1;i++){
        int k = i;
        for(int j = i + 1;j<nums.size();j++){
            if(nums[j] < nums[k]) k = j;
        }
        swap(nums[i],nums[i]);
    }
}
int main(){}