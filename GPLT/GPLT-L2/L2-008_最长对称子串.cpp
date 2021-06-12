#include <bits/stdc++.h>
using namespace std;
string s;
int a[10010];
int main(void){
    getline(cin,s);
    for(int i=0;i<s.size();i+=2){
        s.insert(i,"#");
    }
    s.insert(s.size(),"#");
    for(int i=0;i<s.size();i++){
        int j = i;
        int num = 1;
        while(j-num >= 0 && j+num <s.size() && s[j-num] == s[j+num]){
            num++;
        }
        a[i] = num - 1;
    }
    int ans = -1;
    for(int i=0;i<s.size();i++){
        ans = max(ans,a[i]);
    }
    printf("%d\n",ans);
    return 0;
}