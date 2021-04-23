#include <bits/stdc++.h>
using namespace std;
string add(string a,string b){
    int carry = 0;
    for(int i=a.size()-1;i>=0;i--){
        int t = a[i] - '0' + b[i] - '0' + carry;
        carry = t / 10;
        a[i] = t % 10 + '0';
    }
    if(carry == 1){
        a = "1" + a;
    }
    return a;
}
int main(void){
    string N;
    cin >> N;
    int count = 10;
    while(count--){
        string M = N;
        reverse(M.begin(),M.end());
        if(M == N){
            cout << M << " is a palindromic number." << endl;
            return 0;
        }
        else{
            cout << N << " + " << M << " = " << add(N,M) << endl;
            N = add(N,M);
        }
    }
    cout << "Not found in 10 iterations." << endl;
    return 0;
}