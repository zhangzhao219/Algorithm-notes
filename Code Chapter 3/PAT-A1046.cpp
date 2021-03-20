#include <bits/stdc++.h>
using namespace std;
int dis[100010];
int N;
int M;
int total = 0;
int main(void){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&dis[i]);
        total += dis[i];
        dis[i] = total;
    }
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        int temp1,temp2;
        scanf("%d %d",&temp1,&temp2);
        if(temp1 > temp2){
            swap(temp1,temp2);
        }
        int dis1 = dis[temp2-2] - dis[temp1-2];
        
        printf("%d\n",min(dis1,total - dis1));
    }
    return 0;
}