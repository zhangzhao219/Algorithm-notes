#include <bits/stdc++.h>
int main(void){
    char sorigin[100010];
    scanf("%s",sorigin);
    int len = strlen(sorigin);
    if(sorigin[0] == '-'){
        printf("-");
    }
    char signal;
    int i;
    for(i=0;i<len;i++){
        if(sorigin[i] == 'E'){
            signal = sorigin[i+1];
            i++;
            break;
        }
    }
    int num = 0;
    i++;
    for(;i<len;i++){
        num = num * 10 + (sorigin[i] - '0');
    }
    if(signal == '-'){
        printf("0.");
        for(int j=0;j<num-1;j++){
            printf("0");
        }
        for(int j=1;j<len;j++){
            if(sorigin[j] == 'E'){
                break;
            }
            if(sorigin[j] != '.'){
                printf("%c",sorigin[j]);
            }
        }
    }
    else{
        int count = -1;
        int actual = 0;
        int sign;
        for(int j=1;sorigin[j] != 'E';j++){
            if(sorigin[j] == '.'){
                sign = 1;
            }
            else{
                actual++;
            }
            if(sign == 1){
                count++;
            }
        }
        count -= 1;
        if(count == num){
            for(int j=1;sorigin[j] != 'E';j++){
                if(sorigin[j] == '.'){
                    continue;
                }
                printf("%c",sorigin[j]);
            }
        }
        else if(count < num){
            for(int j=1;sorigin[j] != 'E';j++){
                if(sorigin[j] == '.'){
                    continue;
                }
                printf("%c",sorigin[j]);
            }
            for(int j=0;j<num-count;j++){
                printf("0");
            }
        }
        else{
            int sign = 0;
            int count2 = 0;
            for(int j=1;sorigin[j] != 'E';j++){
                if(sorigin[j] == '.'){
                    sign = 1;
                    continue;
                }
                printf("%c",sorigin[j]);
                if(sign == 1){
                    count2++;
                    if(num == count2){
                        printf(".");
                    }
                }
            }
        }
    }
    return 0;
}