#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int N,M,K;
int origin[maxn][maxn];
int change[maxn][maxn];
bool vis[maxn];

void DFS(int i){
    vis[i] = true;
    for(int j=1;j<=N;j++){
        if(vis[j] == false && change[i][j] == 1){
            DFS(j);
        }
    }
    return;
}

int main(void){
    freopen("../test.in","r",stdin);
    fill(origin[0],origin[0] + maxn*maxn,0);
    scanf("%d %d %d",&N,&M,&K);
    int t1,t2;
    for(int i=0;i<M;i++){
        scanf("%d %d",&t1,&t2);
        origin[t1][t2] = 1;
        origin[t2][t1] = 1;
    }
    for(int k=0;k<K;k++){
        scanf("%d",&t1);
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(i == t1 || j == t1){
                    change[i][j] = 0;
                }
                else{
                    change[i][j] = origin[i][j];
                }
            }
        }
        int count1 = -1;
        memset(vis,false,sizeof(vis));
        vis[t1] = true;
        for(int i=1;i<=N;i++){
            if(vis[i] == false){
                DFS(i);
                count1++;
            }
        }
        printf("%d\n",count1);
    }
    return 0;
}