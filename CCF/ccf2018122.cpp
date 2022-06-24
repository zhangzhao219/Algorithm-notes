#include<bits/stdc++.h>
using namespace std;
int r,y,g;
int judge(int time){
    if(time < y + r){
        return y + r - time;
    }
    else{
        return 0;
    }
}
int main(void){
    scanf("%d %d %d",&r,&y,&g);
    int sum1 = r + g + y;
    long long total = 0;
    int sum;
    scanf("%d",&sum);
    for(int i=0;i<sum;i++){
        int t1,t2;
        scanf("%d %d",&t1,&t2);
        if(t1 == 0){
            total += t2;
        }
        else if(t1 == 2){
            total += judge((y - t2 + total)%sum1);
        }
        else if(t1 == 1){
            total += judge((y + r - t2 + total)%sum1);
        }
        else if(t1 == 3){
            total += judge((sum1 - t2 + total)%sum1);
        }
    }
    printf("%lld\n",total);
    return 0;
}