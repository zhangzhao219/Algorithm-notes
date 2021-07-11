#include <bits/stdc++.h>
using namespace std;
int n;
map<long long,int> mp;
int main(void){
    scanf("%d",&n);
    mp[1] = 1;
    for(long long i=1;i<=100000;i++){
        if(i % 2 == 0){
            mp[i/2*(i+1)+1] = 1;
        }
        else{
            mp[(i+1)/2*i+1] = 1;
        }
    }
    int t;
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        if(mp.find(t) == mp.end()){
            printf("0\n");
        }
        else{
            printf("1\n");
        }
    }
    return 0;
}