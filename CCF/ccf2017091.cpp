#include<bits/stdc++.h>
using namespace std;
int sum;
int main(void){
    scanf("%d",&sum);
    int count = 0;
    count += sum/50 * 7;
    sum -= sum / 50 * 50;
    count += sum / 30 * 4;
    sum -= sum / 30 * 30;
    count += sum / 10;
    printf("%d",count);
    return 0;
}