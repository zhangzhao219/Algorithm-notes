#include<bits/stdc++.h>
using namespace std;
int r,y,g;
int main(void){
    scanf("%d %d %d",&r,&y,&g);
    long long total = 0;
    int sum;
    scanf("%d",&sum);
    for(int i=0;i<sum;i++){
        int t1,t2;
        scanf("%d %d",&t1,&t2);
        if(t1 == 0 || t1 == 1){
            total += t2;
        }
        else if(t1 == 2){
            total += t2;
            total += r;
        }
    }
    printf("%lld\n",total);
    return 0;
}