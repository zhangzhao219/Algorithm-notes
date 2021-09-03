#include<stdio.h>
#include<iostream>
using namespace std;
int sum;
int d[200001];
int main(void){
    cin >> sum;
    for(int i=0;i<sum;i++){
        cin >> d[i];
    }
    int maxv = -2000000000;
    int minv = d[0];
    for(int i=1;i<sum;i++){
        maxv = max(maxv,d[i] - minv);
        minv = min(minv,d[i]);
    }
    cout << maxv << endl;
    return 0;
}