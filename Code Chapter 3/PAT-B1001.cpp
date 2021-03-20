#include <bits/stdc++.h>
using namespace std;
int main(void){
    int sum = 0;
    int n;
    scanf("%d", &n);
    while (1){
        if (n == 1){
            printf("%d\n",sum);
            return 0;
        }
        if (n % 2 == 0){
            n /= 2;
        }
        else{
            n = (3 * n + 1) / 2;
        }
        sum++;
    }
}