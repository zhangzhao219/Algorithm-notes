#include <bits/stdc++.h>
using namespace std;
int main(void){
    char c;
    int sign = 1;
    while((c=getchar()) != EOF){
        if(c == '"'){
            if(sign == 1){
                printf("%s","``");
            }
            else{
                printf("%s","''");
            }
            sign = -sign;
        }
        else{
            printf("%c",c);
        }
    }
    return 0;
}
