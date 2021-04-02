#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    getline(cin,s);
    int num = 0;
    string s1 = "";
    string s2 = "";
    int sign = 0;
    if(s[0] == ' '){
        s1 = "?";
    }
    else{
        while(s[num] != ' '){
        if(s[num] <= '9' && s[num] >= '0'){
            s1 += s[num];
        }
        else{
            sign = 1;
        }
        num++;
        }
        if(sign == 1){
            s1 = "?";
        }
    }
    
    sign = 0;
    num++;
    while(s[num] != ' ' && num < s.size()){
        if(s[num] <= '9' && s[num] >= '0'){
            s2 += s[num];
        }
        else{
            sign = 1;
        }
        num++;
    }
    if(sign == 1){
        s2 = "?";
    }
    if(num != s.size()){
        s2 = "?";
    }

    if(s1 != "?" && s2 != "?"){
        if(stoi(s1) < 1 || stoi(s1) > 1000){
            s1 = "?";
        }
        else if(stoi(s2) < 1 || stoi(s2) > 1000){
            s2 = "?";
        }
        else{
            cout << s1 << " + " << s2 << " = " << stoi(s1) + stoi(s2) << endl;
            return 0;
        }
        
    }
    cout << s1 << " + " << s2 << " = " << "?" << endl;
    return 0;
}