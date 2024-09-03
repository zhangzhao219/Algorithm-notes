#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int n, m;
        cin >> n >> m;
        vector<vector<char> > packages;
        for(int i=0;i<n;i++){
            string s;
            vector<char> temp;
            cin >> s;
            for(int j=0;j<s.size();j++){
                temp.push_back(s[j]);
            }
            packages.push_back(temp);
        }
        bool flag = true;
        int p = packages.size();
        int q = packages[0].size();
        for(int i=0;i<p;i++){
            for(int j=0;j<q;j++){
                if(packages[i][j] == '*'){
                    if(i-1 < 0 || j-1 < 0 || i+1 >= p || j+1 >= q){
                        flag = false;
                        break;
                    }
                    
                }
            }
            if(flag == false){
                break;
            }
        }
        if(flag == true){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
// 64 位输出请用 printf("%lld")


// 3
// 4 4
// oooo
// o*oo
// oo*o
// oooo
// 3 3
// ooo
// ooo
// ooo
// 2 3
// o*o
// ooo

// YES
// YES
// NO