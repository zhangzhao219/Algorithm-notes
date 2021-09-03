#include<bits/stdc++.h>
using namespace std;
int n,a,b;
map<int,int> mp;
int main(void){
    long long sum = 0;
    int temp1,temp2;
    scanf("%d %d %d",&n,&a,&b);
    for(int i=0;i<a;i++){
        scanf("%d %d",&temp1,&temp2);
        mp.insert(make_pair(temp1,temp2));
    }
    for(int i=0;i<b;i++){
        scanf("%d %d",&temp1,&temp2);
        if(mp.count(temp1) > 0){
            sum += mp[temp1] * temp2;
        }
    }
    printf("%lld\n",sum);
    return 0;
}
/*
10 3 4
4 5
7 -3
10 1
1 10
4 20
5 30
7 40
*/