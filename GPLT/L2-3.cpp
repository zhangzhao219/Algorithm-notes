#include <bits/stdc++.h>
using namespace std;
int N,M;
struct node{
    int count;
    string s;
}Node[10010];
map<string,int> mp;

bool cmp(node a,node b){
    if(a.count != b.count){
        return a.count > b.count;
    }
    return a.s < b.s;
}

int main(void){
    freopen("./test.in","r",stdin);
    scanf("%d %d",&N,&M);
    getchar();
    string s;
    for(int i=0;i<N;i++){
        getline(cin,s);
        if(mp.find(s) == mp.end()){
            mp[s] = 1;
        }
        else{
            mp[s]++;
        }
    }
    map<string,int>::iterator it;
    int index = 0;
    for(it=mp.begin();it != mp.end();it++){
        Node[index].count = it->second;
        Node[index].s = it->first;
        index++;
    }
    sort(Node,Node + index,cmp);
    cout << index << endl;
    for(int i=0;i<index;i++){
        cout << Node[i].count << " " << Node[i].s << endl;
    }
    return 0;
}