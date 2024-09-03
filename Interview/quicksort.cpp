#include <bits/stdc++.h>
using namespace std;


void quicksort(vector<int> & nums, int start, int end){
    if(start >= end){
        return;
    }
    int left = start;
    int right = end;
    int x = nums[start];
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
    quicksort(nums, start, left-1);
    quicksort(nums, left+1, end);
}


int main(){
    vector<int> nums = {1,2,5,4,7,8,9,6,5,2,3,4,5,2,1,2,3,5};
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    quicksort(nums, 0, nums.size()-1);
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}