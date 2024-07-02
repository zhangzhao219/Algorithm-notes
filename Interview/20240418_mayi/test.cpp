//已知一组数（其中无重复元素），求这组数可以组成的所有子集。结果中不可有重复的子集。
//例如输入： [4,5,6]，要求输出所有满足要求的子集

#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > result;

void backtracking(vector<int>& nums, vector<bool>& used, vector<int>& temp, int start){
    result.push_back(temp);
    if(start == nums.size()){
        return;
    }
    for(int i=start;i<nums.size();i++){
        if(used[i] == true){
            continue;
        }
        used[i] = true;
        temp.push_back(nums[i]);
        backtracking(nums, used, temp, i);
        temp.pop_back();
        used[i] = false;
    }
}

int main(){
    vector<int> nums = {4,5,6};
    vector<int> temp;
    vector<bool> used(nums.size(), false);
    backtracking(nums,used, temp,0);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}