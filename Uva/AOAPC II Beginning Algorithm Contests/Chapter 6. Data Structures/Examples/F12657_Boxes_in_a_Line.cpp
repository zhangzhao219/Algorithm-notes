#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int leftX[maxn];
int rightX[maxn];
void link(int L,int R){
    leftX[R] = L;
    rightX[L] = R;
}
int main(void){
    int base,k;
    while(scanf("%d %d",&base,&k) == 2){
        for(int i=1;i<=base-1;i++){
            leftX[i] = i-1;
            rightX[i] = i+1;
        }
        leftX[base] = base-1;
        rightX[base] = 0;
        leftX[0] = base;
        rightX[0] = 1;
        int inv = 0;
        int t1,X,Y;
        while(k--){
            scanf("%d",&t1);
            if(t1 == 4){
                inv = !inv;
            }
            else{
                scanf("%d %d",&X,&Y);
                if(t1 == 3 && rightX[Y] == X){

                }
                int LX = leftX[X];
                int RX = rightX[X];
                int LY = leftX[Y];
                int RY = rightX[Y];
                if(t1 == 1){

                }
                else if(t1 == 2){

                }
                else{

                }
            }
        }
    }
    return 0;
}
/*
6 4
1 1 4
2 3 5
3 1 6
4
6 3
1 1 4
2 3 5
3 1 6
100000 1
4
*/