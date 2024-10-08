#include <bits/stdc++.h>

using namespace std;

void quicksort(vector<int> & nums, int left, int right){
    if(left >= right){
        return;
    }
    int start = left;
    int end = right;
    int x = nums[left];
    while(left < right){
        while(left < right && nums[right] >= x){
            right--;
        }
        nums[left] = nums[right];
        while(left < right && nums[left] < x){
            left++;
        }
        nums[right] = nums[left];
    }
    nums[left] = x;
    quicksort(nums, start, left - 1);
    quicksort(nums, left + 1, end);
}

int main(){
    vector<int> nums = {1,2,4,5,7,8,4,5,6,5,2,3,2,4,5,1,1,2};
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    quicksort(nums, 0, nums.size()-1);
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}