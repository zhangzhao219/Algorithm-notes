#include <bits/stdc++.h>
using namespace std;
long long n,k;
long long a[100010];
int main(void){
    scanf("%lld %lld",&n,&k);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    long long count1 = 0;
    long long index = 1;
    while(1){
        long long start = a[index];
        count1++;
        while(start + k >= a[index] && index <= n){
            index++;
        }
        if(index > n){
            break;
        }
    }
    printf("%d",count1);
    return 0;
}