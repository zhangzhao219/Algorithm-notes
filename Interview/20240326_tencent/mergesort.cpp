#include <bits/stdc++.h>
using namespace std;

void mergesort(vector<int>& nums, int start, int end){
    if(end - start <= 1){
        return;
    }
    int mid = (start + end) / 2;
    mergesort(nums, start, mid);
    mergesort(nums, mid, end);
    vector<int> temp;
    int left = start;
    int right = mid;
    while(left < mid && right < end){
        if (nums[left] < nums[right]){
            temp.push_back(nums[left]);
            left += 1;
        } else{
            temp.push_back(nums[right]);
            right += 1;
        }
    }
    while(left < mid){
        temp.push_back(nums[left]);
        left += 1;
    }
    while(right < end){
        temp.push_back(nums[right]);
        right += 1;
    }
    for(int i=start;i<end;i++){
        nums[i] = temp[i - start];
    }
    return;
}

int main(){
    vector<int> nums {1,2,3,2,1,2,3,4,5};
    mergesort(nums,0,nums.size());
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}