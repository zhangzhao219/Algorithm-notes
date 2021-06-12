#include <bits/stdc++.h>
using namespace std;

map<char,char> mp;

bool judgepa(string s){
    string t = s;
    reverse(s.begin(),s.end());
    if(t == s){
        return true;
    }
    else{
        return false;
    }
}

bool judgem(string s){
    for(int i=0;i<=s.size()/2;i++){
        if(s[i] != mp[s[s.size() - i - 1]]){
            return false;
        }
    }
    return true;
}

int main(void){
    string s1 = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
    string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
    for(int i=0;i<s2.size();i++){
        if(s1[i] != ' '){
            mp.insert(make_pair(s2[i],s1[i]));
        }
    }
    // for(map<char,char>::iterator it = mp.begin();it != mp.end();it++){
    //     cout << it->first << " " << it->second << endl;
    // }
    string s;
    while(cin >> s){
        cout << s << " -- ";
        int a = judgepa(s);
        int b = judgem(s);
        if(!a && !b){
            cout << "is not a palindrome." << endl;
        }
        else if(a && !b){
            cout << "is a regular palindrome." << endl;
        }
        else if(!a && b){
            cout << "is a mirrored string." << endl;
        }
        else{
            cout << "is a mirrored palindrome." << endl;
        }
        cout << endl;
    }
    return 0;
}

// NOTAPALINDROME
// ISAPALINILAPASI
// 2A3MEAS
// ATOYOTA