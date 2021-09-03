#include<bits/stdc++.h>
using namespace std;
int sum = 0;
int main(void){
    int n;
    int flag = 1;
    while(1){
        scanf("%d",&n);
        if(n == 0){
            printf("%d\n",sum);
            return 0;
        }
        if(flag != 1 && n == 2){
            flag += 2;
            sum += flag;
        }
        else{
            flag = n;
            sum += n;
        }

    }
}