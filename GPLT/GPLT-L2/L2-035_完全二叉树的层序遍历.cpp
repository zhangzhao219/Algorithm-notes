#include <bits/stdc++.h>
using namespace std;
int N;
int num[400];

void postorder(int root){
    if(num[root] == -1){
        return;
    }
    postorder(root * 2);
    postorder(root * 2 + 1);
    scanf("%d",&num[root]);
}
int main(void){
    scanf("%d",&N);
    memset(num,-1,sizeof(num));
    for(int i=1;i<=N;i++){
        num[i] = 0;
    }
    postorder(1);
    for(int i=1;i<=N;i++){
        printf("%d",num[i]);
        if(i == N){
            printf("\n");
        }
        else{
            printf(" ");
        }
    }
}