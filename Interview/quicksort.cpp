#include <bits/stdc++.h>
using namespace std;

void quicksort(vector<int>& nums, int start, int end){
    if(start >= end ){
        return;
    }
    int left = start;
    int right = end;
    int x = nums[left];
    while(left < right){
        while(left < right && nums[right] > x){
            right--;
        }
        nums[left] = nums[right];
        while(left < right && nums[left] <= x){
            left++;
        }
        nums[right] = nums[left];
    }
    nums[left] = x;
    quicksort(nums,start,left-1);
    quicksort(nums, left+1,end);
}

int main(){
    vector<int> a = {1,2,5,4,8,7,5,6,5,4,1,2,5,4,7,8,5,2,5,6};
    quicksort(a,0,a.size()-1);
    for(int i=0;i<a.size();i++){
        cout << a[i] << " ";
    }
    cout << endl;
    sort(a.begin(), a.end());
    for(int i=0;i<a.size();i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}