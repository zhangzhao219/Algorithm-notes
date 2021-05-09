#include<bits/stdc++.h>
using namespace std;
int apple[100010];
int T;
int main(void){
    scanf("%d",&T);
    int N,M;
    
    while(T--){
        scanf("%d %d",&N,&M);
        for(int i=1;i<=N;i++){
            scanf("%d",&apple[i]);
        }
        while(M--){
            int temp,l,r;
            scanf("%d",&temp);
            if(temp == 1){
                scanf("%d",&l);
                for(int i=1;i<=N;i++){
                    if(apple[i] < l){
                        apple[i] += l;
                    }
                }
            }
            else{
                scanf("%d %d",&l,&r);
                long long tempsum = 0;
                for(int i=l;i<=r;i++){
                    tempsum += apple[i];
                }
                printf("%d\n",tempsum);
            }
        }
    }
}