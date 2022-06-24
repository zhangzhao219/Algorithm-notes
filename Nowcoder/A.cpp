#include <bits/stdc++.h>
using namespace std;

int main(void){
    int k,a,b;
    scanf("%d %d %d",&k,&a,&b);
    
    if(k > 0 && a < b){
        printf("-1\n");
        return 0;
    }
    else if(k < 0 && a > b){
        printf("-1\n");
        return 0;
    }
    if(k > 0){
        if(a == b){
            if(a >= k){
                printf("1\n");
            }
            else{
                printf("-1\n");
            }
            return 0;
        }
        int step = abs(a-b);
        k = abs(k);
        int far = max(a,b);
        int count1 = 1;
        int num = 0;
        while(1){
            if(num + far >= k){
                printf("%d\n",count1);
                return 0;
            }
            num += step;
            count1++;
        }
    }
    else{
        k = -k;
        if(a == b){
            printf("-1\n");
            return 0;
        }
        int step = abs(a-b);
        int far = max(a,b);
        int count1 = 1;
        int num = 0;
        while(1){
            num += step;
            if(num >= k){
                printf("%d\n",count1);
                return 0;
            }
            count1++;
        }
    }
}