#include<bits/stdc++.h>
using namespace std;
int main(void){
    int A,B,D;
    scanf("%d %d %d",&A,&B,&D);
    int sum = A + B;
    int result = 0;
    int ans[31];
    int num = 0;
    do{
        ans[num++] = sum % D;
        sum /= D;
    }while(sum != 0);
    for(int i=num-1;i>=0;i--){
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}