#include <bits/stdc++.h>
using namespace std;
int a[10];
int main(void){
    memset(a,0,sizeof(a));
    char N[1010];
    scanf("%s",N);
    int len = strlen(N);
    for(int i=0;i<len;i++){
        a[N[i] - '0'] += 1;
    }
    for(int i=0;i<10;i++){
        if(a[i] != 0){
            printf("%d:%d\n",i,a[i]);
        }
    }
    return 0;
}