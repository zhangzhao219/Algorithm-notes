#include <bits/stdc++.h>
using namespace std;
int main(void){
    double a,b;
    int s;
    scanf("%lf %d %lf",&a,&s,&b);
    double ans = 0.0;
    if(s == 0){
        ans = a * 2.455;
    }
    else{
        ans = a * 1.26;
    }
    if(ans >b){
        printf("%.2f T_T",ans);
    }
    else{
        printf("%.2f ^_^",ans);
    }
    return 0;
}