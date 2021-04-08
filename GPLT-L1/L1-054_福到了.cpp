#include <bits/stdc++.h>
using namespace std;
string s;
char a[110][110];
char b[110][110];
char ab;
int main(void){
    freopen("../test.in","r",stdin);
    int N;
    scanf("%c %d",&ab,&N);
    getchar();
    for(int i=0;i<N;i++){
        getline(cin,s);
        for(int j=0;j<s.size();j++){
            a[i][j] = s[j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            b[N-i-1][N-j-1] = a[i][j];
        }
    }

    int sign = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(a[i][j] != ' '){
                if(a[i][j] != b[i][j]){
                    sign = 1;
                    break;
                }
            }
        }
    }
    if(sign == 0){
        printf("bu yong dao le\n");
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(b[i][j] == ' '){
                printf(" ");
            }
            else{
                printf("%c",ab);
            }
        }
        printf("\n");
    }
    return 0;
}