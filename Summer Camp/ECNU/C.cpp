#include <bits/stdc++.h>
using namespace std;
int n,p;
double s;

struct Fraction{
    int up;
    int down;
};

struct node{
    double height;
    int index;
    int flag;
    int zheng;
    int up;
    int down;
}a[1010];

int gcd(int a,int b){
    if(b == 0){
        return a;
    }
    return gcd(b,a%b);
}
Fraction reduction(Fraction result){
    if(result.up == 0){
        result.down = 1;
    }
    else{
        int d = gcd(result.up,result.down);
        result.down /= d;
        result.up /= d;
    }
    return result;
}

Fraction add(Fraction a,Fraction b){
    Fraction result;
    result.down = a.down * b.down;
    result.up = a.up * b.down + b.up * a.down;
    return reduction(result);
}

bool cmp(node a,node b){
    return a.index < b.index;
}
bool cmp1(node a,node b){
    return a.height < b.height;
}

int main(void){
    scanf("%d %lf %d",&n,&s,&p);
    for(int i=1;i<=n;i++){
        scanf("%lf",&a[i].height);
        a[i].index = i;
        a[i].flag = 0;
    }
    sort(a+1,a+n+1,cmp1);
    Fraction re1;
    Fraction re2;
    while(s > 0){
        int count1 = 1;
        int flag;
        for(int i=1;i<=n-1;i++){
            if(a[i].height == a[i+1].height){
                count1++;
            }
            else{
                flag = i+1;
                break;
            }
        }
        if(count1 == n){
            re1.up = (int)a[1].height;
            re1.down = 1;
            re2.up = (int)s;
            re2.down = count1;
            re1 = add(re1,re2);
            
            int nu = re1.up / re1.down;
            re1.up = re1.up - re1.down * nu;
            for(int i=1;i<=flag;i++){
                a[i].flag = 1;
                a[i].zheng = nu;
                a[i].up = re1.up;
                a[i].down = re1.down;
            }
            break;
        }
        else if(s >= count1 * (a[flag].height - a[1].height)){
            s -= count1 * (a[flag].height - a[1].height);
            for(int i=1;i<flag;i++){
                a[i].height = a[flag].height;
            }
        }
        else{
            re1.up = (int)a[1].height;
            re1.down = 1;
            re2.up = (int)s;
            re2.down = count1;
            re1 = add(re1,re2);
            int nu = re1.up / re1.down;
            re1.up = re1.up - re1.down * nu;
            for(int i=1;i<flag;i++){
                a[i].flag = 1;
                a[i].zheng = nu;
                a[i].up = re1.up;
                a[i].down = re1.down;
            }
            break;
        }
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(a[i].flag == 0){
            printf("%.0f",a[i].height);
        }
        else{
            if(a[i].zheng != 0){
                printf("%d",a[i].zheng);
            }
            if(a[i].up != 0){
                printf("+%d/%d",a[i].up,a[i].down);
            }
        }
        if(i == n){
            printf("\n");
        }
        else{
            printf(" ");
        }
        
    }
    return 0;
}
/*
8 5 1
8 6 5 2 2 4 6 9
*/