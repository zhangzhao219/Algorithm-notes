#include <bits/stdc++.h>
using namespace std;
int father[510];
bool vis[510];
int exist[510];
struct edge{
    int f;
    int l;
    bool ju;
}Edge[5010];
int findfather(int x){
    int a = x;
    while(x != father[x]){
        x = father[x];
    }
    while(a != father[a]){
        int z = a;
        a = father[a];
        father[a] = x;
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
    memset(vis,false,sizeof(vis));
    memset(exist,0,sizeof(exist));
    int N,M;
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        father[i] = i;
    }
    int t1,t2;
    for(int i=0;i<M;i++){
        scanf("%d %d",&t1,&t2);
        Edge[i].f = t1;
        Edge[i].l = t2;
        Edge[i].ju = false;
        exist[t1]++;
        exist[t2]++;
        Union(t1,t2);
    }
    
    set<int> st;
    for(int i=0;i<N;i++){
        if(exist[i] != 0){
            st.insert(findfather(i));
        }
    }
    int num = st.size();
    int times;
    scanf("%d",&times);
    while(times--){
        st.clear();
        scanf("%d",&t1);
        for(int i=0;i<N;i++){
            father[i] = i;
        }
        for(int i=0;i<M;i++){
            if(Edge[i].ju == false){
                if(Edge[i].l == t1 || Edge[i].f == t1){
                    Edge[i].ju = true;
                    exist[Edge[i].l]--;
                    exist[Edge[i].f]--;
                }
                else{
                    Union(Edge[i].l,Edge[i].f);
                }
            }  
        }
        for(int j=0;j<N;j++){
            if(exist[j] != 0){
                st.insert(findfather(j));
            }
        }
        if(num > st.size()){
            printf("Red Alert: City %d is lost!\n",t1);
            num = st.size();
        }
        else{
            printf("City %d is lost.\n",t1);
        }
    }
    if(times == -1){
        printf("Game Over.\n");
    }
    return 0;
}