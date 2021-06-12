#include <bits/stdc++.h>
using namespace std;
int a[1010];

int main(void){
    int N;
    scanf("%d",&N);
    memset(a,0,sizeof(a));
    while(N--){
        int x,y,z;
        scanf("%d-%d %d",&x,&y,&z);
        a[x] += z;
    }
    int maxnum = -1;
    int maxscore = -1;
    for(int i=0;i<1010;i++){
        if(a[i] > maxscore){
            maxscore = a[i];
            maxnum = i;
        }
    }
    printf("%d %d\n",maxnum,maxscore);
    return 0;
}