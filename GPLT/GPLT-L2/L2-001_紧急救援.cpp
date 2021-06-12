#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int maxn = 510;

int N,M,S,D;

int G[maxn][maxn];
int rescue[maxn];
bool vis[maxn];
int d[maxn];
vector<int> pre[maxn];

void dijkstra(int s){
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
int maxvalue = -1;
int num = 0;
void DFS(int end){
    if(end == S){
        temppath.push_back(end);
        num++;
        int tempvalue = 0;
        for(int i=0;i<temppath.size();i++){
            tempvalue += rescue[temppath[i]];
        }
        if(tempvalue > maxvalue){
            maxvalue = tempvalue;
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
    scanf("%d %d %d %d",&N,&M,&S,&D);
    memset(vis,false,sizeof(vis));
    fill(d,d+maxn,INF);
    fill(G[0],G[0] + maxn * maxn,INF);
    for(int i=0;i<N;i++){
        scanf("%d",&rescue[i]);
    }
    int t1,t2;
    for(int i=0;i<M;i++){
        scanf("%d %d",&t1,&t2);
        scanf("%d",&G[t1][t2]);
        G[t2][t1] = G[t1][t2];
    }
    dijkstra(S);
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