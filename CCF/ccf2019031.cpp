#include<bits/stdc++.h>
using namespace std;
int num[100010];
int n;
int main(void){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    int maxn = num[0];
    int minn = num[n-1];
    if(maxn < minn){
        swap(minn,maxn);
    }
    if(n%2 == 0){
        if((num[n/2] + num[n/2-1])%2 == 0){
            printf("%d %d %d\n",maxn,(num[n/2] + num[n/2-1]) / 2,minn);
        }
        else{
            printf("%d %.1f %d\n",maxn,(num[n/2] + num[n/2-1]) / 2.0,minn);
        }
    }
    else{
        printf("%d %d %d\n",maxn,num[n/2],minn);
    }
    return 0;
}