#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    if(n <= 1){
        return false;
    }
    for(int i=2;i<=sqrt(n);i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
bool hashTable[100010];
int main(void){
    memset(hashTable,0,sizeof(hashTable));
    int M,N;
    scanf("%d %d",&M,&N);
    while(!isPrime(M)){
        M++;
    }
    for(int i=0;i<N;i++){
        int temp;
        scanf("%d",&temp);
        int num = 0;
        int sign = 0;
        while(hashTable[temp%M] == true){
            if(num > M){
                sign = 1;
                break;
            }
            num++;
            temp = (temp + num * num - (num-1) * (num-1)) % M;
        }
        if(sign == 1){
            printf("-");
        }
        else{
            printf("%d",temp%M);
            hashTable[temp%M] = true;
        }
        if(i != N-1){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}