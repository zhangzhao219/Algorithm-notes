#include <bits/stdc++.h>
using namespace std;
int N,M,K;

int main(void){
    scanf("%d %d %d",&N,&M,&K);
    while(K--){
        stack<int> st;
        int temp;
        int num = 1;
        bool flag = true;
        for(int i=1;i<=N;i++){
            scanf("%d",&temp);
            if(temp != num){
                st.push(temp);
                if(st.size() > M){
                    flag = false;
                }
            }
            else{
                num++;
                while(!st.empty() && st.top() == num){
                    st.pop();
                    num++;
                }
            }
        }
        if(flag && num == N + 1){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}