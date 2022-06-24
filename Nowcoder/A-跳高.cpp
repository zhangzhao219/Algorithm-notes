#include <bits/stdc++.h>
using namespace std;
int num[1000000];
bool cmp(int a,int b){
    return a > b;
}
int main(void){
    int n,h,u;
    scanf("%d %d %d",&n,&h,&u);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    if(h >= u){
        printf("0\n");
        return 0;
    }
    sort(num,num + n,cmp);
    u -= h;
    for(int i=0;i<n;i++){
        u -= num[i];
        if(u <= 0){
            printf("%d\n",i+1);
            return 0;
        }
    }
}