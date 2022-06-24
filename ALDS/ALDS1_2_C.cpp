#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct card{
    char kind;
    int value;
}d[40],c[40];
int sum;

int main(void){
    cin >> sum;
    for(int i=0;i<sum;i++){
        cin >> d[i].kind >> d[i].value;
        c[i].kind = d[i].kind;
        c[i].value = d[i].value;
    }

    for(int i=0;i<sum-1;i++){
        for(int j=0;j<sum-i-1;j++){
            if(c[j].value > c[j+1].value){
                swap(c[j].value,c[j+1].value);
                swap(c[j].kind,c[j+1].kind);
            }
        }
    }
    for(int k=0;k<sum;k++){
        cout << c[k].kind << c[k].value;
        if(k == sum-1){
            cout << endl << "Stable" << endl;
        }
        else{
            cout << " ";
        }
    }

    int mini = 0;
    for(int i=0;i<sum-1;i++){
        mini = i;
        for(int j=i;j<sum;j++){
            if(d[j].value < d[mini].value){
                mini = j;
            }
        }
        if(mini != i){
            swap(d[i],d[mini]);
        }
    }

    for(int k=0;k<sum;k++){
        cout << d[k].kind << d[k].value;
        if(k == sum-1){
            cout << endl;
        }
        else{
            cout << " ";
        }
    }

    for(int i=0;i<sum;i++){
        if(c[i].kind != d[i].kind || c[i].value != d[i].value){
            cout << "Not stable" << endl;
            return 0;
        }
    }
    cout << "Stable" << endl;
    return 0;
}