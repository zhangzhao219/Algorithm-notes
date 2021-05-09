#include <bits/stdc++.h>
using namespace std;
char matrix[310][310];
int N;
int T;
int main(void){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf("%s",matrix[i]);
        }
        int M;
        scanf("%d",&M);
        int sign = 0;
        while(M--){
            getchar();
            char c;
            scanf("%c",&c);
            if(c == 'P'){
                int t1,t2;
                scanf("%d %d",&t1,&t2);
                if(sign == 0){
                    printf("%c\n",matrix[t1-1][t2-1]);
                }
                else if(sign == 1){
                    printf("%c\n",matrix[t2-1][N-t1]);
                }
                else if(sign == 2){
                    printf("%c\n",matrix[N-t1][N-t2]);
                }
                else{
                    printf("%c\n",matrix[N-t2][t1-1]);
                }
            }
            else{
                sign++;
                sign = sign % 4;
            }
            
        }
        printf("\n");
    }
    return 0;
}