#include <bits/stdc++.h>
using namespace std;
int N,Q;
int num[10010];
int main(void){
    int index = 1;
    while(scanf("%d %d",&N,&Q) == 2 && N){
        printf("CASE# %d:\n",index++);
        for(int i=1;i<=N;i++){
            scanf("%d",&num[i]);
        }
        sort(num+1,num+N+1);
        for(int i=0;i<Q;i++){
            int tn;
            scanf("%d",&tn);
            int t = lower_bound(num+1,num+N+1,tn) - num;
            if(num[t] == tn){
                printf("%d found at %d\n",num[t],t);
            }
            else{
                printf("%d not found\n",tn);
            }
        }
    }
    return 0;
}
/*
4 1
2
3
5
1
5
5 2
1
3
3
3
1
2
3
0 0
*/
