#include <bits/stdc++.h>
using namespace std;
int q;
vector<int> at;
vector<int> bt;
int main(void){
    scanf("%d",&q);
    long long a,b;
    while(q--){
        scanf("%lld %lld",&a,&b);
        at.clear();
        bt.clear();
        at.push_back(1);
        bt.push_back(1);
        while(a != 1){
            if(a % 2 == 0){
                a = a / 2;
                at.push_back(0);
            }
            else{
                a = (a - 1) / 2;
                at.push_back(1);
            }
        }
        reverse(at.begin(),at.end());
        while(b != 1){
            if(b % 2 == 0){
                b = b / 2;
                bt.push_back(0);
            }
            else{
                b = (b - 1) / 2;
                bt.push_back(1);
            }
        }
        reverse(bt.begin(),bt.end());
        if(at > bt){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        // for(int i=0;i<at.size();i++){
        //     printf("%d ",at[i]);
        // }
        // printf("\n");
        // for(int i=0;i<bt.size();i++){
        //     printf("%d ",bt[i]);
        // }
        // printf("\n");
    }
    return 0;
}