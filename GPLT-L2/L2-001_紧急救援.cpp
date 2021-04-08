#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
const int INF = 1000000000;

int N,M,S,D;
bool vis[maxn];
int dis[maxn];
int G[maxn][maxn];
int weight[maxn];

vector<int> pre[maxn];
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
int maxvalue = -1;
int num = 0;
void DFS(int s){
    if(s == S){
        temppath.push_back(s);
        num++;
        int value = 0;
        for(int i=0;i<temppath.size();i++){
            value += weight[temppath[i]];
        }
        if(value > maxvalue){
            maxvalue = value;
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
    scanf("%d %d %d %d",&N,&M,&S,&D);
    for(int i=0;i<N;i++){
        scanf("%d",&weight[i]);
    }
    memset(vis,false,sizeof(vis));
    fill(dis,dis + maxn,INF);
    fill(G[0],G[0] + maxn * maxn,INF);
    int t1,t2;
    for(int i=0;i<M;i++){
        scanf("%d %d",&t1,&t2);
        scanf("%d",&G[t1][t2]);
        G[t2][t1] = G[t1][t2];
    }
    Dijkstra(S);
    DFS(D);
    printf("%d %d\n",num,maxvalue);
    for(int i=path.size() - 1;i>=0;i--){
        printf("%d",path[i]);
        if(i == 0){
            printf("\n");
        }
        else{
            printf(" ");
        }
    }
    return 0;
}