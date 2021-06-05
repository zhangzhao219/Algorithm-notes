#include <bits/stdc++.h>
using namespace std;
int N,M;
int a[100000];
map<int,vector<int> > mp;
int main(void){
    scanf("%d %d",&N,&M);
    int t1,t2;
    for(int i=0;i<N;i++){
        scanf("%d %d",&t1,&t2);
        mp[t1].push_back(t2);
        mp[t2].push_back(t1);
    }
    for(int i=0;i<M;i++){
        int sign = 0;
        int K;
        vector<int> vt;
        memset(a,0,sizeof(a));
        scanf("%d",&K);
        for(int i=0;i<K;i++){
            scanf("%d",&t1);
            vt.push_back(t1);
            a[t1] = 1;
        }
        for(int i=0;i<vt.size();i++){
            for(int j=0;j<mp[vt[i]].size();j++){
                if (a[mp[vt[i]][j]] == 1){
                    sign = 1;
                    break;
                }
            }
            if(sign == 1){
                break;
            }
        }
        if(sign == 1){
            printf("No\n");
        }
        else{
            printf("Yes\n");
        }
    }
    return 0;
}