#include<bits/stdc++.h>
using namespace std;
int N,M;
vector<int> vt;
int t;
int main(void){
    scanf("%d %d",&N,&M);
    int sum1 = 0;
    for(int i=0;i<N;i++){
        vt.clear();
        for(int j=0;j<M;j++){
            scanf("%d",&t);
            vt.push_back(t);
        }
        sum1 += *max_element(vt.begin(),vt.end());
    }
    printf("%d",sum1);
    return 0;
}