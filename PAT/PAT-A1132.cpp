#include <bits/stdc++.h>
using namespace std;
int N;
int main(void){
    freopen("./test.in","r",stdin);
    scanf("%d",&N);
    string s;
    while(N--){
        cin >> s;
        int len = s.size();
        int a = stoi(s.substr(0,len/2));
        int b = stoi(s.substr(len/2,len/2));
        int c = stoi(s);
        if(a == 0 || b == 0 || c == 0){
            printf("No\n");
        }
        else if(c % (a*b) == 0){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}