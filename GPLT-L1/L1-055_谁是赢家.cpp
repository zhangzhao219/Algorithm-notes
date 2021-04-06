#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a,b,c,d,e;
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    if(a > b && c+d+e < 3){
        printf("The winner is a: %d + %d",a,3 - (c+d+e));
    }
    else if(a < b && c+d+e == 0){
        printf("The winner is a: %d + %d",a,3 - (c+d+e));
    }
    else if(a < b && c+d+e > 0){
        printf("The winner is b: %d + %d",b,c+d+e);
    }
    else if(a > b && c+d+e == 3){
        printf("The winner is b: %d + %d",b,c+d+e);
    }
    return 0;
}