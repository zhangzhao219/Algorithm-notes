#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
const int INF = 1000000000;

int N,M,C1,C2;
bool vis[maxn];
int d[maxn];
int weight[maxn];
int G[maxn][maxn];

vector<int> pre[maxn];
void Dijkstra(int s){
    d[s] = 0;
    for(int i=0;i<N;i++){
        int u = -1,MIN = INF;
        for(int j=0;j<N;j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1){
            return;
        }
        vis[u] = true;
        for(int v=0;v<N;v++){
            if(vis[v] == false && G[u][v] != INF){
                if(d[v] > G[u][v] + d[u]){
                    d[v] = G[u][v] + d[u];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(d[v] == G[u][v] + d[u]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int optvalue = 0;
int num = 0;
vector<int> path,temppath;

void DFS(int v){
    if(v == C1){
        num++;
        temppath.push_back(v);
        int value = 0;
        for(int i=0;i<temppath.size();i++){
            value += weight[temppath[i]];
        }
        if(value > optvalue){
            optvalue = value;
            path = temppath;
        }
        temppath.pop_back();
        return;
    }
    temppath.push_back(v);
    for(int i=0;i<pre[v].size();i++){
        DFS(pre[v][i]);
    }
    temppath.pop_back();
}

int main(void){
    freopen("../test.in","r",stdin);
    memset(vis,false,sizeof(vis));
    fill(G[0],G[0] + maxn * maxn,INF);
    fill(d,d + maxn,INF);

    scanf("%d %d %d %d",&N,&M,&C1,&C2);
    for(int i=0;i<N;i++){
        scanf("%d",&weight[i]);
    }
    int t1,t2;
    for(int i=0;i<M;i++){
        scanf("%d %d",&t1,&t2);
        scanf("%d",&G[t1][t2]);
        G[t2][t1] = G[t1][t2];
    }
    Dijkstra(C1);
    DFS(C2);
    printf("%d %d\n",num,optvalue);
    return 0;
}