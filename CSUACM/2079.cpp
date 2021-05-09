#include <bits/stdc++.h>
using namespace std;
int main(void){
    int T,N;
    scanf("%d",&T);
    double a,b,c;
    while(T--){
        scanf("%d",&N);
        double maxp = -1.0;
        while(N--){
            scanf("%lf %lf %lf",&a,&b,&c);
            double temp = sqrt(a*a+b*b+c*c);
            maxp = max(maxp,temp);
        }
        printf("%.2f\n",maxp);
    }
    return 0;
}