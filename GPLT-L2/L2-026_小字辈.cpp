#include <bits/stdc++.h>
using namespace std;
int N;
int parent[100010];
vector<int> p[100010];
int main(void){
    scanf("%d",&N);
    int ancient;
    for(int i=1;i<=N;i++){
        scanf("%d",&parent[i]);
        if(parent[i] == -1){
            ancient = i;
        }
    }
    for(int i=1;i<=N;i++){
        p[parent[i]].push_back(i);
    }
    memset(parent,0,sizeof(parent));
    queue<int> q;
    q.push(ancient);
    parent[ancient] = 1;
    int nowlayer = 1;
    vector<int> bottom;
    bottom.push_back(ancient);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i=0;i<p[t].size();i++){
            q.push(p[t][i]);
            parent[p[t][i]] = parent[t] + 1;
            if(parent[p[t][i]] > nowlayer){
                nowlayer = parent[p[t][i]];
                bottom.clear();
                bottom.push_back(p[t][i]);
            }
            else if(parent[p[t][i]] == nowlayer){
                bottom.push_back(p[t][i]);
            }
        }
    }
    sort(bottom.begin(),bottom.end());
    printf("%d\n",nowlayer);
    for(int i=0;i<bottom.size();i++){
        printf("%d",bottom[i]);
        if(i != bottom.size() - 1){
            printf(" ");
        }
        else{
            printf("\n");
        }
    }
}