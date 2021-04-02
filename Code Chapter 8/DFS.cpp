#include <bits/stdc++.h>
using namespace std;
int n,V;
int w[30];
int c[30];
int maxValue = 0;
void DFS(int index,int totalweight,int totalvalue){
    if(index == n){
        return;
    }
    DFS(index+1,totalweight,totalvalue);
    if(totalweight + w[index] <= V){
        if(totalvalue + c[index] > maxValue){
            maxValue = totalvalue + c[index];
        }
        DFS(index+1,totalweight + w[index],totalvalue + c[index]);
    }
}
int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d %d",&n,&V);
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&c[i]);
    }
    DFS(0,0,0);
    printf("%d",maxValue);
    return 0;
}