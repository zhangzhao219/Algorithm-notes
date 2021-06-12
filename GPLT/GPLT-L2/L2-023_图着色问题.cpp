#include <bits/stdc++.h>
using namespace std;
int V,E,K;
vector<int> vt[510];
int color[510];
bool vis[510];

int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d %d %d",&V,&E,&K);
    int t1,t2;
    for(int i=0;i<E;i++){
        scanf("%d %d",&t1,&t2);
        vt[t1].push_back(t2);
    }
    int sum;
    scanf("%d",&sum);
    while(sum--){
        int sign = 0;
        memset(vis,false,sizeof(vis));
        int num = 0;
        for(int i=1;i<=V;i++){
            scanf("%d",&color[i]);
            if(vis[color[i]] == false){
                vis[color[i]] = true;
                num++;
            }
        }
        if(num != K){
            sign = 1;
        }
        for(int i=1;i<=V;i++){
            for(int j=0;j<vt[i].size();j++){
                if(color[i] == color[vt[i][j]]){
                    sign = 1;
                    break;
                }
            }
            if(sign == 1){
                break;
            }
        }
        if(sign == 1){
            printf("No\n");
        }
        else{
            printf("Yes\n");
        }
    }
    return 0;
}