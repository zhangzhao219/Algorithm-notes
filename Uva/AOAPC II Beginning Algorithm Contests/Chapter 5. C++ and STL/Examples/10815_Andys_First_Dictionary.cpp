#include <bits/stdc++.h>
using namespace std;
set<string> st;
int main(void){
    string s;
    while(cin >> s){
        for(int i=0;i<s.size();i++){
            if(!isalpha(s[i])){
                s[i] = ' ';
            }
            else{
                s[i] = tolower(s[i]);
            }
        }
        stringstream ss(s);
        string buf;
        while(ss >> buf){
            st.insert(buf);
        }
    }
    for(set<string>::iterator it = st.begin();it != st.end();it++){
        cout << *it << endl;
    }
    return 0;
}
/*
Adventures in Disneyland

Two blondes were going to Disneyland when they came to a fork in theroad. The sign read: "Disneyland Left."

So they went home.
*/
