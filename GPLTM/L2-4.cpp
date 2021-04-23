#include <bits/stdc++.h>
using namespace std;
int N,M;
int G[210][210];
const int INF = 1000000010;
bool vis[210];
int main(void){
    freopen("./test.in","r",stdin);
    scanf("%d %d",&N,&M);
    for(int i=0;i<N+1;i++){
        for(int j=0;j<N+1;j++){
            G[i][j] = INF;
        }
    }
    for(int i=0;i<M;i++){
        int t1,t2;
        scanf("%d %d",&t1,&t2);
        scanf("%d",&G[t1][t2]);
        G[t2][t1] = G[t1][t2];
    }
    int times;
    scanf("%d",&times);
    int bestcount = 0;
    int bestnum = 0;
    int bestcost = INF;
    for(int i=1;i<=times;i++){
        int tempnum;
        scanf("%d",&tempnum);
        if(tempnum != N){
            int t2;
            while(tempnum--){
                scanf("%d",&t2);
            }
        }
        else{
            int sign = 0;
            int tempcost = 0;
            vector<int> path;
            path.push_back(0);
            memset(vis,false,sizeof(vis));
            for(int j=0;j<tempnum;j++){
                int temp;
                scanf("%d",&temp);
                if(vis[temp] == false){
                    vis[temp] = true;
                }
                else{
                    sign = 1;
                }
                path.push_back(temp);
            }
            path.push_back(0);
            for(int j=0;j<path.size() - 1;j++){
                if(G[path[j]][path[j+1]] == INF){
                    sign = 1;
                    break;
                }
                else{
                    tempcost += G[path[j]][path[j+1]];
                }
            }
            if(sign == 0){
                bestcount++;
                if(tempcost < bestcost){
                    bestcost = tempcost;
                    bestnum = i;
                }
            }
        }
    }
    printf("%d\n%d %d",bestcount,bestnum,bestcost);
    return 0;
}