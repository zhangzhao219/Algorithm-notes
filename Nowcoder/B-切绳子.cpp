#include <bits/stdc++.h>
using namespace std;
int T;

int maxn = 0;

void DFS(long long n,int sum){
    if(n == 1){
        maxn = max(maxn,sum);
        return;
    }
    if(n/2 > n - n/2){
        DFS(n/2,sum + 1);
    }
    else{
        DFS(n - n/2,sum + 1);
    }
}

int main(void){
    scanf("%d",&T);
    while(T--){
        maxn = 0;
        long long n;
        scanf("%lld",&n);
        DFS(n,0);
        printf("%d\n",maxn+1);
    }
    return 0;
}