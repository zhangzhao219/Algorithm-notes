#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    int t1,t2;
    int sum;
    scanf("%d",&sum);
    while(sum--){
        cin >> s >> t1 >> t2;
        if(((t1 < 15) || (t1 >20 )) || ((t2 < 50)||(t2 > 70))){
            cout << s << endl;
        }
    }
    return 0;
}