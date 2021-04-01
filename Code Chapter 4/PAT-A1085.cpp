#include <bits/stdc++.h>
using namespace std;
long long N;
long long p;
long long a[100010];
int main(void){
    scanf("%lld %lld",&N,&p);
    for(long long i=0;i<N;i++){
        scanf("%lld",&a[i]);
    }
    sort(a,a+N);
    long long ans = 1;
    for(int i=0;i<N;i++){
        long long j = upper_bound(a+i+1,a+N,a[i]*p) - a;
        ans = max(ans,j-i);
    }
    printf("%lld",ans);
    return 0;
}