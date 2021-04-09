#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;
    scanf("%d",&N);
    string s;
    getchar();
    while(N--){
        getline(cin,s);
        int sign = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == ',' || s[i] == '.'){
                if((i-3) >= 0 && s[i-3] == 'o' && s[i-2] == 'n' && s[i-1] == 'g'){
                    sign++;
                }
            }
        }
        if(sign == 2){
            int num = 0;
            int i;
            for(i=s.size()-1;i>=0;i--){
                if(s[i] == ' '){
                    num++;
                }
                if(num == 3){
                    break;
                }
            }
            for(int j=0;j<i;j++){
                cout << s[j];
            }
            printf(" qiao ben zhong.\n");
        }
        else{
            cout << "Skipped" << endl;
        }
    }
    return 0;
}