#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > result;
int main() {
    int s;
    cin >> s;
    for(int i=0;i<=501;i++){
        vector<int> temp;
        for(int j=0;j<=501;j++){
            temp.push_back(0);
        }
        result.push_back(temp);
    }
    for(int kk=0;kk<s;kk++){
        int n, m;
        cin >> n >> m;
        for(auto& row: result){
            fill(row.begin(), row.end(), 0);
        }
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            for(int j=0;j<m;j++){
                result[i][j] = s[j] - '0';
            }
        }
        if(n % 2 != 0 || m % 2 != 0){
            cout << "NO" << endl;
            continue;
        }
        bool sign = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(result[i][j] == 1){
                    if(i+1 < n && j+1 < m){
                        if(result[i][j+1] == 1 && result[i+1][j] == 1 && result[i+1][j+1] == 1){
                            sign = true;
                            break;
                        }
                    }
                }
            }
            if(sign == true){
                break;
            }
        }
        if(sign == true){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
// 64 位输出请用 printf("%lld")


// 3
// 6 6
// 111111
// 111111
// 111111
// 111111
// 111111
// 111111
// 4 6
// 000000
// 000110
// 000110
// 000000
// 3 6
// 000000
// 000110
// 000110