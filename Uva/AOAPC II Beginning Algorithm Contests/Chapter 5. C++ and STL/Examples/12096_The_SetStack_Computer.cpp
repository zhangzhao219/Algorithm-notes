#include <bits/stdc++.h>
using namespace std;
map<set<int>,int> IDcache;
vector<set<int> > Setcache;
int ID(set<int> x){
    if(IDcache.count(x)){
        return IDcache[x];
    }
    Setcache.push_back(x);
    return IDcache[x] = Setcache.size() - 1;
}
int main(void){
    int t;
    cin >> t;
    while(t--){
        stack<int> s;
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            string op;
            cin >> op;
            if(op[0] == 'P'){
                s.push(ID(set<int>()));
            }
            else if(op[0] == 'D'){
                s.push(s.top());
            }
            else{
                set<int> x1 = Setcache[s.top()];
                s.pop();            
                set<int> x2 = Setcache[s.top()];
                s.pop();
                set<int> x;
                if(op[0] == 'U'){
                    set_union(x1.begin(),x1.end(),x2.begin(),x2.end(),inserter(x,x.begin()));
                }
                if(op[0] == 'I'){
                    set_intersection(x1.begin(),x1.end(),x2.begin(),x2.end(),inserter(x,x.begin()));
                }
                if(op[0] == 'A'){
                    x = x2;
                    x.insert(ID(x1));
                }
                s.push(ID(x));
            }
            cout << Setcache[s.top()].size() << endl;
        }
        cout << "***" << endl;
    }
    return 0;
}
/*
2
9
PUSH
DUP
ADD
PUSH
ADD
DUP
ADD
DUP
UNION
5
PUSH
PUSH
ADD
PUSH
INTERSECT
*/
