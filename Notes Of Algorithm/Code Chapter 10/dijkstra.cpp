#include <bits/stdc++.h>
using namespace std;
const int maxv = 1000;
const int inf = 1000000000;

int n,G[maxv][maxv];
int d[maxv];
bool vis[maxv];

void Dijkstra(int s){
    memset(vis,false,sizeof(vis));
    fill(d,d+maxv,inf);
    for(int i=0;i<n;i++){
        int u = -1,MIN = inf;
        for(int j=0;j<n;j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1){
            return;
        }
        vis[u] = true;
        for(int v=0;v<n;v++){
            if(vis[v] == false && G[u][v] != inf && d[u] + G[u][v] < d[v]){
                d[v] = d[u] + G[u][v];
            }
        }
    }
}


struct Node{
    int v,dis;
};

vector<Node> Adj[maxv];
void Dijkstra2(int s){
    memset(vis,false,sizeof(vis));
    fill(d,d+maxv,inf);
    for(int i=0;i<n;i++){
        int u=-1,MIN=inf;
        for(int j=0;j<n;j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1){
            return;
        }
        vis[u] = true;
        for(int j=0;j<Adj[u].size();j++){
            int v = Adj[u][j].v;
            if(vis[v] == false && d[u] + Adj[u][j].dis < d[v]){
                d[v] = d[u] + Adj[u][j].dis;
            }
        }
    }
}

int pre[maxv];
void DFS(int s,int v){
    if(v == s){
        printf("%d\n",s);
        return;
    }
    DFS(s,pre[v]);
    printf("%d\n",v);
}