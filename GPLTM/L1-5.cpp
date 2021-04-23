#include <bits/stdc++.h>
using namespace std;
int main(void){
    string a;
    getline(cin,a);
    for(int i=0;i<a.size();i++){
        if(a[i] != '6'){
            cout << a[i];
        }
        else{
            int count6 = 1;
            for(int j=i+1;j<a.size();j++){
                if(a[j] == '6'){
                    count6++;
                }
                else{
                    break;
                }
            }
            if(count6 > 9){
                cout << "27";
                i += count6 - 1;
            }
            else if(count6 > 3){
                cout << "9";
                i += count6 - 1;
            }
            else{
                cout << a[i];
            }
        }
    }
    return 0;
}