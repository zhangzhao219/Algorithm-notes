#include <bits/stdc++.h>
using namespace std;
int n;
bool cmp(string s1,string s2){
    return s1 > s2;
}
string s[25];
int main(void){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    sort(s,s+n,cmp);
    for(int i=0;i<n;i++){
        cout << s[i];
    }
    return 0;
}