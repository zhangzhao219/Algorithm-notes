#include <bits/stdc++.h>
using namespace std;

void mergesort(vector<int>& nums, int start, int end){
    if(end - start <= 1){
        return;
    }
    int mid = (start + end) / 2;
    mergesort(nums, start, mid);
    mergesort(nums, mid, end);
    int leftA = start;
    int leftB = mid;
    vector<int> temp;
    while(leftA < mid && leftB < end){
        if(nums[leftA] < nums[leftB]){
            temp.push_back(nums[leftA]);
            leftA++;
        } else{
            temp.push_back(nums[leftB]);
            leftB++; 
        }
    }
    while(leftA < mid){
        temp.push_back(nums[leftA]);
        leftA++;
    }
    while(leftB < end){
        temp.push_back(nums[leftB]);
        leftB++;
    }
    for(int i=start;i<end;i++){
        nums[i] = temp[i-start];
    }
    return;
}

int main(){
    vector<int> nums = {1,5,4,8,5,6,9,5,2,3,6,5,2,6,3,2,5,8,9,6,3,2,1};
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    mergesort(nums, 0, nums.size());
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}