#include <bits/stdc++.h>

using namespace std;

void mergesort(vector<int> & nums, int left, int right){
    if(left >= right){
        return;
    }
    int mid = (right - left) / 2 + left;
    mergesort(nums, left, mid);
    mergesort(nums, mid + 1, right);
    vector<int> temp;
    int l1start = left;
    int l1end = mid;
    int l2start = mid + 1;
    int l2end = right;
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
        nums[left+i] = temp[i];
    }
}

int main(){
    vector<int> nums = {1,4,5,7,8,4,5,2,1,3,6,5,2,4,5,2,3};
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