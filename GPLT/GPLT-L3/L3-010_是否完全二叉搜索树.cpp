#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000000;
int tree[maxn];

void insert(int root,int x){
    if(tree[root] == 0){
        tree[root] = x;
        return;
    }
    if(x < tree[root]){
        insert(root*2+1,x);
    }
    else{
        insert(root*2,x);
    }
    return;
}

int main(void){
    int N;
    memset(tree,0,sizeof(tree));
    scanf("%d",&N);
    int child = 0;
    int temp;
    for(int i=0;i<N;i++){
        scanf("%d",&temp);
        
        insert(1,temp);
    }
    int sign = 0;
    for(int i=1;i<maxn;i++){
        if(tree[i] != 0){
            printf("%d",tree[i]);
            N--;
            if(N == 0){
                printf("\n");
                break;
            }
            else{
                printf(" ");
            }
        }
        else{
            sign = 1;
        }
    }
    if(sign == 1){
        printf("NO\n");
    }
    else{
        printf("YES\n");
    }
    return 0;
}