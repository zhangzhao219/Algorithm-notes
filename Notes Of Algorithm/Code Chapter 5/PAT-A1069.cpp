#include <bits/stdc++.h>
using namespace std;
bool cmp(char a, char b){
    return a > b;
}
int main(){
    string s;
    cin >> s;
    s.insert(0, 4-s.length(), '0');
    do{
        string a = s, b = s;
        sort(a.begin(), a.end(), cmp);
        sort(b.begin(), b.end());
        int res = stoi(a) - stoi(b);
        s = to_string(res);
        s.insert(0, 4-s.length(), '0');
        cout << a <<" - " << b <<" = " << s << endl;
    }while(s != "6174" && s != "0000");
    return 0;
}

