#include <bits/stdc++.h>
using namespace std;
int N,M;
const int INF = 1000000000;
bool vis[210];
int G[210][210];
vector<int> vt;
int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d %d",&N,&M);
    for(int i=0;i<N+1;i++){
        for(int j=0;j<N+1;j++){
            G[i][j] = INF;
        }
    }
    int t1,t2;
    while(M--){
        scanf("%d %d",&t1,&t2);
        scanf("%d",&G[t1][t2]);
        G[t2][t1] = G[t1][t2];
    }
    int countnum = 0;
    int num = 0;
    int minsum = INF;
    scanf("%d",&M);
    for(int i=1;i<=M;i++){
        vt.clear();
        vt.push_back(0);
        memset(vis,false,sizeof(vis));
        int sign = 0;
        scanf("%d",&t1);
        if(t1 != N){
            sign = 1;
        }
        for(int j=0;j<t1;j++){
            scanf("%d",&t2);
            vt.push_back(t2);
            if(vis[t2] == true){
                sign = 1;
            }
            else{
                vis[t2] = true;
            }
        }
        
        if(sign == 0){
            int cost = 0;
            int sign1 = 0;
            vt.push_back(0);
            for(int j=0;j<vt.size()-1;j++){
                if(G[vt[j]][vt[j+1]] != INF){
                    cost += G[vt[j]][vt[j+1]];
                }
                else{
                    sign1 = 1;
                    break;
                }
            }
            if(sign1 == 0){
                countnum++;
                if(cost < minsum){
                    minsum = cost;
                    num = i;
                }
            }
        }
    }
    printf("%d\n%d %d\n",countnum,num,minsum);
    return 0;
}