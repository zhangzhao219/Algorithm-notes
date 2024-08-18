// 有一个文件，每一行两个相似的query，找出这些集合里面所有相似query的子集
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
}

int main(){
    vector<vector<int> > queryset{
        {1,2},
        {3,4},
        {5,6},
        {1,4},
    };
    int n = 7;
    for(int i=0;i<n;i++){
        father.push_back(i);
    }
    for(int i=0;i<queryset.size();i++){
        join(queryset[i][0], queryset[i][1]);
    }
    // for(int i=0;i<n;i++){
    //     cout << findfather(i) << " ";
    // }
    // cout << endl;
    map<int, vector<int> > mp;
    for(int i=0;i<n;i++){
        mp[findfather(i)].push_back(i);
    }
    for(auto it=mp.begin();it != mp.end(); it++){
        // cout << it->first << endl;
        for(int i=0;i<it->second.size();i++){
            cout << it->second[i] << " ";
        }
        cout << endl;
    }
    return 0;
}