#include <bits/stdc++.h>
using namespace std;
// 通过 λ的平方 - (a11 + a22) * λ = a12a21 - a11a22 进行计算
// 在-1到1的区间内进行二分计算
int main(void){
    double a11;
    double a12;
    double a21;
    double a22;
    scanf("%lf %lf %lf %lf",&a11,&a12,&a21,&a22);
    double left = -1.0;
    double right = 1.0;
    double t1 = a11 + a22;
    double t2 = a12 * a21 - a11 * a22;
    // 既然只有一个特征值，因此一定在-1到1的区间内是单调的，计算对称轴，决定哪一边更大
    double duichenzhou = t1 / 2.0;
    // 二分计算，精确到5位小数
    while(right - left > 0.00001){
        double mid = (right + left) / 2.0;
        if(duichenzhou >= 1.0){
            if(mid * mid - mid * t1 < t2){
                right = mid;
            }
            else if(mid * mid - mid * t1 > t2){
                left = mid;
            }
            else{
                break; // 正好相等
            }
        }
        else{
            if(mid * mid - mid * t1 > t2){
                right = mid;
            }
            else if(mid * mid - mid * t1 < t2){
                left = mid;
            }
            else{
                break; // 正好相等
            }
        }
    }
    printf("%.4f\n",left);
    return 0;
}