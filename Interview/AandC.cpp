#include <bits/stdc++.h>
using namespace std;

void dfs_permutation(vector<vector<int> >& result, vector<int>& temp, vector<bool>& used, vector<int>& nums, int start, int k){
    if(temp.size() == k){
        result.push_back(temp);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(used[i] == true){
            continue;
        }
        used[i] = true;
        temp.push_back(nums[i]);
        dfs_permutation(result, temp, used, nums, i+1, k);
        temp.pop_back();
        used[i] = false;
    }
}

vector<vector<int> > all_permutation(vector<int> nums, int k){
    vector<vector<int> > result;
    vector<int> temp;
    vector<bool> used(nums.size(), false);
    dfs_permutation(result, temp, used, nums, 0, k);
    return result;
}

void dfs_combination(vector<vector<int> >& result, vector<int>& temp, vector<int>& nums, int start, int k){
    if(temp.size() == k){
        result.push_back(temp);
        return;
    }
    for(int i=start;i<nums.size();i++){
        temp.push_back(nums[i]);
        dfs_combination(result, temp, nums, i+1, k);
        temp.pop_back();
    }
}

vector<vector<int> > all_combination(vector<int> nums, int k){
    vector<vector<int> > result;
    vector<int> temp;
    dfs_combination(result, temp, nums, 0, k);
    return result;
}

int main(){
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
    vector<vector<int> > result = all_permutation(nums, 5);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    result = all_combination(nums, 5);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}