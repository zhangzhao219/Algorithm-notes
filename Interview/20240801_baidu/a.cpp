// 6个人，身高 1 2 3 4 5 6 ，排成2*3的矩阵，每一列后面的人比前面的高，总共有多少种方案
// 1 3 5
// 2 4 6
#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > result;

bool judge(vector<int>& temp, int num, int now){
    if(now == 0 || now == 2 || now == 4){
        return true;
    }
    if(num <= temp[now-1]){
        return false;
    }
    return true;
}
void backtracking(vector<int> &nums, vector<int>& temp, vector<bool>& visited, int now){
    if(now == nums.size()){
        result.push_back(temp);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(visited[i] == true){
            continue;
        }
        if(judge(temp, nums[i], now) == false){
            continue;
        }
        visited[i] = true;
        temp.push_back(nums[i]);
        backtracking(nums, temp, visited, now+1);
        temp.pop_back();
        visited[i] = false;
    }
}

int main(){
    vector<int> nums = {1,2,3,4,5,6};
    vector<int> temp;
    vector<bool> visited(nums.size(), false);
    backtracking(nums, temp, visited, 0);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << result.size() << endl;
    return 0;
}