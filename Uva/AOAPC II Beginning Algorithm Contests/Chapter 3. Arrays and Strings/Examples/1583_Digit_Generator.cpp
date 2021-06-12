#include <bits/stdc++.h>
using namespace std;
int num[100005];
int main(void){
    memset(num,0,sizeof(num));
    for(int i=100005;i>=0;i--){
        int t = 0;
        int x = i;
        while(x != 0){
            t += x % 10;
            x /= 10;
        }
        num[t+i] = i;
    }
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        printf("%d\n",num[t]);
    }
    return 0;
}