#include <bits/stdc++.h>
using namespace std;

int findTargetSumWays(vector<int>& nums, int target) {
    int numsum = 0;
    for(int i=0;i<nums.size();i++){
        numsum += nums[i];
    }
    if(abs(target) > numsum){
        return 0;
    }
    if((target + numsum) % 2 == 1){
        return 0;
    }
    int bagSize = (target + numsum) / 2;
    vector<vector<int> > dp(nums.size(), vector<int>(bagSize+1,0));
    for(int i=0;i<=bagSize+1;i++){
        dp[0][i] = 1;
    }
    dp[0][0] = 1;
    for(int i=1;i<nums.size();i++){
        for(int j=0;j<=bagSize+1;j++){
            if(j == 0){
                dp[i][j] = 1;
            }
            else{
                if(j >= nums[i]){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]];
                } else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<=bagSize+1;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[nums.size()-1][bagSize+1];
}

int main(){
    vector<int> a = {0,0,0,0,0,0,0,0,1};
    cout << findTargetSumWays(a,1) << endl;
}