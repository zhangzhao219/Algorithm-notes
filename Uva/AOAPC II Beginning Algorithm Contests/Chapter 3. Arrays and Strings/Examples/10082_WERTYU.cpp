#include <bits/stdc++.h>
using namespace std;
int main(void){
    char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    char c;
    while((c = getchar()) != EOF){
        int sign = 0;
        for(int i=0;i<strlen(s);i++){
            if(s[i] == c){
                sign = 1;
                printf("%c",s[i-1]);
                break;
            }
        }
        if(sign == 0){
            printf("%c",c);
        }
    }
    return 0;
}