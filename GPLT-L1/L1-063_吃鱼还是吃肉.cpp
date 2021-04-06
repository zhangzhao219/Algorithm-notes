#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;
    scanf("%d",&N);
    int t1,t2,t3;
    for(int i=0;i<N;i++){
        scanf("%d %d %d",&t1,&t2,&t3);
        int shengao,tizhong;
        if(t1 == 0){
            shengao = 129;
            tizhong = 25;
        }
        else{
            shengao = 130;
            tizhong = 27;
        }
        if(t2 < shengao){
            printf("duo chi yu! ");
        }
        else if(t2 == shengao){
            printf("wan mei! ");
        }
        else{
            printf("ni li hai! ");
        }
        if(t3 < tizhong){
            printf("duo chi rou!\n");
        }
        else if(t3 == tizhong){
            printf("wan mei!\n");
        }
        else{
            printf("shao chi rou!\n");
        }
    }
    return 0;
}