#include <bits/stdc++.h>
using namespace std;
int N,M;
int G[10010];
int at[10010];
vector<int> GT[10010];

int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++){
        G[i] = 0;
    }
    int t1,t2;
    for(int i=0;i<M;i++){
        scanf("%d %d",&t1,&t2);
        G[t1]++;
        G[t2]++;
        GT[t1].push_back(t2);
        GT[t2].push_back(t1);
    }
    int sum;
    scanf("%d",&sum);
    while(sum--){
        for(int i=1;i<=N;i++){
            at[i] = G[i];
        }
        scanf("%d",&t1);
        for(int i=0;i<t1;i++){
            scanf("%d",&t2);
            at[t2] = 0;
            for(int j=0;j<GT[t2].size();j++){
                at[GT[t2][j]]--;
            }
        }
        int sign = 0;
        for(int i=1;i<=N;i++){
            if(at[i] > 0){
                sign = 1;
                break;
            }
        }
        if(sign == 1){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
    return 0;
}