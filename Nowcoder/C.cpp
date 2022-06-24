#include <bits/stdc++.h>
using namespace std;
int n;

int t[300010];
int h[300010];
int d[300010];

int main(void){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&t[i],&h[i],&d[i]);
    }
    for(int i=1;i<=n;i++){
        int count1 = 0;
        for(int j=t[i];j >= t[i]-d[i];j--){
            if(j < 1){
                break;
            }
            
        }
    }
    return 0;
}