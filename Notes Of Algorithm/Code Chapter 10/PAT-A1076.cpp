#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int G[maxn][maxn];
int layer[maxn];

bool vis[maxn];

int N,L;
int main(void){
    freopen("../test.in","r",stdin);
    memset(vis,false,sizeof(vis));
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++){
            G[i][j] = 0;
            G[j][i] = 0;
        }
    }
    scanf("%d %d",&N,&L);
    int temp,temp2;
    for(int i=1;i<=N;i++){
        scanf("%d",&temp);
        for(int j=0;j<temp;j++){
            scanf("%d",&temp2);
            G[temp2][i] = 1;
        }
    }
    int query;
    scanf("%d",&query);
    for(int i=0;i<query;i++){
        memset(layer,0,sizeof(layer));
        memset(vis,false,sizeof(vis));
        scanf("%d",&temp);
        int count1 = 0;
        queue<int> q;
        q.push(temp);
        vis[temp] = true;
        while(!q.empty()){
            int t = q.front();
            if(layer[t] >= L){
                break;
            }
            q.pop();
            for(int j=1;j<=N;j++){
                if(G[t][j] == 1 && vis[j] == false){
                    vis[j] = true;
                    count1++;
                    layer[j] = layer[t] + 1;
                    q.push(j);
                }
            }
        }
        printf("%d\n",count1);
    }
    return 0;
}