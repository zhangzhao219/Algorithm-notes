#include <bits/stdc++.h>
using namespace std;

double binarysearch(double x, double threshold){
    double left = 0;
    double right = x+1;
    while(right - left >= threshold){
        double mid = (left + right) / 2.0;
        if(mid * mid < x){
            left = mid;
        } else{
            right = mid;
        }
    }
    return left;
}

double gdtosqrt(double x, double threshold){
    // y^2 = x -> x - y^2 = 0
    // min (x - y^2)^2
    // x^2 - 2 * x * y^2 + y^4
    // -4*x * y + 4 * y ^ 3 

    double now = x;
    double pre = x + threshold + 1;
    double lr = 0.0001;
    while(abs(now-pre) >= threshold){
        pre = now;
        now = now - lr * (-4 * x * now + 4 * now * now * now);
    }
    return now;
}

int main(){
    double a = 0.1;
    double res = binarysearch(a, 0.0000001);
    cout << res << endl;
    double res2 = gdtosqrt(a, 0.0000001);
    cout << res2 << endl;
    return 0;
}