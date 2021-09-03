#include<bits/stdc++.h>
using namespace std;
int N,M,K;

vector<int> a[101];
int b[101];

int main(void){
    scanf("%d %d %d",&N,&M,&K);
    int t1,t2,t3;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            // printf("%d",j);
            scanf("%d",&t1);
            a[i].push_back(t1);
        }
    }
    for(int i=0;i<N-1;i++){
        scanf("%d %d %d",&t1,&t2,&t3);
        b[t1] = t3;
    }
    int count = 0;
    for(int i=0;i<M;i++){
        int mint = 200;
        int maxt = -1;
        for(int j=0;j<N;j++){
            if(a[j][i] == 1){
                mint = min(mint,j);
                maxt = max(maxt,j);
            }
        }
        int counttemp = 0;
        if(maxt > mint){
            for(int j=mint+1;j<=maxt;j++){
                counttemp += b[j];
            }
        }
        count = max(count,counttemp);
    }
    printf("%d",count);
    return 0;
}