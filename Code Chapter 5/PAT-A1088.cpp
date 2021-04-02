#include <bits/stdc++.h>
using namespace std;
struct Ret{
    long int up;
    long int down;
}ret[2];

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
    if(temp.down < 0){
        temp.up = -temp.up;
        temp.down = -temp.down;
    }
    return temp;
}

Ret add(Ret a,Ret b){
    long int finaldown = lcm(a.down,b.down);
    long int finalup = finaldown / a.down * a.up + finaldown / b.down * b.up;
    
    return reduction(finalup,finaldown);
}

Ret minuss(Ret a,Ret b){
    long int finaldown = lcm(a.down,b.down);
    long int finalup = finaldown / a.down * a.up - finaldown / b.down * b.up;
    
    return reduction(finalup,finaldown);
}

Ret mul(Ret a,Ret b){
    long int finaldown = a.down * b.down;
    long int finalup = a.up * b.up;
    
    return reduction(finalup,finaldown);
}

Ret chu(Ret a,Ret b){
    if(b.up == 0){
        Ret temp;
        temp.up = 0;
        temp.down = 0;
        return temp;
    }
    else{
        long int finaldown = a.down * b.up;
        long int finalup = a.up * b.down;
        return reduction(finalup,finaldown);
    } 
}

void Print(Ret a){
    if(a.up == 0 && a.down == 0){
        printf("Inf");
    }
    else{
        a = reduction(a.up,a.down);
        int sign = 0;
        if(a.up < 0){
            printf("(");
            sign = 1;
        }
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
        if(sign == 1){
            printf(")");
        }
    } 
}
int main(void){
    scanf("%ld/%ld %ld/%ld",&ret[0].up,&ret[0].down,&ret[1].up,&ret[1].down);
    Print(ret[0]);
    printf(" + ");
    Print(ret[1]);
    printf(" = ");
    Print(add(ret[0],ret[1]));
    printf("\n");

    Print(ret[0]);
    printf(" - ");
    Print(ret[1]);
    printf(" = ");
    Print(minuss(ret[0],ret[1]));
    printf("\n");

    Print(ret[0]);
    printf(" * ");
    Print(ret[1]);
    printf(" = ");
    Print(mul(ret[0],ret[1]));
    printf("\n");

    Print(ret[0]);
    printf(" / ");
    Print(ret[1]);
    printf(" = ");
    Print(chu(ret[0],ret[1]));
    printf("\n");
    return 0;
}