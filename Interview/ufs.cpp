#include <bits/stdc++.h>
using namespace std;

vector<int> father;

int findfather(int x){
    if(x == father[x]){
        return x;
    }
    return father[x] = findfather(father[x]);
}

void join(int a, int b){
    int faA = findfather(a);
    int faB = findfather(b);
    if(faA != faB){
        father[faA] = faB;
    }
    return;
}

int main(){
    vector<vector<int> > edges = {
        {0,1},
        {2,3},
        {4,5},
        {6,7},
        {1,7},
    };
    int total = 8;
    for(int i=0;i<total;i++){
        father.push_back(i);
    }
    for(int i=0;i<edges.size();i++){
        int x = edges[i][0];
        int y = edges[i][1];
        join(x,y);
    }
    for(int i=0;i<total;i++){
        cout << findfather(i) << " ";
    }
    cout << endl;
}