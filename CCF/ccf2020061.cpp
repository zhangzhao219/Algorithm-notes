#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

struct node{
    int x;
    int y;
    char k;
}Node[1010];

int n,m;

int main(void){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> Node[i].x >> Node[i].y >> Node[i].k;
    }
    for(int i=0;i<m;i++){
        int t1,t2,t3;
        cin >> t1 >> t2 >> t3;
        set<char> s1;
        set<char> s2;
        for(int j=0;j<n;j++){
            if(t1 + Node[j].x * t2 + Node[j].y * t3 > 0){
                s1.insert(Node[j].k);
            }
            else{
                s2.insert(Node[j].k);
            }
        }
        if(s1.size() == 1 && s2.size() == 1){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}
/*
9 3
1 1 A
1 0 A
1 -1 A
2 2 B
2 3 B
0 1 A
3 1 B
1 3 B
2 0 A
0 2 -3
-3 0 2
-3 1 1
*/