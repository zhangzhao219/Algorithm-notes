#include <bits/stdc++.h>
using namespace std;
string str[10010];
bool cmp(string a,string b){
    return a+b < b+a;
}
int main(void){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        cin >> str[i];
    }
    sort(str,str + N,cmp);
    string s;
    for(int i=0;i<N;i++){
        s += str[i];
    }
    while(s.size() != 0 && s[0] == '0'){
        s.erase(s.begin());
    }
    if(s.size() == 0){
        cout << '0';
    }
    cout << s;
    return 0;
}