#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;

struct SegmentTree{
    int l,r;
    long long v,add,mul; // v为结果，add存储和的懒标记，mul存储积的懒标记
}tree[4*maxn];

long long w[maxn];
int n,m,p; // p是余数

// 自底向上更新信息
void update(int node){
    tree[node].v = (tree[node * 2].v + tree[node * 2 + 1].v) % p;
}

// 懒标记
void lazy_tag(int node){
    int leftnode = node * 2;
    int rightnode = node * 2 + 1;

    int mid = (tree[node].l + tree[node].r) / 2;

    // 更新结果
    tree[leftnode].v = (tree[leftnode].v * tree[node].mul + tree[node].add * (mid - tree[node].l + 1)) % p;
    tree[rightnode].v = (tree[rightnode].v * tree[node].mul + tree[node].add * (tree[node].r - mid)) % p;

    // 更新积的懒标记
    tree[leftnode].mul = (tree[leftnode].mul * tree[node].mul) % p;
    tree[rightnode].mul = (tree[rightnode].mul * tree[node].mul) % p;

    // 更新和的懒标记
    tree[leftnode].add = (tree[leftnode].add * tree[node].mul + tree[node].add) % p;
    tree[rightnode].add = (tree[rightnode].add * tree[node].mul + tree[node].add) % p;

    // 懒标记初始化
    tree[node].mul = 1;
    tree[node].add = 0;

    return;
}

// 建立线段树
void buildtree(int node,int start,int end){
    tree[node].l = start;
    tree[node].r = end;
    tree[node].add = 0;
    tree[node].mul = 1;
    if(start == end){
        tree[node].v = w[start];
        tree[node].v %= p;
    }
    else{
        int mid = (start + end) / 2;
        // 递归建立左子树
        buildtree(node * 2,start,mid);
        // 递归建立右子树
        buildtree(node * 2 + 1,mid+1,end);
        update(node);
    }
}

// 区间查询
long long ask_interval(int node,int start,int end){
    if(tree[node].l >= start && tree[node].r <= end){
        return tree[node].v % p;
    }
    else if(tree[node].r < start || tree[node].l > end){
        return 0;
    }
    else{
        lazy_tag(node);
        int mid = (tree[node].l + tree[node].r) / 2;
        long long res = 0;
        if(start <= mid){
            res += ask_interval(node * 2,start,end);
        }
        if(end > mid){
            res += ask_interval(node * 2 + 1,start,end);
        }
        return res % p;
    }
}

// 区间乘法修改
void change_interval_mul(int node,int start,int end,long long val){
    // 完全被包含
    if(tree[node].l >= start && tree[node].r <= end){
        tree[node].v = (tree[node].v * val) % p;
        tree[node].mul = (tree[node].mul * val) % p;
        tree[node].add = (tree[node].add * val) % p;
        return;
    }
    // 不被包含
    else if(tree[node].r < start || tree[node].l > end){
        return;
    }
    // 不完全被包含
    else{
        lazy_tag(node); // 向下操作，先更新懒标记
        int mid = (tree[node].l + tree[node].r) / 2;
        // 操作左半边区间
        if(start <= mid){
            change_interval_mul(node * 2,start,end,val);
        }
        // 操作右半边区间
        if(end > mid){
            change_interval_mul(node * 2 + 1,start,end,val);
        }
        update(node);
    }
}

// 区间加法修改
void change_interval_add(int node,int start,int end,long long val){
    // 完全被包含
    if(tree[node].l >= start && tree[node].r <= end){
        tree[node].v = (tree[node].v + (tree[node].r - tree[node].l + 1) * val) % p;
        tree[node].add = (tree[node].add + val) % p;
        return;
    }
    // 不被包含
    else if(tree[node].r < start || tree[node].l > end){
        return;
    }
    // 不完全被包含
    else{
        lazy_tag(node); // 向下操作，先更新懒标记
        int mid = (tree[node].l + tree[node].r) / 2;
        // 操作左半边区间
        if(start <= mid){
            change_interval_add(node * 2,start,end,val);
        }
        // 操作右半边区间
        if(end > mid){
            change_interval_add(node * 2 + 1,start,end,val);
        }
        update(node);
    }
}

int main(void){
    scanf("%d %d %d",&n,&m,&p);
    for(int i=1;i<=n;i++){
        scanf("%lld",&w[i]);
    }
    buildtree(1,1,n);
    while(m--){
        int kind,x,y;
        long long k;
        scanf("%d",&kind);
        if(kind == 1){
            scanf("%d %d %lld",&x,&y,&k);
            change_interval_mul(1,x,y,k);
        }
        else if(kind == 2){
            scanf("%d %d %lld",&x,&y,&k);
            change_interval_add(1,x,y,k);
        }
        else{
            scanf("%d %d",&x,&y);
            printf("%lld\n",ask_interval(1,x,y));
        }
    }
    return 0;
}