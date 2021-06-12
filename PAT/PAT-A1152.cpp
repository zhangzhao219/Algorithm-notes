#include <bits/stdc++.h>
using namespace std;
bool isprime(int x){
    if(x == 0 || x == 1){
        return false;
    }
    for(int i=2;i<=sqrt(x);i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}
int L,K;
int main(void){
    scanf("%d %d",&L,&K);
    string s;
    cin >> s;
    for(int i=0;i<=L - K;i++){
        if(isprime(stoi(s.substr(i,K)))){
            cout << s.substr(i,K) << endl;
            return 0;
        }
    }
    cout << "404" << endl;
    return 0;
}