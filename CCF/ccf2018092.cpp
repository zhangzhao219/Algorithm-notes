#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000001];
int b[1000001];
int main(void){
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    int t1,t2;
    for(int i=0;i<n;i++){
        scanf("%d %d",&t1,&t2);
        for(int j=t1;j<t2;j++){
            a[j] = 1;
        }
    }
    for(int i=0;i<n;i++){
        scanf("%d %d",&t1,&t2);
        for(int j=t1;j<t2;j++){
            b[j] = 1;
        }
    }
    for(int i=0;i<1000001;i++){
        a[i] = a[i] * b[i];
    }
    int sum = 0;
    for(int i=0;i<1000001;i++){
        if(a[i] == 1){
            sum++;
        }
    }
    printf("%d",sum);
    return 0;
}