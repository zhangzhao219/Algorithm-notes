#include <bits/stdc++.h>
using namespace std;
int pri[210];
int stemp[10010];
int dp[10010];
int main(void){
    freopen("../test.in","r",stdin);
    int N,M,L;
    scanf("%d",&N);
    memset(pri,-1,sizeof(pri));
    scanf("%d",&M);
    int temp;
    for(int i=0;i<M;i++){
        scanf("%d",&temp);
        pri[temp] = i;
    }
    scanf("%d",&L);
    int num2 = 0;
    for(int i=0;i<L;i++){
        scanf("%d",&temp);
        if(pri[temp] != -1){
            stemp[num2++] = pri[temp];
        }
    }
    int ans = -1;
    for(int i=0;i<num2;i++){
        dp[i] = 1;
        for(int j=0;j<i;j++){
            if(stemp[i] >= stemp[j] && (dp[j] + 1 > dp[i])){
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}