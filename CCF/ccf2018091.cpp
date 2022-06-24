#include<bits/stdc++.h>
using namespace std;
int n;
int a[1010];
int b[1010];
int main(void){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    b[0] = (a[0] + a[1]) / 2;
    b[n-1] = (a[n-2] + a[n-1]) / 2;
    for(int i=1;i<n-1;i++){
        b[i] = (a[i-1] + a[i] + a[i+1]) / 3;
    }
    for(int i=0;i<n;i++){
        printf("%d ",b[i]);
    }
    return 0;
}