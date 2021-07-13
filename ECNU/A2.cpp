#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000010;
struct SegmentTree{
    int l,r;
    long long sum,add;
}tree[4*maxn];

int w[maxn];
int K,n;

void update(int node){
    tree[node].sum = tree[node*2].sum + tree[node * 2 + 1].sum;
}

void lazy_tag(int node){
    int leftnode = node * 2;
    int rightnode = node * 2 + 1;
    if(tree[node].add){
        tree[leftnode].add += tree[node].add;
        tree[leftnode].sum += (long long)(tree[leftnode].r - tree[leftnode].l + 1) * tree[node].add;
        tree[rightnode].add += tree[node].add;
        tree[rightnode].sum += (long long)(tree[rightnode].r - tree[rightnode].l + 1) * tree[node].add;
        tree[node].add = 0;
    }
    return;
}

void buildtree(int node,int start,int end){
    tree[node].l = start;
    tree[node].r = end;
    tree[node].add = 0;
    if(start == end){
        tree[node].sum = w[start];
        return;
    }
    else{
        int mid = (start + end) / 2;
        buildtree(node*2,start,mid);
        buildtree(node*2+1,mid+1,end);
        update(node);
    }
}

int ask_point(int node){

}

int main(void){
    scanf("%d %d",&K,&n);
    int flag = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
        if(i == w[i]){
            flag = 1;
        }
    }
    if(flag == 0){
        printf("NO\n");
    }
    else{
        printf("YES\n");
    }
    buildtree(1,1,n);
    int L,R,C;
    for(int i=0;i<K-1;i++){
        scanf("%d %d %d",&L,&R,&C);
        change_interval(1,L,R,C);
        printf("%d",ask_interval(1,1,n));
    }
}