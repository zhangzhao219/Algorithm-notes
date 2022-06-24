#include <bits/stdc++.h>
using namespace std;
int main(void){
    double num;
    scanf("%lf",&num);
    // x = 1/2(x + n/x)
    double x0,x1;
    x0 = num;
    x1 = 0.5 * (x0 + num / x0);
    while(abs(x1 - x0) >= 0.0001){
        x0 = x1;
        x1 = 0.5 * (x0 + num / x0);
    }
    printf("%f\n",x0);
    return 0;
}