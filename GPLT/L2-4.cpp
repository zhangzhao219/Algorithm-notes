#include <bits/stdc++.h>
using namespace std;
int N,M;
vector<int> vt[100010];
int num[110];
int main(void){
    freopen("./test.in","r",stdin);
    memset(num,-1,sizeof(num));
    scanf("%d %d",&N,&M);
    int tempsum;
    int t;
    for(int i=1;i<=N;i++){
        scanf("%d",&tempsum);
        while(tempsum--){
            scanf("%d",&t);
            vt[i].push_back(t);
        }
    }
    int t1,t2;
    int now = 1;
    while(M--){
        scanf("%d %d",&t1,&t2);
        if(t1 == 0){
            now = vt[now][t2-1];
        }
        else if(t1 == 1){
            num[t2] = now;
            printf("%d\n",now);
        }
        else{
            now = num[t2];
        }
    }
    printf("%d",now);
    return 0;
}