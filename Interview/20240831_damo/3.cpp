#include <bits/stdc++.h>
using namespace std;

vector<vector<char > > matrix;
vector<string> result;

void backtracking(int i, int j, int n, int m, string t){
    if(i == n-1 && j == m-1){
        t += matrix[n-1][m-1];
        result.push_back(t);
        return;
    }
    if(i+1 < n){
        backtracking(i+1,j,n,m,t+matrix[i][j]);
    }
    if(j+1 < m){
        backtracking(i,j+1,n,m,t+matrix[i][j]);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    string t;
    for(int i=0;i<n;i++){
        cin >> t;
        vector<char> temp;
        for(int j=0;j<m;j++){
            temp.push_back(t[j]);
        }
        matrix.push_back(temp);
    }
    string s2;
    backtracking(0,0,n,m,s2);
    // for(int i=0;i<result.size();i++){
    //     cout << result[i] << endl;
    // }
    int maxsum = 1;
    string s;
    for(int x=0;x<result.size();x++){
        s = result[x];
        int len = s.size() + 1;
        int dp[len * 2 + 10];
        int N = 0;
        string extends;
        extends.push_back('^');
        for(int i=0;i<len;i++){
            extends.push_back('#');
            extends.push_back(s[i]);
            N += 2;
        }
        extends.push_back('#');
        extends.push_back('$');
        N += 2;
        int right = 0;
        int pos = 0;
        for(int i=1;i<=N;i++){
            if(i < right){
                dp[i] = min(dp[2*pos-i], right-i);
            } else{
                dp[right=i]=1;
            }
            while(extends[i-dp[i]] == extends[i+dp[i]]){
                dp[i]++;
            }
            if(i + dp[i] > right){
                right = i + dp[i];
                pos = i;
            }
        }
        maxsum = max(maxsum, *max_element(dp+1, dp+N+1)-1);
    }
    cout << maxsum << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")

// 4 4
// abcd
// bdgf
// czke
// dcbb

// 5