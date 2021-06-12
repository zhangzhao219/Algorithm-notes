#include <bits/stdc++.h>
using namespace std;
int a[10010];
int dp[10010];
int start[10010];
int end1[10010];
int main(void){
    int K;
    scanf("%d",&K);
    int sign = 1;
    for(int i=0;i<K;i++){
        scanf("%d",&a[i]);
        if(a[i] >= 0){
            sign = 0;
        }
    }
    if(sign == 1){
        printf("0 %d %d\n",a[0],a[K-1]);
        return 0;
    }
    dp[0] = a[0];
    start[0] = 0;
    end1[0] = 0;
    for(int i=1;i<K;i++){
        if(a[i] > dp[i-1] + a[i]){
            dp[i] = a[i];
            start[i] = i;
        }
        else{
            dp[i] = dp[i-1] + a[i];
            start[i] = start[i-1];
        }
    }
    int index = 0;
    for(int i=0;i<K;i++){
        if(dp[i] > dp[index]){
            index = i;
        }
    }
    printf("%d %d %d\n",dp[index],a[start[index]],a[index]);
    return 0;
}