#include <bits/stdc++.h>
using namespace std;
int N,M,Smax;
queue<char> q[110];
stack<char> st;
vector<char> vt;
int main(void){
    // freopen("./test.in","r",stdin);
    scanf("%d %d %d",&N,&M,&Smax);
    string s;
    for(int i=1;i<=N;i++){
        cin >> s;
        for(int j=0;j<s.size();j++){
            q[i].push(s[j]);
        }
    }
    int t;
    while(1){
        scanf("%d",&t);
        if(t == 0){
            if(!st.empty()){
                int t1 = st.top();
                st.pop();
                vt.push_back(t1);
            } 
        }
        else if(t == -1){
            break;
        }
        else{
            if(!q[t].empty()){
                int t1 = q[t].front();
                q[t].pop();
                if(st.size() == Smax){
                    int t2 = st.top();
                    st.pop();
                    vt.push_back(t2);
                    st.push(t1);
                }
                else{
                    st.push(t1);
                }
            }
        }
    }
    for(int i=0;i<vt.size();i++){
        printf("%c",vt[i]);
    }
    printf("\n");
    return 0;
}