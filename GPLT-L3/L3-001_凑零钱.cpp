#include <bits/stdc++.h>
using namespace std;
int N,M;
int coin[10010];
int dp[10010];
bool choice[10010][10010];
bool flag[10010];
bool cmp(int a,int b){
    return a > b;
}
int main(void){
    freopen("../test.in","r",stdin);
    memset(dp,0,sizeof(dp));
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++){
        scanf("%d",&coin[i]);
    }
    sort(coin+1,coin + N + 1,cmp);
    for(int i=1;i<=N;i++){
        for(int v=M;v>=coin[i];v--){
            if(dp[v] <= dp[v-coin[i]] + coin[i]){
                dp[v] = dp[v-coin[i]] + coin[i];
                choice[i][v] = true;
            }
            else{
                choice[i][v] = false;
            }
        }
    }
    if(dp[M] != M){
        printf("No Solution\n");
    }
    else{
        int k = N;
        int num = 0;
        int v = M;
        while(k >= 0){
            if(choice[k][v] == 1){
                flag[k] = true;
                v -= coin[k];
                num++;
            }
            else{
                flag[k] = false;
            }
            k--;
        }
        for(int i=N;i>=1;i--){
            if(flag[i] == true){
                printf("%d",coin[i]);
                num--;
                if(num > 0){
                    printf(" ");
                }
                else{
                    printf("\n");
                }
            }
        }
    }
    return 0;
}