#include <bits/stdc++.h>
using namespace std;
int price[5] = {1,2,4,8,16};
int num[5] = {10,23,49,109,227};
int main(void){
    int ans = 0;
    int n;
    scanf("%d",&n);
    for(int i=4;i>=0;i--){
        int t = n / price[i];
        ans += t * num[i];
        n -= price[i] * t;
    }
    printf("%d",ans);
    return 0;
}