#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int sum;
int d[110];
int main(void){
    cin >> sum;
    for(int i=0;i<sum;i++){
        cin >> d[i];
    }
    int num = 0;
    for(int i=0;i<sum-1;i++){
        for(int j=0;j<sum-i-1;j++){
            if(d[j] > d[j+1]){
                swap(d[j],d[j+1]);
                num++;
            }
        }
    }
    for(int k=0;k<sum;k++){
        cout << d[k];
        if(k == sum-1){
            cout << endl;
        }
        else{
            cout << " ";
        }
    }
    cout << num << endl;
    return 0;
}