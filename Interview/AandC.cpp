#include <bits/stdc++.h>
using namespace std;


void combination_own(vector<int> & nums, vector<vector<int> >& result, vector<int> & temp, int k, int start){
    if(temp.size() == k){
        result.push_back(temp);
        return;
    }
    for(int i=start;i<nums.size();i++){
        temp.push_back(nums[i]);
        combination_own(nums, result, temp, k, i+1);
        temp.pop_back();
    }
}

void permutation_own(vector<int> & nums, vector<vector<int> >& result, vector<bool> & visited, vector<int> & temp, int k){
    if(temp.size() == k){
        result.push_back(temp);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(visited[i] == true){
            continue;
        }
        visited[i] = true;
        temp.push_back(nums[i]);
        permutation_own(nums, result, visited, temp, k);
        temp.pop_back();
        visited[i] = false;
    }
}

vector<vector<int> > combination(vector<int> &nums, int k){
    vector<vector<int> > result;
    vector<int> temp;
    combination_own(nums, result, temp, k, 0);
    return result;
}

vector<vector<int> > permutation(vector<int> &nums, int k){
    vector<vector<int> > result;
    vector<int> temp;
    vector<bool> visited(nums.size(), false);
    permutation_own(nums, result, visited, temp, k);
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    vector<vector<int>> result;
    result = combination(nums, 3);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    result = permutation(nums, 3);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}