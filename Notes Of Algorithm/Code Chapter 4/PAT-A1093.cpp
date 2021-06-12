#include <bits/stdc++.h>
using namespace std;
char s[100100];
int leftP[100100];
int rightA[100100];
int main(void){
    scanf("%s",s);
    int len = strlen(s);
    leftP[0] = 0;
    rightA[len] = 0; 
    for(int i=0;i<len;i++){
        if(s[i] == 'P'){
            leftP[i] = leftP[i-1] + 1;
        }
        else{
            leftP[i] = leftP[i-1];
        }
    }
    for(int i=len-1;i>=0;i--){
        if(s[i] == 'T'){
            rightA[i] = rightA[i+1] + 1;
        }
        else{
            rightA[i] = rightA[i+1];
        }
    }
    int ans = 0;
    for(int i=0;i<len;i++){
        if(s[i] == 'A'){
            ans = (ans + leftP[i] * rightA[i]) % 1000000007;
        }
    }
    printf("%d",ans);
    return 0;
}