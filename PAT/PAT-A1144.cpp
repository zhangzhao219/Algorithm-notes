#include <bits/stdc++.h>
using namespace std;
int main(void){
    freopen("./test.in","r",stdin);
    int N;
    cin >> N;
    map<int,int> mp;
    int temp;
    for(int i=0;i<N;i++){
        cin >> temp;
        mp[temp]++;
    }
    int num = 0;
    while(++num){
        if(mp[num] == 0){
            break;
        }
    }
    cout << num << endl;
    return 0;
}