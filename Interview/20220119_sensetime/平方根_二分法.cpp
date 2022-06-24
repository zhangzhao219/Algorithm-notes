#include <bits/stdc++.h>
using namespace std;
int main(void){
    double num;
    scanf("%lf",&num);
    if(num == 0){
        printf("0\n");
        return 0;
    }
    double L = 0.0;
    double R = num+1.0;
    while(R - L > 0.0001){
        double mid = (L + R) / 2.0;
        if(mid * mid == num){
            printf("%f\n",mid);
            return 0;
        }
        else if(mid * mid < num){
            L = mid;
        }
        else{
            R = mid;
        }
    }
    printf("%f\n",L);
    return 0;
}