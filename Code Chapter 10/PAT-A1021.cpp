#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

int N;
set<int> result;
vector<int> G[maxn];
bool vis[maxn];
int layer[maxn];

bool judgevis(){
    for(int i=1;i<=N;i++){
        if(vis[i] == false){
            return false;
        }
    }
    return true;
}

void BFS(int index){
    
    queue<int> q;
    q.push(index);
    vis[index] = true;
    layer[index] = 0;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i=0;i<G[t].size();i++){
            if(vis[G[t][i]] == false){
                q.push(G[t][i]);
                vis[G[t][i]] = true;
                layer[G[t][i]] = layer[t] + 1;
            }
        }
    }
    return;
}

int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d",&N);
    if(N == 1){
        printf("1\n");
        return 0;
    }
    int t1,t2;
    for(int i=0;i<N-1;i++){
        scanf("%d %d",&t1,&t2);
        G[t1].push_back(t2);
        G[t2].push_back(t1);
    }
    memset(vis,false,sizeof(vis));
    memset(layer,0,sizeof(layer));
    BFS(1);
    if(judgevis()){
        int maxlayer;
        maxlayer = 0;
        for(int i=1;i<=N;i++){
            if(layer[i] > maxlayer){
                maxlayer = layer[i];
            }
        }
        for(int i=1;i<=N;i++){
            if(layer[i] == maxlayer){
                result.insert(i);
            }
        }
        memset(vis,false,sizeof(vis));
        memset(layer,0,sizeof(layer));
        BFS(*result.begin());
        maxlayer = 0;
        for(int i=1;i<=N;i++){
            if(layer[i] > maxlayer){
                maxlayer = layer[i];
            }
        }
        for(int i=1;i<=N;i++){
            if(layer[i] == maxlayer){
                result.insert(i);
            }
        }
        set<int>::iterator it;
        for(it=result.begin();it != result.end();it++){
            printf("%d\n",*it);
        }
        return 0;
    }
    int count1 = 1;
    while(!judgevis()){
        for(int i=1;i<=N;i++){
            if(vis[i] == false){
                BFS(i);
                count1++;
                break;
            }
        }
    }
    printf("Error: %d components\n",count1);
    return 0;
}