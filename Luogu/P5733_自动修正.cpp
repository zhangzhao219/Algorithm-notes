#include <bits/stdc++.h>
using namespace std;
int main(void){
    freopen("../test.in","r",stdin);
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(s[i] <= 'z' && s[i] >= 'a'){
            s[i] = s[i] - 'a' + 'A';
        }
    }
    cout << s;
    return 0;
}