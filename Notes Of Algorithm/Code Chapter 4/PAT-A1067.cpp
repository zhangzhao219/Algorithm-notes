#include <bits/stdc++.h>
using namespace std;
int N;
int count1 = 0;
int a[100010];
int main(void){
    scanf("%d",&N);
    int left = N-1,num;
    for(int i=0;i<N;i++){
        scanf("%d",&num);
        a[num] = i;
        if(num == i && num != 0){
            left--;
        }
    }
    int k = 1;
    while(left > 0){
        if(a[0] == 0){
            while(k < N){
                if(a[k] != k){
                    swap(a[0],a[k]);
                    count1++;
                    break;
                }
                k++;
            }
        }
        while(a[0] != 0){
            swap(a[0],a[a[0]]);
            count1++;
            left--;
        }
    }
    printf("%d\n",count1);
    return 0;
}