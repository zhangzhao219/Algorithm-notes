#include <bits/stdc++.h>
using namespace std;
char s[101][260];
int sum;
int main(void){
    scanf("%d",&sum);
    getchar();
    int minlen = 270;
    for(int i=0;i<sum;i++){
        fgets(s[i],260,stdin);
        int j = 0;
        while(s[i][j]!='\n') 
            j++;
        s[i][j]='\0';
        int len = strlen(s[i]);
        minlen = min(minlen,len);
        for(int j=0;j<len/2;j++){
            char temp = s[i][j];
            s[i][j] = s[i][len - j - 1];
            s[i][len - j - 1] = temp;
        }
    }
    int sign = 0;
    for(int i=0;i<minlen;i++){
        int same = 1;
        char temp = s[0][i];
        for(int j=1;j<sum;j++){
            if(s[j][i] != temp){
                same = 0;
                break;
                
            }
        }
        if(same == 0){
            break;
        }
        else{
            sign++;
        }
    }
    if(sign == 0){
        printf("nai");
    }
    else{
        for(int i=sign-1;i >= 0;i--){
            printf("%c",s[0][i]);
        }
    }
}