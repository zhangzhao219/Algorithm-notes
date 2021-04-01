#include <bits/stdc++.h>
using namespace std;
struct Gas{
    double pi;
    double di;
}gas[600];
bool cmp(Gas a,Gas b){
    return a.di < b.di;
}
int main(void){
    double Cmax,D,Davg;
    int N;
    scanf("%lf %lf %lf %d",&Cmax,&D,&Davg,&N);
    for(int i=0;i<N;i++){
        scanf("%lf %lf",&gas[i].pi,&gas[i].di);
    }
    sort(gas,gas + N,cmp);
    // for(int i=0;i<N;i++){
    //     printf("%f %f\n",gas[i].pi,gas[i].di);
    // }
    double totaldistance = 0.0;
    int num = 0;
    double fullrun = Cmax * Davg;
    double price = 0.0;
    double havegas = 0.0;
    while(totaldistance < D){
        if(totaldistance != gas[num].di){
            break;
        }
        else{
            int mincost = gas[num].pi;
            int sign = num;
            for(int i=num;gas[i].di <= totaldistance + fullrun;i++){
                if(mincost > gas[i].pi){
                    mincost = gas[i].pi;
                    sign = i;
                    break;
                }
            }
            if(sign == num){
                price += fullrun * gas[num].pi;
                
            }
            else{
                price += gas[num].pi * (gas[sign].di - totaldistance);
                totaldistance = gas[sign].di;
                havegas = 0.0;
                num = sign;
            }
        }
    }
    if(totaldistance != D){
        printf("The maximum travel distance = %.2f\n",totaldistance);
    }
    else{
        printf("%.2f\n",price / Davg);
    }
    return 0;
}