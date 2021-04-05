#include <bits/stdc++.h>
using namespace std;
int N,K;
set<int> st[10010];
int main(void){
    scanf("%d",&N);
    int temp,temp2;
    for(int i=1;i<=N;i++){
        scanf("%d",&temp);
        for(int j=0;j<temp;j++){
            scanf("%d",&temp2);
            st[i].insert(temp2);
        }
    }
    scanf("%d",&K);
    for(int i=0;i<K;i++){
        scanf("%d %d",&temp,&temp2);
        set<int>::iterator it1;
        int count1 = 0;
        for(it1 = st[temp].begin();it1 != st[temp].end();it1++){
            if(st[temp2].find(*it1) != st[temp2].end()){
                count1++;
            }
        }
        printf("%.2f%\n",double(count1) / double(st[temp].size() + st[temp2].size() - count1) * 100);
    }
    return 0;
}