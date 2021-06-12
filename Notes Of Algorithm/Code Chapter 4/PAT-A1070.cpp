#include <bits/stdc++.h>
using namespace std;
struct moon{
    double ton;
    double price;
    double danjia;
}Moon[1010];
bool cmp(moon a,moon b){
    return a.danjia > b.danjia;
}
int main(void){
    int N,D;
    scanf("%d %d",&N,&D);

    for(int i=0;i<N;i++){
        scanf("%lf",&Moon[i].ton);
    }
    for(int i=0;i<N;i++){
        scanf("%lf",&Moon[i].price);
        Moon[i].danjia = Moon[i].price / Moon[i].ton;
    }
    sort(Moon,Moon+N,cmp);
    double totalprice = 0.0;
    for(int i=0;i<N;i++){
        if(D - Moon[i].ton >= 0){
            D -= Moon[i].ton;
            totalprice += Moon[i].ton * Moon[i].danjia;
        }
        else{
            totalprice = totalprice + D * Moon[i].danjia;
            break;
        }
    }
    printf("%.2f",totalprice);
    return 0;
}