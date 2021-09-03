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

    int mini = 0;
    for(int i=0;i<sum-1;i++){
        mini = i;
        for(int j=i;j<sum;j++){
            if(d[j] < d[mini]){
                mini = j;
            }
        }
        if(mini != i){
            swap(d[i],d[mini]);
            num++;
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