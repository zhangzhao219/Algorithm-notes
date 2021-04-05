#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;
    scanf("%d",&N);
    double temp;
    double sum = 0.0;
    for(int i=0;i<N;i++){
        scanf("%lf",&temp);
        sum += 1.0 / temp;
    }
    printf("%.2f\n",double(N) / sum);
}