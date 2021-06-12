#include <bits/stdc++.h>
using namespace std;
int N;
int num[100010];
int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&num[i]);
    }
    sort(num,num+N);
    int sum1 = 0,sum2 = 0,sum3 = 0,sum4 = 0;
    if(N%2 == 0){
        printf("Outgoing #: %d\n",N/2);
        printf("Introverted #: %d\n",N/2);
        for(int i=0;i<N/2;i++){
            sum1 += num[i];
        }
        for(int i=N/2;i<N;i++){
            sum2 += num[i];
        }
        printf("Diff = %d\n",sum2 - sum1);
    }
    else{
        for(int i=0;i<N/2;i++){
            sum1 += num[i];
        }
        for(int i=N/2;i<N;i++){
            sum2 += num[i];
        }
        int diff1 = sum2 - sum1;
        for(int i=0;i<=N/2;i++){
            sum3 += num[i];
        }
        for(int i=N/2 + 1;i<N;i++){
            sum4 += num[i];
        }
        int diff2 = sum4 - sum3;
        if(diff1 > diff2){
            printf("Outgoing #: %d\n",N/2 + 1);
            printf("Introverted #: %d\n",N/2);
            printf("Diff = %d\n",diff1);
        }
        else{
            printf("Outgoing #: %d\n",N/2);
            printf("Introverted #: %d\n",N/2 + 1);
            printf("Diff = %d\n",diff2);
        }
    }
    return 0;
}