#include <bits/stdc++.h>
using namespace std;
int father[100002];
int findfather(int x){
    if(x == father[x]){
        return x;
    }
    return father[x] = findfather(father[x]);
}
void join(int i, int j){
    int faA = findfather(i);
    int faB = findfather(j);
    if(faA == faB){
        return;
    }
    father[faA] = faB;
}

unordered_map<int, vector<int> > mp;

int main() {
    for(int i=2;i<1000002;i++){
        if(i <= 3){
            mp[i] = {};
        }
        if(i % 2 == 0 || i % 3 == 0){
            continue;
        } 
        bool sign = true;
        for(int j=2;j*j<=i;j++){
            if(i % j == 0){
                sign = false;
                break;
            }
        }
        if(sign){
            mp[i] = {};
        }
    }
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int t;
        cin >> t;
        for(int j=0;j<t;j++){
            int s;
            cin >> s;
            if(mp.find(s) != mp.end()){
                mp[s].push_back(i);
            }
        }
    }
    for(int i=1;i<=n;i++){
        father[i] = i;
    }
    for(auto it = mp.begin(); it != mp.end();it++){
        int y = it->second.size();
        if(y >= 2){
            for(int j=1;j<y;j++){
                join(it->second[0], it->second[j]);
            }
        }
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int a;
        int b;
        cin >> a >> b;
        if(findfather(a) == findfather(b)){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}


// 4
// 2 11 13
// 1 5
// 3 11 7 5
// 4 2 4 6 8
// 3
// 1 2
// 1 4
// 1 3

// YES
// NO
// YES