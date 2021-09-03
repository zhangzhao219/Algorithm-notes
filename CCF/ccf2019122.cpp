#include<bits/stdc++.h>
using namespace std;
int n;
map<pair<int,int>,int> mp;
pair<int,int> num[1010];

int main(void){
    scanf("%d",&n);
    int result[5];
    for(int i=0;i<5;i++){
        result[i] = 0;
    }
    int temp1,temp2;
    for(int i=0;i<n;i++){
        scanf("%d %d",&temp1,&temp2);
        num[i] = make_pair(temp1,temp2);
        mp[num[i]] = 1;
    }
    for(int i=0;i<n;i++){
        int x = num[i].first;
        int y = num[i].second;
        if(mp[make_pair(x,y+1)] && mp[make_pair(x,y-1)] && mp[make_pair(x+1,y)] && mp[make_pair(x-1,y)]){
            result[mp[make_pair(x+1,y+1)] + mp[make_pair(x+1,y-1)] + mp[make_pair(x-1,y+1)] + mp[make_pair(x-1,y-1)]]++;
        }
    }
    for(int i=0;i<5;i++){
        printf("%d\n",result[i]);
    }
    return 0;
}
/*
7
1 2
2 1
0 0
1 1
1 0
2 0
0 1
*/