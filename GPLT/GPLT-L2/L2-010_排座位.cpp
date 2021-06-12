#include <bits/stdc++.h>
using namespace std;
int father[110];
set<pair<int,int> > st;
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
}
int main(void){
    freopen("../test.in","r",stdin);
    int N,M,K;
    scanf("%d %d %d",&N,&M,&K);
    for(int i=1;i<=N;i++){
        father[i] = i;
    }
    int a,b,c;
    while(M--){
        scanf("%d %d %d",&a,&b,&c);
        if(c == 1){
            Union(a,b);
        }
        else{
            st.insert(make_pair(a,b));
            st.insert(make_pair(b,a));
        }
    }
    while(K--){
        scanf("%d %d",&a,&b);
        if(findfather(a) == findfather(b) && st.find(make_pair(a,b)) == st.end()){
            printf("No problem\n");
        }
        else if(findfather(a) != findfather(b) && st.find(make_pair(a,b)) == st.end()){
            printf("OK\n");
        }
        else if(findfather(a) == findfather(b) && st.find(make_pair(a,b)) != st.end()){
            printf("OK but...\n");
        }
        else if(findfather(a) != findfather(b) && st.find(make_pair(a,b)) != st.end()){
            printf("No way\n");
        }
    }
    return 0;
}