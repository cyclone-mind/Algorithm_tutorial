#include <utility>
#include <vector>
#include <iostream>
using namespace std;
// 空间复杂度O(n)、时间复杂度O(nlogn)、非自适应、原地、非稳定
int partition(vector<int>& nums,int left,int right){
    int i = left,j = right;
    while(i < j){
        while(i < j && nums[j] >= nums[left]){
            j--;
        }
        while(i < j && nums[i] <= nums[left]){
            i++;
        }
        swap(nums[i],nums[j]);
    }
    swap(nums[i],nums[left]);
    return i;
}

void quickSort(vector<int>& nums,int left,int right){
    if(left >= right) return;
    int pivot = partition(nums,left,right);
    quickSort(nums, left, pivot - 1);
    quickSort(nums, pivot + 1,right);
}

int main(){
    vector<int> vec = {2,4,1,0,3,5};
    quickSort(vec, 0, vec.size()-1);
    for(auto v : vec){
        std::cout << v << " ";
    }
    std::cout << "\n";
}