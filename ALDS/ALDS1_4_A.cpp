#include<iostream>
using namespace std;
int num[10010];
int main(void){
    int n,q;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    cin >> q;
    int sum = 0;
    for(int i=0;i<q;i++){
        int temp;
        cin >> temp;
        for(int j=0;j<n;j++){
            if(num[j] == temp){
                sum++;
                break;
            }
        }
    }
    cout << sum << endl;
    return 0;
}