#include <bits/stdc++.h>
using namespace std;
int Cmax,N,Sp,M;

const int maxn = 510;
const int INF = 1000000000;

bool vis[maxn];
int dis[maxn];
int weight[maxn];
int G[maxn][maxn];

vector<int> pre[maxn];
void Dijkstra(int s){
    dis[s] = 0;
    for(int i=0;i<N;i++){
        int u = -1,MIN = INF;
        for(int j=0;j<=N;j++){
            if(vis[j] == false && dis[j] < MIN){
                u = j;
                MIN = dis[j];
            }
        }
        if(u == -1){
            return;
        }
        vis[u] = true;
        for(int v=0;v<=N;v++){
            if(vis[v] == false && G[u][v] != INF){
                if(dis[v] > dis[u] + G[u][v]){
                    dis[v] = dis[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(dis[v] == dis[u] + G[u][v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

vector<int> temppath;
vector<int> path;
int minneed = INF;
int minremain = INF;

void DFS(int s){
    if(s == 0){
        temppath.push_back(s);
        int need = 0,remain = 0;
        for(int i=temppath.size() - 1;i >= 0;i--){
            int id = temppath[i];
            if(weight[id] > 0){
                remain += weight[id];
            }
            else{
                if(remain > abs(weight[id])){
                    remain -= abs(weight[id]);
                }
                else{
                    need = need + abs(weight[id]) - remain;
                    remain = 0;
                }
            }
        }
        if(need < minneed){
            minneed = need;
            minremain = remain;
            path = temppath;
        }
        else if(need == minneed && remain < minremain){
            minremain = remain;
            path = temppath;
        }
        temppath.pop_back();
        return;
    }
    temppath.push_back(s);
    for(int i=0;i<pre[s].size();i++){
        DFS(pre[s][i]);
    }
    temppath.pop_back();
}

int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d %d %d %d",&Cmax,&N,&Sp,&M);
    memset(vis,false,sizeof(vis));
    fill(dis,dis + maxn,INF);
    fill(G[0],G[0] + maxn * maxn,INF);
    weight[0] = 0;
    for(int i=1;i<=N;i++){
        scanf("%d",&weight[i]);
        weight[i] -= Cmax / 2;
    }
    int t1,t2;
    for(int i=0;i<M;i++){
        scanf("%d %d",&t1,&t2);
        scanf("%d",&G[t1][t2]);
        G[t2][t1] = G[t1][t2];
    }
    Dijkstra(0);
    DFS(Sp);
    printf("%d ",minneed);
    for(int i=path.size() - 1;i>=0;i--){
        printf("%d",path[i]);
        if(i != 0){
            printf("->");
        }
    }
    printf(" %d\n",minremain);
    return 0;
}