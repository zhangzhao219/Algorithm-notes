#include<bits/stdc++.h>
using namespace std;
long long k,n;
long long a[10000010];
int main(void){
    scanf("%lld %lld",&k,&n);
    long long flag = 0;
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i] == i){
            flag = 1;
        }
    }
    if(flag == 1){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    long long L,R,C;
    for(long long i=0;i<k-1;i++){
        scanf("%lld %lld %lld",&L,&R,&C);
        for(long long j=L;j<=R;j++){
            a[j] += C;
        }
        flag = 0;
        for(long long j=1;j<=n;j++){
            if(a[j] == j){
                flag = 1;
                break;
            }
            else if(a[j] > j){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
    
}