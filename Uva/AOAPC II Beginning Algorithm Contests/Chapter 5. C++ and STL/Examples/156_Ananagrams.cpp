#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
vector<string> vt;
string repr(string s){
    for(int i=0;i<s.size();i++){
        s[i] = tolower(s[i]);
    }
    sort(s.begin(),s.end());
    return s;
}
int main(void){
    string s;
    while(cin >> s){
        if(s[0] == '#'){
            vector<string> ans;
            for(int i=0;i<vt.size();i++){
                if(mp[repr(vt[i])] == 1){
                    ans.push_back(vt[i]);
                }
            }
            sort(ans.begin(),ans.end());
            for(int i=0;i<ans.size();i++){
                cout << ans[i] << endl;
            }
            return 0;
        }
        else{
            vt.push_back(s);
            string r = repr(s);
            if(mp.find(r) == mp.end()){
                mp[r] = 1;
            }
            else{
                mp[r]++;
            }
        }
    }
}


/*
ladder came tape soon leader acme RIDE lone Dreis peat ScAlE orb eye Rides dealer NotE derail LaCeS drIed noel dire Disk mace Rob dries
#
*/