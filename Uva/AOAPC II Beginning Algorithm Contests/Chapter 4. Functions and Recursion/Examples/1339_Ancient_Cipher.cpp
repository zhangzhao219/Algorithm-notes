#include <bits/stdc++.h>
using namespace std;
vector<int> numa(26);
vector<int> numb(26);
int main(void){
    string s;
    while(cin >> s){
        string s1;
        cin >> s1;
        for(int i=0;i<26;i++){
            numa[i] = 0;
            numb[i] = 0;
        }
        for(int i=0;i<s.size();i++){
            numa[s[i] - 'A']++;
            numb[s1[i] - 'A']++;
        }
        sort(numa.begin(),numa.end());
        sort(numb.begin(),numb.end());
        if(numa == numb){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}


