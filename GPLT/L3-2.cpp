#include <bits/stdc++.h>
using namespace std;
int N,M;
int paper[100010];
vector<int> kou[110];
// bool vis[110];

bool comp(vector<int> vt,int num){
    for(int i=0;i<vt.size();i++){
        if(vt[i] != paper[num]){
            return false;
        }
        else{
            num++;
        }
    }
    return true;
}
int main(void){
    freopen("./test.in","r",stdin);
    // memset(vis,false,sizeof(vis));
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&paper[i]);
    }
    scanf("%d",&M);
    int tempsum;
    int t;
    for(int i=1;i<=M;i++){
        scanf("%d",&tempsum);
        while(tempsum--){
            scanf("%d",&t);
            kou[i].push_back(t);
        }
    }
    vector<int> result;
    for(int i=0;i<N;){
        int res;
        for(int j=1;j<=M;j++){
            if(comp(kou[j],i)){
                // vis[j] = true;
                result.push_back(j);
                res = kou[j].size();
                break;
            }
        }
        i += res-1;
    }
    for(int i=0;i<result.size();i++){
        printf("%d",result[i]);
        if(i == result.size() - 1){
            printf("\n");
        }
        else{
            printf(" ");
        }
    }
    return 0;
}