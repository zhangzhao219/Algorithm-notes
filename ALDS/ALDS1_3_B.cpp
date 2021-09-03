#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct node{
    char name[20];
    int time;
}Node[100010];

queue<node> qt;

int main(void){
    int n,q;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> Node[i].name >> Node[i].time;
        qt.push(Node[i]);
    }
    int totaltime = 0;
    while(!qt.empty()){
        node temp = qt.front();
        if(temp.time <= q){
            totaltime += temp.time;
            cout << temp.name << " " << totaltime << endl;
            qt.pop();
        }
        else{
            totaltime += q;
            temp.time -= q;
            qt.push(temp);
            qt.pop();
        }
    }
    return 0;
}
