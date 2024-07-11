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
    // 对y求导
    // -4*x * y + 4 * y ^ 3 

    double now = x;
    double pre = x + threshold*2;
    double lr = 0.00001;
    while(abs(now-pre) >= threshold){
        pre = now;
        now = now - lr * (-4 * x * now + 4 * now * now * now);
    }
    return now;
}

double gdtocube(double x, double threshold){
    // y^3 = x -> x - y^3 = 0
    // min (x - y^3)^2
    // x^2 - 2 * x * y^3 + y^6
    // 对y求导
    // -6*x * y^2 + 6 * y ^ 5

    double now = x;
    double pre = x + threshold*2;
    double lr = 0.00001;
    while(abs(now-pre) >= threshold){
        pre = now;
        now = now - lr * (-6 * x * now * now + 6 * now * now * now * now * now);
    }
    
    return now;
}

int main(){
    double a = 1;
    double threshold = 0.00000000001;
    double res = binarysearch(a, threshold);
    cout << res << endl;
    double res2 = gdtosqrt(a, threshold);
    cout << res2 << endl;
    double res3 = gdtocube(a, threshold);
    cout << res3 << endl;
    return 0;
}