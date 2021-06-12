#include <bits/stdc++.h>
using namespace std;
int N;
int num[1000010];
int main(void){
    freopen("./test.in","r",stdin);
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&num[i]);
    }
    sort(num,num+N);
    int minn = num[0];
    int count1 = 1;
    for(int i=1;i<N;i++){
        if(num[i] == minn){
            count1++;
        }
        else{
            break;
        }
    }
    int maxn = num[N-1];
    int count2 = 1;
    for(int i=N-2;i>=0;i--){
        if(num[i] == maxn){
            count2++;
        }
        else{
            break;
        }
    }
    printf("%d %d\n%d %d",minn,count1,maxn,count2);
    return 0;
}