#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    double w,p,v2,s=0;
    scanf("%lf%lf",&w,&p);
    v2=2*1000*100/w;
    while(v2>0.000001){
        s+=v2/9.8;
        v2*=1-p/100;
    }
    printf("%.3f\n",s);
    return 0;
}