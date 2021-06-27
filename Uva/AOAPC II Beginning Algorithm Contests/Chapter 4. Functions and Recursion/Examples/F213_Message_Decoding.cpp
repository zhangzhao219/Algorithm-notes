#include <bits/stdc++.h>
using namespace std;
map<int,char> mp;
int main(void){
    char c;
    while(c = getchar() != EOF){
        string s;
        mp.clear();
        getline(cin,s);
        int index = 0;
        for(int i=0;i<s.size();i++){
            mp[index++] = s[i];
        }
        getchar();
        
    }
}
/*
TNM AEIOU
0010101100011
1010001001110110011
11000
$#**\
0100000101101100011100101000
*/