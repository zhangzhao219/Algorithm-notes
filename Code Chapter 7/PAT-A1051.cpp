#include <bits/stdc++.h>
using namespace std;
stack<int> st;
int a[1010];
int main(void){
    // freopen("../test.in","r",stdin);
    int M,N,K;
    scanf("%d %d %d",&M,&N,&K);
    for(int i=0;i<K;i++){
        int temp;
        int count = 0;
        for(int j=0;j<N;j++){
            scanf("%d",&a[j]);
        }
        for(int j=1;j<=N;j++){
            if(st.empty() || (st.size() <M && st.top() != a[count]) ){
                st.push(j);
            }
            while(!st.empty() && st.top() == a[count]){
                st.pop();
                count++;
            }
        }
        if(st.empty()){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        while(!st.empty()){
            st.pop();
        }
    }
}