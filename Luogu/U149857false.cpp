#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long n,m;
    scanf("%lld %lld",&n,&m);
    if(3*m >= n){
        long long sum = 0;
        long long count = 0;
        for(long long i=1;;i*=3){
            sum = i + i + i;
            count++;
            if(sum >= n){
                printf("%d\n",count);
                return 0;
            }
        }
    }
    else{
        long long count = 0;
        count += n/(m*2);
        n = max(m,n - n/(m*2)*2*m);
        long long sum = 0;
        for(long long i=1;;i*=3){
            sum = i + i + i;
            count++;
            if(sum >= n){
                printf("%d\n",count);
                return 0;
            }
        }
    }
}