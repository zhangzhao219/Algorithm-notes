#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for(int k=1;k<=n;k++){
        set<string> st;
        long long actualcount = 0;
        for(int i=0;i<=n-k;i++){
            st.insert(s.substr(i,k));
            actualcount += 1;
        }
        
        if(st.size() != actualcount){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")

// meimei

// YES

// ade

// NO