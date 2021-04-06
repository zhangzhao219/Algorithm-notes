#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;
    string s;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        cin >> s;
        if(s[0] - '0' + s[1] - '0' + s[2] - '0' == s[3] - '0' + s[4] - '0' + s[5] - '0'){
            printf("You are lucky!\n");
        }
        else{
            printf("Wish you good luck.\n");
        }
    }
    return 0;
}