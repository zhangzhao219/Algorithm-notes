#include <bits/stdc++.h>
using namespace std;
int a1,a2,n;
queue<int> q;
vector<int> vt;
int main(void){
    freopen("./test.in","r",stdin);
    scanf("%d %d %d",&a1,&a2,&n);
    q.push(a1);
    q.push(a2);
    vt.push_back(a1);
    while(vt.size() <= n){
        int a = q.front();
        q.pop();
        int b = q.front();
        vt.push_back(b);
        int t = a * b;
        string st = to_string(t);
        for(int i=0;i<st.size();i++){
            q.push(st[i] - '0');
        }
    }
    for(int i=0;i<n;i++){
        printf("%d",vt[i]);
        if(i == n-1){
            printf("\n");
        }
        else{
            printf(" ");
        }
    }
    return 0;
}