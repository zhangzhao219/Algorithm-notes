#include <bits/stdc++.h>
using namespace std;
int main(void){
    int g1,s1,k1,g2,s2,k2;
    scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
    g1 += g2;
    k1 += k2;
    s1 += s2;
    if(k1 >= 29){
        s1 += k1 / 29;
        k1 = k1 % 29;
    }
    if(s1 >= 17){
        g1 += s1 / 17;
        s1 = s1 % 17;
    }
    printf("%d.%d.%d",g1,s1,k1);
}