#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > result;
unordered_map<int, bool> mp;

void backtracking(vector<int>& temp, int n){
    if(n == 1){
        result.push_back(temp);
        return;
    }
    for(int i=2;i<=n;i++){
        if(n % i == 0 && mp.find(i) == mp.end()){
            temp.push_back(i);
            backtracking(temp, n/i);
            temp.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    vector<int> temp;
    for(int i=2;i<n;i++){
        if(i*i <= n){
            mp[i*i] = true;
        } else{
            break;
        }
    }
    backtracking(temp,n);
    // for(int i=0;i<result.size();i++){
    //     for(int j=0;j<result[i].size();j++){
    //         cout << result[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << result.size() << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")