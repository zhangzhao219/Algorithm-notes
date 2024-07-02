#include <bits/stdc++.h>
using namespace std;

void permutation_own(vector<int>& nums, vector<vector<int> >& result, vector<bool>& visit, vector<int>& temp, int k){
    if(temp.size() == k){
        result.push_back(temp);
    }
    for(int i=0;i<nums.size();i++){
        if(visit[i] == true){
            continue;
        }
        visit[i] = true;
        temp.push_back(nums[i]);
        permutation_own(nums, result, visit, temp, k);
        temp.pop_back();
        visit[i] = false;
    }
}

void combination_own(vector<int>& nums, vector<vector<int> >& result, vector<int>& temp, int start, int k){
    if(temp.size() == k){
        result.push_back(temp);
        return;
    }
    for(int i=start;i<nums.size();i++){
        temp.push_back(nums[i]);
        combination_own(nums, result, temp, i+1, k);
        temp.pop_back();
    }
}

vector<vector<int> > all_permutation(vector<int>& nums, int k){
    vector<vector<int> > result;
    vector<int> temp;
    vector<bool> visit(nums.size(), false);
    permutation_own(nums,result,visit,temp,k);
    return result;
}

vector<vector<int> > all_combination(vector<int>& nums, int k){
    vector<vector<int> > result;
    vector<int> temp;
    combination_own(nums,result,temp,0,k);
    return result;
}

int main(){
    vector<int> nums = {1,2,3,4,5,6};
    vector<vector<int> > result = all_permutation(nums, 6);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    result = all_combination(nums, 4);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}