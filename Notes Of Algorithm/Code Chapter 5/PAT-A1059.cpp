#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;

int prime[100010];
int pnum = 0;

// 普通判断质数
bool isPrime(int n){
    if(n == 1){
        return false;
    }
    for(int i=2;i<=(int)sqrt(1.0*n);i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
void Find_Prime(){
    for(int i=1;i<maxn;i++){
        if(isPrime(i) == true){
            prime[pnum++] = i;
        }
    }
}

// 埃氏筛法求质数表
void Find_Prime(){
    bool judge[100010];
    memset(judge,false,sizeof(judge));
    for(int i=2;i<=100010;i++){
        if(judge[i] == false){
            prime[pnum++] = i;
            for(int j=i+i;j<=100010;j += i){
                judge[j] = true;
            }
        }
    }
}

// 存储质数的结构
struct factor{
    int x; // 分解出的质数
    int cnt; // 分解出的质数次数
}Factor[10];

int main(void){
    Find_Prime();
    int n,num = 0;
    scanf("%d",&n);
    if(n == 1){
        printf("1=1");
    }
    else{
        printf("%d=",n);
        int b = (int)sqrt(1.0*n);
        for(int i=0;i<pnum && prime[i] <= b;i++){
            if(n % prime[i] == 0){
                Factor[num].x = prime[i];
                Factor[num].cnt = 0;
                while(n % prime[i] == 0){
                    Factor[num].cnt++;
                    n /= prime[i];
                }
                num++;
            }
            if(n == 1){
                break;
            }
        }
        if(n != 1){
            Factor[num].x = n;
            Factor[num++].cnt = 1;
        }

        for(int i=0;i<num;i++){
            if(i != 0){
                printf("*");
            }
            if(Factor[i].cnt == 1){
                printf("%d",Factor[i].x);
            }
            else{
                printf("%d^%d",Factor[i].x,Factor[i].cnt);
            }
        }
    }
    return 0;
}