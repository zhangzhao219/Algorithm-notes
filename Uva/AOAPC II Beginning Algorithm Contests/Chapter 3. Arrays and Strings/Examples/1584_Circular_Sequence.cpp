#include <bits/stdc++.h>
using namespace std;
int n;
int main(void){
    scanf("%d",&n);
    while(n--){
        string ori;
        string temp = "";
        cin >> ori;
        string res = ori;
        int len = ori.size();
        for(int i=0;i<len;i++){
            int x = i;
            for(int j=0;j<len;j++){
                temp += ori[x % len];
                x++;
            }
            // cout << temp << endl;
            res = min(res,temp);
            temp = "";
        }
        cout << res << endl;
    }
    return 0;
}
