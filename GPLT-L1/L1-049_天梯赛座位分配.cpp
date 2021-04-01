#include <bits/stdc++.h>
using namespace std;
int num[110];
int a[10010];
int N;

int main(void){
    scanf("%d",&N);
    int sum = 0;
    for(int i=1;i<=N;i++){
        scanf("%d",&num[i]);
        num[i] *= 10;
        sum += num[i];
    }
    for(int i=1;i<=10010;){
        int sign = 0;
        for(int k=1;k<=N;k++){
            if(num[k] != 0){
                sign = 1;
                a[i] = k;
                i++;
                num[k]--;
            }
        }
        if(sign == 0){
            break;
        }
    }
    for(int i=1;i<=N;i++){
        printf("#%d\n",i);
        int count1 = 0;
        int count2 = 0;
        for(int j=1;j<=sum;j++){
            if(a[j] == i){
                if(a[j+1] == i || (j == sum && a[j-1] == i)){
                    printf("%d",j+count2);
                    count2++;
                }
                else{
                    printf("%d",j);
                }
                count1++;
                if(count1 % 10 != 0){
                    printf(" ");
                }
                else{
                    printf("\n");
                }
            }
            
        }
    }
    return 0;
}