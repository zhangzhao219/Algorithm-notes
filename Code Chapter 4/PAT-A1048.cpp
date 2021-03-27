#include <bits/stdc++.h>
using namespace std;
int hashTable[510];
int main(void){
    memset(hashTable,0,sizeof(hashTable));
    int N,M;
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        int temp;
        scanf("%d",&temp);
        hashTable[temp]++;
    }
    for(int i=0;i<=500;i++){
        if(hashTable[i] > 0 && hashTable[M-i] > 0){
            if(M == 2 * i){
                if(hashTable[i] >= 2){
                    printf("%d %d\n",i,M-i);
                    return 0;
                }
            }
            else{
                printf("%d %d\n",i,M-i);
                return 0;
            }
        }
    }
    printf("No Solution");
    return 0;
}