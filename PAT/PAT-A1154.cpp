#include <bits/stdc++.h>
using namespace std;
int N,M,K;
vector<int> vt[10010];
set<int> st;
int num[10010];
int main(void){
    scanf("%d %d",&N,&M);
    int t1,t2;
    for(int i=0;i<M;i++){
        scanf("%d %d",&t1,&t2);
        vt[t1].push_back(t2);
    }
    scanf("%d",&K);
    while(K--){
        st.clear();
        memset(num,-1,sizeof(num));
        for(int i=0;i<N;i++){
            scanf("%d",&num[i]);
            st.insert(num[i]);
        }
        int sign = 0;
        for(int i=0;i<10010;i++){
            for(int j=0;j<vt[i].size();j++){
                if(num[i] == num[vt[i][j]]){
                    printf("No\n");
                    sign = 1;
                    break;
                }
            }
            if(sign == 1){
                break;
            }
        }
        if(sign == 0){
            printf("%d-coloring\n",st.size());
        }
    }
    return 0;

}