#include <bits/stdc++.h>
using namespace std;
const int maxv = 10010;
int inorder[maxv],postorder[maxv],lch[maxv],rch[maxv];
int n;
int best,best_sum;
bool read_list(int* a){
    string line;
    if(!getline(cin,line)){
        return false;
    }
    stringstream ss(line);
    n = 0;
    int x;
    while(ss >> x){
        a[n++] = x;
    }
    return n > 0;
}
int build(int L1,int R1,int L2,int R2){
    if(L1 > R1){
        return 0;
    }
    int root = postorder[R2];
    int p = L1;
    while(inorder[p] != root){
        p++;
    }
    int cnt = p-L1;
    lch[root] = build(L1,p-1,L2,L2+cnt-1);
    rch[root] = build(p+1,R1,L2+cnt,R2-1);
    return root;
}
void dfs(int u,int sum){
    sum += u;
    if(lch[u] == 0 && rch[u] == 0){
        if(sum < best_sum || (sum == best_sum && u < best)){
            best = u;
            best_sum = sum;
        }
    }
    if(lch[u] != 0){
        dfs(lch[u],sum);
    }
    if(rch[u] != 0){
        dfs(rch[u],sum);
    }
}
int main(void){
    while(read_list(inorder)){
        read_list(postorder);
        build(0,n-1,0,n-1);
        best_sum = 1000000000;
        dfs(postorder[n-1],0);
        printf("%d\n",best);
    }
    return 0;
}
/*
3 2 1 4 5 7 6
3 1 2 5 6 7 4
7 8 11 3 5 16 12 18
8 3 11 7 16 18 12 5
255
255
*/