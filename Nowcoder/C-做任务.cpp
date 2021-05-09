#include <bits/stdc++.h>
using namespace std;
int n;
stack<int> a[6];

int main(void){
    scanf("%d",&n);
    int t;
    for(int i=1;i<=n;i++){
        scanf("%d",&t);
        a[t].push(i);
        if(!a[1].empty() && !a[2].empty() && !a[3].empty() && !a[4].empty() && !a[5].empty()){
            printf("%d %d %d %d %d\n",a[1].top(),a[2].top(),a[3].top(),a[4].top(),a[5].top());
            a[1].pop();
            a[2].pop();
            a[3].pop();
            a[4].pop();
            a[5].pop();
        }
        else{
            printf("-1\n");
        }
    }
    return 0;
}