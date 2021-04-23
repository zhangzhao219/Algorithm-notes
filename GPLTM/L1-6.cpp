#include <bits/stdc++.h>
using namespace std;
int deal(int x){
    int sum = 0;
    while(x){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
int main(void){
    int N;
    scanf("%d",&N);
    while(N--){
        int temp;
        scanf("%d",&temp);
        int b = 0;
        int sign = 1;
        for(int i=2;i<=9;i++){
            int c = deal(temp * i);
            if(b != 0 && c != b){
                sign = 0;
                printf("NO\n");
                break;
            }
            b = c;
        }
        if(sign == 1){
            printf("%d\n",deal(temp * 2));
        }
    }
    return 0;
}