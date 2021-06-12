#include <bits/stdc++.h>
using namespace std;

int main(void){
    char s1[82];
    char s2[82];
    bool num[128];
    memset(num,false,sizeof(num));
    scanf("%s",s1);
    scanf("%s",s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for(int i=0;i<len1;i++){
        int j;
        char c1,c2;
        for(j=0;j<len2;j++){
            c1 = s1[i];
            c2 = s2[j];
            if(c1 >= 'a' && c1 <= 'z'){
                c1 -= 32;
            }
            if(c2 >= 'a' && c2 <= 'z'){
                c2 -= 32;
            }
            if(c1 == c2){
                break;
            }
        }
        if(j == len2 && num[c1] == false){
            printf("%c",c1);
            num[c1] = true;
        }
    }
    return 0;
}