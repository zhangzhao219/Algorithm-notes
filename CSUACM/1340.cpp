#include <bits/stdc++.h>
using namespace std;
int N;
bool judge(string s){
    for(int i=0;i<s.size();i++){
        if(s[i] == '7'){
            return true;
        }
    }
    return false;
}
int main(void){
    scanf("%d",&N);
    string s;
    while(N--){
        cin >> s;
        if(judge(s)){
            printf("Lucky\n");
        }
        else{
            printf("Unlucky\n");
        }
    }
    return 0;
}