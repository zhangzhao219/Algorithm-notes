#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin >> s;
    if(s.size() == 4){
        if(stoi(s.substr(0,2)) < 22){
            cout << "20";
        }
        else{
            cout << "19";
        }
        cout << s.substr(0,2);
        cout << "-";
        cout << s.substr(2,2);
    }
    else if(s.size() == 6){
        for(int i=0;i<4;i++){
            cout << s[i];
        }
        cout << "-";
        for(int i=4;i<6;i++){
            cout << s[i];
        }
    }
}