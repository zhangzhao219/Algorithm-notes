#include <bits/stdc++.h>
using namespace std;
const int maxn = 300;
const int INF = 1000000000;
int N,K;
int start = 0;
int end1;
map<string,int> stringtoint;
map<int,string> inttostring;
int weight[maxn];
bool vis[maxn];
int dis[maxn];
int G[maxn][maxn];

vector<int> pre[maxn];
void Dijkstra(int s){
    dis[s] = 0;
    for(int i=0;i<N;i++){
        int u=-1,MIN = INF;
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
int maxcost = -1;
int num = 0;
void DFS(int s){
    if(s == 0){
        num++;
        temppath.push_back(s);
        int value = 0;
        for(int i=0;i<temppath.size();i++){
            value += weight[temppath[i]];
        }
        if(value > maxcost){
            maxcost = value;
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
    memset(vis,false,sizeof(vis));
    fill(dis,dis + maxn,INF);
    fill(G[0],G[0] + maxn * maxn,INF);
    scanf("%d %d",&N,&K);
    string temp,temp2;
    cin >> temp;
    stringtoint[temp] = 0;
    inttostring[0] = temp;
    weight[0] = 0;
    for(int i=1;i<N;i++){
        cin >> temp >> weight[i];
        stringtoint[temp] = i;
        inttostring[i] = temp;
    }
    int t;
    for(int i=0;i<K;i++){
        cin >> temp >> temp2 >> t;
        int t1 = stringtoint[temp];
        int t2 = stringtoint[temp2];
        G[t1][t2] = t;
        G[t2][t1] = t;
    }
    end1 = stringtoint["ROM"];
    Dijkstra(start);
    DFS(end1);
    printf("%d %d %d %d\n",num,dis[end1],maxcost,maxcost / (path.size() - 1));
    for(int i=path.size() - 1;i>=0;i--){
        cout << inttostring[path[i]];
        if(i != 0){
            printf("->");
        }
        else{
            printf("\n");
        }
    }
    return 0;
}