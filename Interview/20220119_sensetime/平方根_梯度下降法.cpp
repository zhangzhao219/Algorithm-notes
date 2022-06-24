#include <bits/stdc++.h>
using namespace std;
int main(void){
    double num;
    scanf("%lf",&num);
    double y1 = num;
    double lr = 0.001;
    double y0;
    while(abs(y1 * y1 - num) >= 0.0001){
        if(y1 * y1 > num){
            y0 = y1;
            y1 = y0 - lr * 2.0 * y0;
        }
        else if(y1 * y1 < num){
            y0 = y1;
            y1 = y0 + lr * 2.0 * y0;
        }
        else{
            break;
        }
    }
    printf("%f\n",y1);
    return 0;
}