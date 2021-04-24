#include <bits/stdc++.h>
using namespace std;
int N,M;
int main(void){
    freopen("./test.in","r",stdin);
    scanf("%d %d",&N,&M);
    getchar();
    int sign = 0;
    for(int i=0;i<N;i++){
        string s;
        getline(cin,s);
        // cout << s << endl;
        if(s.find("qiandao") == string::npos && s.find("easy") == string::npos){
            M--;
        }
        if(sign == 0){
            if(M == -1){
                cout << s << endl;
                sign = 1;
            }
        }
        
    }
    if(sign == 0){
        printf("Wo AK le\n");
    }
    
    return 0;
}