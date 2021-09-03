#include<bits/stdc++.h>
using namespace std;
int n;
int a[1010];
int main(void){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int sum = 10001;
    for(int i=0;i<n-1;i++){
        if(a[i+1] - a[i] == 0){
            printf("0");
            return 0;
        }
        if(a[i+1] - a[i] < sum){
            sum = a[i+1] - a[i];
        }
    }
    printf("%d",sum);
    return 0;
}