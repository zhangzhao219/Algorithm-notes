#include <bits/stdc++.h>
using namespace std;
int n,k;
bool stair[110];
int times = 0;
void DFS(int s){
    if(stair[s] == true){
        return;
    }
    else if(s == n){
        times++;
        return;
    }
    else if(s > n || stair[s] == true){
        return;
    }
    for(int i=1;i<=3;i++){
        DFS(s+i);
    }
}
int main(void){
    scanf("%d %d",&n,&k);
    memset(stair,false,sizeof(stair));
    int t;
    for(int i=0;i<k;i++){
        scanf("%d",&t);
        stair[t] = true;
    }
    DFS(0);
    printf("%d\n",times);
    return 0;
}