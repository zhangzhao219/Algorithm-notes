#include <bits/stdc++.h>
using namespace std;
int a[24];
int main(void){
    for(int i=0;i<24;i++){
        scanf("%d",&a[i]);
    }
    int temp;
    while(1){
        scanf("%d",&temp);
        if(temp < 0 || temp > 23){
            return 0;
        }
        else{
            printf("%d ",a[temp]);
            if(a[temp] > 50){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
    }
    return 0;
}