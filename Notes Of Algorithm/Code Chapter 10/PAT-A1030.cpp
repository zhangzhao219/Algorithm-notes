#include <bits/stdc++.h>
using namespace std;
int N,M,S,D;

const int maxn = 510;
const int INF = 1000000000;

struct node{
    int d;
    int cost;
}G[maxn][maxn];

int dis[maxn];
int cost[maxn];
bool vis[maxn];

vector<int> pre[maxn];
vector<int> temppath;
vector<int> path;

int minnumcost = INF;

void Dijkstra(int s){
    dis[s] = 0;
    for(int i=0;i<N;i++){
        int u = -1,MIN = INF;
        for(int j=0;j<N;j++){
            if(vis[j] == false && dis[j] < MIN){
                u = j;
                MIN = dis[j];
            }
        }
        if(u == -1){
            return;
        }
        vis[u] = true;
        for(int v=0;v<N;v++){
            if(vis[v] == false && G[u][v].d != INF){
                if(dis[v] > dis[u] + G[u][v].d){
                    dis[v] = dis[u] + G[u][v].d;
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(dis[v] == dis[u] + G[u][v].d){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int s){
    if(s == S){
        temppath.push_back(s);
        int value = 0;
        for(int i=0;i<temppath.size() - 1;i++){
            value += G[temppath[i]][temppath[i+1]].cost;
        }
        if(value < minnumcost){
            minnumcost = value;
            path = temppath;
        }
        temppath.pop_back();
    }
    temppath.push_back(s);
    for(int i=0;i<pre[s].size();i++){
        DFS(pre[s][i]);
    }
    temppath.pop_back();
}

int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d %d %d %d",&N,&M,&S,&D);
    fill(dis,dis+maxn,INF);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            G[i][j].d = INF;
            G[i][j].cost = 0;
        }
    }
    memset(vis,false,sizeof(vis));
    int t1,t2;
    for(int i=0;i<M;i++){
        scanf("%d %d",&t1,&t2);
        scanf("%d",&G[t1][t2].d);
        G[t2][t1].d = G[t1][t2].d;
        scanf("%d",&G[t1][t2].cost);
        G[t2][t1].cost = G[t1][t2].cost;
    }
    Dijkstra(S);
    DFS(D);
    for(int i=path.size() - 1;i>=0;i--){
        printf("%d ",path[i]);
    }
    printf("%d %d\n",dis[D],minnumcost);
    return 0;
}