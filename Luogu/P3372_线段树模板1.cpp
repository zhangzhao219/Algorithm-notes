#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;

// 线段树结构
struct SegmentTree{
    int l,r; // 区间的左右端点
    long long sum,add; // sum存储求和结果，add懒标记
}tree[4*maxn]; // 开四倍大小

int w[maxn]; // 原始数据

int n,m; // 题目给的总数和询问次数

// 自底向上更新信息
void update(int node){
    // 结点的总和 = 左孩子的总和 + 右孩子的总和
    tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
}

// 懒标记
void lazy_tag(int node){
    // 左孩子结点
    int leftnode = node * 2;
    // 右孩子结点
    int rightnode = node * 2 + 1;
    // 如果懒标记不为0
    if(tree[node].add){
        // 将懒标记传递给左孩子
        tree[leftnode].add += tree[node].add;
        // 左孩子的总和 = 左孩子的总和 + 传递下来的懒标记 * 左孩子的区间 （每一个都要加）
        tree[leftnode].sum += (long long)(tree[leftnode].r - tree[leftnode].l + 1) * tree[node].add;
        // 将懒标记传递给右孩子
        tree[rightnode].add += tree[node].add;
        // 右孩子的总和 = 右孩子的总和 + 传递下来的懒标记 * 右孩子的区间 （每一个都要加）
        tree[rightnode].sum += (long long)(tree[rightnode].r - tree[rightnode].l + 1) * tree[node].add;
        // 懒标记置为0
        tree[node].add = 0;
    }
    return;
}

// 建立线段树
void buildtree(int node,int start,int end){
    // 结点信息的初始化
    tree[node].l = start;
    tree[node].r = end;
    tree[node].add = 0;
    // start == end 说明找到了叶子结点
    if(start == end){
        // 叶子结点的和是它本身
        tree[node].sum = w[start];
        return;
    }
    else{
        int mid = (start + end) / 2;
        // 递归建立左子树
        buildtree(node * 2,start,mid);
        // 递归建立右子树
        buildtree(node * 2 + 1,mid+1,end);
        // 更新信息
        update(node);
    }
}

//单点查询
int ask_point(int node,int x){
    // 找到了叶子结点，返回叶子结点的值
    if(tree[node].l == tree[node].r){
        return tree[node].sum;
    }
    // 将懒标记下传
    lazy_tag(node);
    int mid=(tree[node].l + tree[node].r) / 2;
    // 向左孩子方向继续寻找
    if(x <= mid){
        ask_point(node * 2,x);
    }
    // 向右孩子方向继续寻找
    else{
        ask_point(node*2 + 1,x);
    }
}

// 单点修改
void change_point(int node,int x,int y){
    // 找到了叶子结点，更改掉叶子结点的值
    if(tree[node].l == tree[node].r){
        tree[x].sum = y;
        return;
    }
    // 将懒标记下传
    lazy_tag(node);
    int mid = (tree[node].l + tree[node].r) / 2;
    if(x <= mid){
        change_point(node * 2,x,y);
    }
    else{
        change_point(node * 2 + 1,x,y);
    }
    // 自底向上更新信息
    update(node);
}

// 区间查询
long long ask_interval(int node,int start,int end){
    // 完全被包含直接返回总和
    if(tree[node].l >= start && tree[node].r <= end){
        return tree[node].sum;
    }
    // 不被包含
    else if(tree[node].r < start || tree[node].l > end){
        return 0;
    }
    else{
        // 更新懒标记
        lazy_tag(node);
        int mid = (tree[node].l + tree[node].r) / 2;
        long long res = 0;
        if(start <= mid){
            res += ask_interval(node * 2,start,end);
        }
        if(end > mid){
            res += ask_interval(node * 2 + 1,start,end);
        }
        return res;
    }
}

// 区间更新
void change_interval(int node,int start,int end,int val){
    // 完全被包含
    if(tree[node].l >= start && tree[node].r <= end){
        // 更改懒标记
        tree[node].add += val;
        // 更新结点的总和 = 结点的区间 * 更新的值
        tree[node].sum += (long long)(tree[node].r - tree[node].l + 1) * val;
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
            change_interval(node * 2,start,end,val);
        }
        // 操作右半边区间
        if(end > mid){
            change_interval(node * 2 + 1,start,end,val);
        }
        // 更新信息
        update(node);
    }
}


int main(void){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    buildtree(1,1,n);
    while(m--){
        int kind,x,y,k;
        scanf("%d",&kind);
        if(kind == 1){
            scanf("%d %d %d",&x,&y,&k);
            change_interval(1,x,y,k);
        }
        else{
            scanf("%d %d",&x,&y);
            printf("%lld\n",ask_interval(1,x,y));
        }
    }
    return 0;
}