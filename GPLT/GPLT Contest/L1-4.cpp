#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N,M;
    scanf("%d %d",&N,&M);
    double temp;
    for(int i=0;i<N;i++){
        scanf("%lf",&temp);
        if(temp < M){
            printf("On Sale! %.1f\n",temp);
        }
    }
    return 0;
}