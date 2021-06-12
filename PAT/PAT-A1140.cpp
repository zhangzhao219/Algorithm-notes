#include <bits/stdc++.h>
using namespace std;
int main(void){
    freopen("./test.in","r",stdin);
    int N;
    string s;
    cin >> s >> N;
    N--;
    while(N > 0){
        N--;
        string temp = "";
        for(int i=0;i<s.size();){
            char t = s[i];
            int count = 1;
            for(int j=i+1;j<s.size();j++){
                if(s[j] == t){
                    count++;
                }
                else{
                    break;
                }
            }
            temp = temp + t + to_string(count);
            i += count;
        }
        s = temp;
    }
    cout << s << endl;
    return 0;
}