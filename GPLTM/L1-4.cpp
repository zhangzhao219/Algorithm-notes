#include <bits/stdc++.h>
using namespace std;
int main(void){
    int x;
    scanf("%d",&x);
    while(x--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(a*a + b*b + c*c == 3*a*b*c){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}