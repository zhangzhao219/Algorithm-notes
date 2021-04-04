#include <bits/stdc++.h>
using namespace std;
int n,m;
int father[110];

int findfather(int x){
    int a = x;
    while(x != father[x]){
        x = father[x];
    }
    
    while(a != father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a,int b){
    int faA = findfather(a);
    int faB = findfather(b);
    if(faA != faB){
        father[faA] = faB;
    }
    return;
}

int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        father[i] = i;
    }
    for(int i=0;i<m;i++){
        int t1,t2;
        scanf("%d %d",&t1,&t2);
        Union(t1,t2);
    }
    set<int> st;
    for(int i=1;i<=n;i++){
        st.insert(findfather(i));
    }
    printf("%d\n",st.size());
    return 0;
}