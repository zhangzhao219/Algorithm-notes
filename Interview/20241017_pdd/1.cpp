

// def prob(m, n, k):
//     pass



// print(prob(m, n, k))


#include<iostream>
#include<vector>
#include <cmath>
using namespace std;

int m = 2;
int n = 6;
int k = 3;

// 2 3 4 5 6 7
// 3 4 5 6 7 8
// 4 5 6 7 8 9
// 5 6 7 8 9 10


int result = 0;

void judge(vector<int> & nums){
    int temp = 0;
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
        temp += nums[i];
    }
    cout << endl;
    if(temp >= k){
        result += 1;
    }
}

void backtracking(vector<int> & nums){
    // int temp = 0;
    // for(int i=0;i<nums.size();i++){
    //     temp += nums[i];
    // }
    // if(temp >= k){
    //     // for(int i=0;i<m;i++){
    //     //     cout << nums[i] << " ";
    //     // }
    //     // cout << endl;
    //     result += 1;
    //     return;
    // }
    // // cout << temp << endl;
    for(int i=0;i<m;i++){
        for(int j=1;j<=n;j++){
            int t = nums[i];
            nums[i] = j;
            backtracking(nums);
            nums[i] = t;
        }
    }
}

int main(){
    vector<int> nums;
    for(int i=0;i<m;i++){
        nums.push_back(1);
    }
    backtracking(nums, 0);
    cout << result << endl;
    cout << pow(n,m) << endl;
    cout << result / pow(n,m) << endl;
    return 0;
}

// 1 2 3 4 5 6

// 1 1 1
// 2 1 1
// 3 1 1
// 4 1 1

// 0 0 0
