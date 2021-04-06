#include <bits/stdc++.h>
using namespace std;
int main(void){
    double a,b;
    scanf("%lf %lf",&a,&b);
    printf("%.1f\n",a / pow(b,2));
    if(a / pow(b,2) > 25){
        printf("PANG");
    }
    else{
        printf("Hai Xing");
    }
    return 0;
}