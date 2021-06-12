#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int maxn = 510;
int Cmax,N,Sp,M;
int G[maxn][maxn];
bool vis[maxn];
int d[maxn];
int re[maxn];

vector<int> pre[maxn];
void dijkstra(int s){
    d[s] = 0;
    for(int i=0;i<N;i++){
        int u = -1,MIN = INF;
        for(int j=0;j<=N;j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1){
            return;
        }
        vis[u] = true;
        for(int v=0;v<=N;v++){
            if(vis[v] == false && G[u][v] != INF){
                if(d[v] > d[u] + G[u][v]){
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(d[v] == d[u] + G[u][v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

vector<int> temppath;
vector<int> path;
int sendbikes = INF;
int receivebikes = INF;

void DFS(int end){
    if(end == 0){
        temppath.push_back(end);
        int need = 0;
        int remain = 0;
        for(int i=temppath.size() - 1;i>=0;i--){
            if(re[temppath[i]] > 0){
                remain += re[temppath[i]];
            }
            else{
                if(remain > abs(re[temppath[i]])){
                    remain -= abs(re[temppath[i]]);
                }
                else{
                    need += abs(re[temppath[i]]) - remain;
                    remain = 0;
                }
            }
        }
        if(need < sendbikes){
            receivebikes = remain;
            sendbikes = need;
            path = temppath;
        }
        else if(need == sendbikes && remain < receivebikes){
            receivebikes = remain;
            path = temppath;
        }
        temppath.pop_back();
        return;
    }
    temppath.push_back(end);
    for(int i=0;i<pre[end].size();i++){
        DFS(pre[end][i]);
    }
    temppath.pop_back();
}

int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d %d %d %d",&Cmax,&N,&Sp,&M);
    memset(vis,false,sizeof(vis));
    fill(G[0],G[0] + maxn * maxn,INF);
    fill(d,d+maxn,INF);
    re[0] = 0;
    for(int i=1;i<=N;i++){
        scanf("%d",&re[i]);
        re[i] -= Cmax / 2;
    }
    int t1,t2;
    for(int i=0;i<M;i++){
        scanf("%d %d",&t1,&t2);
        scanf("%d",&G[t1][t2]);
        G[t2][t1] = G[t1][t2];
    }
    dijkstra(0);
    DFS(Sp);
    printf("%d ",sendbikes);
    for(int i=path.size()-1;i>=0;i--){
        printf("%d",path[i]);
        if(i != 0){
            printf("->");
        }
        else{
            printf(" ");
        }
    }
    printf("%d\n",receivebikes);
    return 0;
}