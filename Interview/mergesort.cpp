#include <bits/stdc++.h>
using namespace std;

void mergesort(vector<int> & nums, int start, int end){
    if(start >= end){
        return;
    }
    int mid = (end - start) / 2 + start;
    mergesort(nums, start, mid);
    mergesort(nums, mid + 1, end);
    vector<int> temp;
    int l1_start = start;
    int l1_end = mid;
    int l2_start = mid + 1;
    int l2_end = end;
    while(l1_start <= l1_end || l2_start <= l2_end){
        if(l1_start > l1_end){
            temp.push_back(nums[l2_start]);
            l2_start += 1;
        } else if(l2_start > l2_end){
            temp.push_back(nums[l1_start]);
            l1_start += 1;
        } else{
            if(nums[l1_start] < nums[l2_start]){
                temp.push_back(nums[l1_start]);
                l1_start += 1;
            } else{
                temp.push_back(nums[l2_start]);
                l2_start += 1;
            }
        }
    }
    for(int i=start;i<=end;i++){
        nums[i] = temp[i - start];
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