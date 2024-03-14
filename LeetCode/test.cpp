#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int> > result;
    sort(nums.begin(), nums.end());
    cout << nums.size() << endl;
    for(int i=0;i<=nums.size();i++){
        cout << i << endl;
        if(i > 0 && nums[i] == nums[i-1]){
            continue;
        }
        for(int l=i;l<nums.size();l++){
            if(l < nums.size()-1 && nums[l] == nums[l+1]){
                continue;
            }
            int j = i + 1;
            int k = l - 1;

            while(j < k){
                if(nums[i] + nums[j] + nums[k] + nums[l] == target){
                    result.push_back(vector<int>{nums[i], nums[j], nums[k], nums[l]});
                    while(j < k && nums[j] == nums[j+1]){
                        j++;
                    }
                    while(j < k && nums[k] == nums[k-1]){
                        k--;
                    }
                    j++;
                    k--;
                } else if(nums[i] + nums[j] + nums[k] + nums[l] > target){
                    k--;
                } else{
                    j++;
                }
            }
        }
    }
    return result;
}

int main(){
    vector<int> a = {0};
    fourSum(a,0);
    // cout <<  << endl;
}