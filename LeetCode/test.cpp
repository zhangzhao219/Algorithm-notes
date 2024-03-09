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
    
    for(int i=0;i<n;i++){
        cout << "1" << endl;
        cout << edges[i][0] << " " << edges[i][1] << endl;
        join(edges[i][0], edges[i][1]);
        cout << edges[i][0] << " " << edges[i][1] << endl;
    }
    cout << "2" << endl;
    if(findfather(source) == findfather(destination)){
        return true;
    }
    return false;
}

int main(){
    vector<vector<int> > a = {
        {0,1},
        {0,2},
        {3,5},
        {5,4},
        {4,3},
    };
    cout << validPath(6,a,0,5) << endl;
}