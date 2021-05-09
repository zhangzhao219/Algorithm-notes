#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000010;

int prime[maxn];
int pnum = 0;

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

struct factor{
    int x;
    int cnt;
}Factor[1000];

int N;

int main(void){
    Find_Prime();
    long long n,num = 0;
    scanf("%d",&N);
    while(N--){
        scanf("%lld",&n);
        long long b = (long long)sqrt(1.0*n);
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
        long long result = 1;
        for(int i=0;i<num;i++){
            // printf("%d %d\n",Factor[i].x,Factor[i].cnt);
            while(Factor[i].cnt >= 3){
                result *= Factor[i].x;
                Factor[i].cnt -= 3;
            }
        }
        printf("%d\n",result);
    }
    return 0;
}