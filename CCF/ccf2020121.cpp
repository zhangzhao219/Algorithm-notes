#include<bits/stdc++.h>
using namespace std;
int n;
int sum = 0;
int main(void){
    scanf("%d",&n);
    int t1,t2;
    for(int i=0;i<n;i++){
        scanf("%d %d",&t1,&t2);
        sum += t1 * t2;
    }
    if(sum >= 0){
        printf("%d\n",sum);
    }
    else{
        printf("0");
    }
    return 0;
}