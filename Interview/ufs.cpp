#include <bits/stdc++.h>
using namespace std;

vector<int> father;

int findfather(int a){
    if(a == father[a]){
        return a;
    }
    return father[a] = findfather(father[a]);
}
void join(int a, int b){
    a = findfather(a);
    b = findfather(b);
    if(a == b){
        return;
    }
    father[a] = b;
}
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    for(int i=0;i<n;i++){
        father.push_back(i);
    }
    for(int i=0;i<edges.size();i++){
        join(edges[i][0], edges[i][1]);
    }
    if(findfather(source) == findfather(destination)){
        return true;
    }
    return false;
}