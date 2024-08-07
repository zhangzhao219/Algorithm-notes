#include <bits/stdc++.h>
using namespace std;

void mergesort(vector<int> & nums, int start, int end){
    if(start >= end){
        return;
    }
    int mid = (end - start) / 2 + start;
    mergesort(nums, start, mid);
    mergesort(nums, mid+1, end);
    vector<int> temp;
    int l1start = start;
    int l1end = mid;
    int l2start = mid + 1;
    int l2end = end;
    while(l1start <= l1end || l2start <= l2end){
        if(l1start > l1end){
            temp.push_back(nums[l2start]);
            l2start += 1;
        } else if(l2start > l2end){
            temp.push_back(nums[l1start]);
            l1start += 1;
        } else{
            if(nums[l1start] < nums[l2start]){
                temp.push_back(nums[l1start]);
                l1start += 1;
            } else{
                temp.push_back(nums[l2start]);
                l2start += 1;
            }
        }
    }
    for(int i=0;i<temp.size();i++){
        nums[start+i] = temp[i];
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