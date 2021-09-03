#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int judge(int a){
    if(a%7 == 0){
        return 0;
    }
    else{
        char s[10000];
        itoa(a,s,10);
        for(int i=0;i<strlen(s);i++){
            if(s[i] == '7'){
                return 0;
            }
        }
    }
    return 1;
}
int main(void){
    int total;
    scanf("%d",&total);
    int a=0,b=0,c=0,d=0;
    for(int i=1;i <= total;i++){
        if(judge(i) == 0){
            // printf("%d\n",i);
            if(i % 4 == 0){
                d++;
            }
            else if(i % 4 == 1){
                a++;
            }
            else if(i % 4 == 2){
                b++;
            }
            else if (i % 4 == 3){
                c++;
                // printf("%d\n",i);
            }
            total++;
        }
    }
    printf("%d\n%d\n%d\n%d\n",a,b,c,d);
    return 0;
}