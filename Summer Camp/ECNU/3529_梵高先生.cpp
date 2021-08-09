#include <bits/stdc++.h>
using namespace std;
int n;
int G[25][25];
int main(void){
    scanf("%d",&n);
    G[1][1] = 1;
    G[2][1] = 1;
    G[2][2] = 1;
    for(int i=3;i<=25;i++){
        G[i][1] = 1;
        for(int j=2;j<i;j++){
            G[i][j] = G[i-1][j] + G[i-1][j-1];
        }
        G[i][i] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%d",G[i][j]);
            if(i == j){
                printf("\n");
            }
            else{
                printf(" ");
            }
        }
    }
    return 0;
}