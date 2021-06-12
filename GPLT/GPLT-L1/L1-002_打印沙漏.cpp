#include <bits/stdc++.h>
using namespace std;
int sum;
char c;
int main(void){
    scanf("%d %c",&sum,&c);
    int num = 1;
    int i;
    for(i=1;;){
        i += 2;
        if(num + 2 * i > sum){
            i -= 2;
            break;
        }
        num  = num + 2 * i;
    }
    for(int j=0;j<i;j++){
        for(int k=0;k< i/2 - abs(j-i/2);k++){
            printf(" ");
        }
        for(int k=0;k< 2 * abs(j-i/2) + 1;k++){
            printf("%c",c);
        }
        printf("\n");
    }
    printf("%d\n",sum-num);
    
}