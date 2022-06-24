#include <bits/stdc++.h>
using namespace std;
vector<int> vt;

int n,q;

int main(void){
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        vt.push_back(i);
    }
    int t1,t2;
    while(q--){
        scanf("%d %d",&t1,&t2);
        int num;
        for(int i=0;i<vt.size();i++){
            if(vt[i] == t1){
                num = i;
                break;
            }
        }
        int start = min(int(vt.size()-1),num+t2);
        int j = start;
        while(start >= num){
            vt.insert(vt.begin(),vt[j]);
            vector<int>::iterator it = vt.begin() + j + 1;
            vt.erase(it);
            start--;
        }
    }
    for(int i=0;i<vt.size();i++){
        printf("%d ",vt[i]);
    }
    return 0;
}