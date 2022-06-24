#include <bits/stdc++.h>
using namespace std;
int l;
int main(void){
    scanf("%d",&l);
    int D,I;
    for(int i=0;i<l;i++){
        scanf("%d",&D);
        if(D == -1){
            return 0;
        }
        scanf("%d",&I);
        int k = 1;
        for(int j=0;j<D-1;j++){
            if(I % 2 == 1){
                k = 2 * k;
                I = (I+1) / 2;
            }
            else{
                k = 2 * k + 1;
                I /= 2;
            }
        }
        printf("%d\n",k);
    }
}
/*
5
4 2
3 4
10 1
2 2
8 128
-1
*/