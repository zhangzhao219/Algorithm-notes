#include <bits/stdc++.h>
using namespace std;
struct Ret{
    long int up;
    long int down;
}ret[110];

long int gcd(long int a,long int b){
    if(b == 0){
        return a;
    }
    return gcd(b,a%b);
}

long int lcm(long int a,long int b){
    return a / gcd(a,b) * b;
}
Ret reduction(long int finalup,long int finaldown){
    Ret temp;
    if(finalup == 0){
        temp.up = 0;
        temp.down = 1;
    }
    else{
        long tempgcd = gcd(finalup,finaldown);
        temp.up = finalup / tempgcd;
        temp.down = finaldown / tempgcd;
    }
    return temp;
}

Ret add(Ret a,Ret b){
    long int finaldown = lcm(a.down,b.down);
    long int finalup = finaldown / a.down * a.up + finaldown / b.down * b.up;
    return reduction(finalup,finaldown);
}

void Print(Ret a){
    if(a.up == 0){
        printf("0");
    }
    else if(a.down == 1){
        printf("%d",a.up);
    }
    else if(abs(a.up) > a.down){
        if(a.up < 0){
            printf("-");
        }
        a.up = abs(a.up);
        printf("%d ",a.up / a.down);
        a.up = a.up - a.down * (a.up / a.down);
        printf("%d/%d",a.up,a.down);
    }
    else{
        printf("%d/%d",a.up,a.down);
    }
}
int main(void){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%ld/%ld",&ret[i].up,&ret[i].down);
    }
    for(int i=1;i<N;i++){
        ret[0] = add(ret[0],ret[i]);
    }
    Print(ret[0]);
    return 0;
}