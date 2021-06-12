#include <bits/stdc++.h>
using namespace std;
int main(void){
    int num;
    char c;
    scanf("%d %c",&num,&c);
    int times = int(round(double(num) / 2.0));
    for(int i=0;i<times;i++){
        if(i == 0 || i == times - 1){
            for(int j=0;j<num;j++){
                printf("%c",c);
            }
        }
        else{
            printf("%c",c);
            for(int j=0;j<num-2;j++){
                printf(" ");
            }
            printf("%c",c);
        }
        printf("\n");
    }
    
    return 0;
}