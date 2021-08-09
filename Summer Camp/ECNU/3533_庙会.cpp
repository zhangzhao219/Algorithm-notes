#include <bits/stdc++.h>
using namespace std;
int m,n,k;
int main(void){
    scanf("%d %d %d",&m,&n,&k);
    int a = 0;
    int b = 0;
    for(int i=0;i<k;i++){
        a++;
        b++;
        if(a == m+1){
            a = 1;
        }
        if(b == n+1){
            b = 1;
        }
        printf("%d %d\n",a,b);
    }
    return 0;
}