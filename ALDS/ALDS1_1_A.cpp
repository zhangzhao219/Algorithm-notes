#include<stdio.h>
#include<iostream>
using namespace std;
int sum;
int d[110];
int main(void){
    cin >> sum;
    for(int i=0;i<sum;i++){
        cin >> d[i];
        cout << d[i];
        if(i == sum-1){
            cout << endl;
        }
        else{
            cout << " ";
        }
    }
    int key;
    for(int i=1;i<sum;i++){
        key = d[i];
        int j = i-1;
        while(j >= 0 && d[j] > key){
            d[j+1] = d[j];
            j--;
        }
        d[j+1] = key;
        for(int k=0;k<sum;k++){
            cout << d[k];
            if(k == sum-1){
                cout << endl;
            }
            else{
                cout << " ";
            }
        }
    }
    return 0;
}