#include<stdio.h>
#include<iostream>
#include<vector>    
using namespace std;
int sum;
int d[1000010];
int num = 0;
vector<int> G;
int main(void){
    cin >> sum;
    for(int i=0;i<sum;i++){
        cin >> d[i];
    }
    for(int h=1;h<sum;h = 3 * h + 1){
        G.push_back(h);
    }
    cout << G.size() << endl;
    for(int z = G.size() - 1;z>=0;z--){
        int y = G[z];
        cout << y;
        if(z == 0){
            cout << endl;
        }
        else{
            cout << " ";
        }
        int key;
        for(int i=y;i<sum;i++){
            key = d[i];
            int j = i-y;
            while(j >= 0 && d[j] > key){
                d[j+y] = d[j];
                j -= y;
                num++;
            }
            d[j+y] = key;
        }
    }
    cout << num << endl;
    for(int k=0;k<sum;k++){
        cout << d[k] << endl;
    }

    return 0;
}