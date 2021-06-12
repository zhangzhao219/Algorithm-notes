#include <bits/stdc++.h>
using namespace std;
int n;
long long P;
long long num[100010];
bool cmp(long long a,long long b){
    return a > b;
}
int main(void){
    scanf("%d %lld",&n,&P);
    for(int i=0;i<n;i++){
        scanf("%lld",&num[i]);
    }
    sort(num,num + n,cmp);
    int count1 = 0;
    for(int i=0;i<n;i++){
        if(i+1 <= n && num[i] + num[i+1] < P){
            break;
        }
        for(int j=i+1;j<n;j++){
            if(num[i] + num[j] > P && num[j] + P > num[i]){
                count1++;
            }
            if(num[i] + num[j] <= P){
                break;
            }
        }
    }
    printf("%d\n",count1);
    return 0;
}