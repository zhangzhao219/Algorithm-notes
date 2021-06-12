#include <bits/stdc++.h>
using namespace std;
int N,M,K;
int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d %d %d",&N,&M,&K);
    int temp;
    while(K--){
        stack<int> st;
        bool flag = true;
        int cnt = 1;
        for(int i=1;i<=N;i++){
            scanf("%d",&temp);
            if(temp != cnt){
                st.push(temp);
                if(st.size() > M){
                    flag = false;
                }
            }
            else{
                cnt++;
                while(!st.empty() && st.top() == cnt){
                    cnt++;
                    st.pop();
                }
            }
        }
        if(flag && cnt == N+1){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }

    return 0;
}