#include <bits/stdc++.h>
using namespace std;

void mergesort(vector<int>& nums, int start, int end){
    if(start >= end){
        return;
    }
    int mid = (end - start) / 2 + start;
    mergesort(nums, start, mid);
    mergesort(nums, mid + 1, end);
    vector<int> temp;
    int l1 = start;
    int l2 = mid + 1;
    while(l1 <= mid || l2 <= end){
        if(l2 > end){
            temp.push_back(nums[l1]);
            l1++;
        } else if (l1 > mid){
            temp.push_back(nums[l2]);
            l2++;
        } else{
            if(nums[l1] < nums[l2]){
                temp.push_back(nums[l1]);
                l1++;
            } else{
                temp.push_back(nums[l2]);
                l2++;
            }
        }
    }
    for(int i=start;i<=end;i++){
        nums[i] = temp[i-start];
    }
}

int main(){
    vector<int> nums = {1,5,4,8,5,6,9,5,2,3,6,5,2,6,3,2,5,8,9,6,3,2,1,4,5,7,4,5,2,1,2,3,5,6,4,1,2,5,4,8,9,6,2};
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    mergesort(nums, 0, nums.size()-1);
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}