#include <bits/stdc++.h>
using namespace std;
int T;
long long A;
long long B;
long long C;
int main(void){
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%lld %lld %lld",&A,&B,&C);
        long long result = A + B;
        int flag;
        if(A > 0 && B > 0 && result < 0){
            flag = 1;
        }
        else if(A < 0 && B < 0 && result >= 0){
            flag = 0;
        }
        else if(result > C){
            flag = 1;
        }
        else{
            flag = 0;
        }
        if(!flag){
            printf("Case #%d: false\n",i);
        }
        else{
            printf("Case #%d: true\n",i);
        }
    }
    return 0;

}