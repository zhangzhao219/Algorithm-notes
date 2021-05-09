#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int n;

long long arr[maxn + 10];
long long tree[5 * maxn + 10];

void buildtree(int node,int start,int end){
    if(start == end){
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    int leftnode = node * 2;
    int rightnode = node * 2 + 1;
    buildtree(leftnode,start,mid);
    buildtree(rightnode,mid+1,end);
    tree[node] = tree[leftnode] + tree[rightnode];
}

void updatetree(int node,int start,int end,int idx,int val){
    if(start == end){
        arr[idx] = val;
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    int leftnode = node * 2;
    int rightnode = node * 2 + 1;
    if(idx <= mid){
        updatetree(leftnode,start,mid,idx,val);
    }
    else{
        updatetree(rightnode,mid+1,end,idx,val);
    }
    tree[node] = tree[leftnode] + tree[rightnode];
}

long long querytree(int node,int start,int end,int L,int R){
    if(start > R || end < L){
        return 0;
    }
    else if(start == end || (start >= L && end <= R)){
        return tree[node];
    }
    else{
        int mid = (start + end) / 2;
        int leftnode = 2 * node;
        int rightnode = 2 * node + 1;
        long long sumleft = querytree(leftnode,start,mid,L,R);
        long long sumright = querytree(rightnode,mid+1,end,L,R);
        return sumleft + sumright;
    }
}

int w;
int main(void){
	freopen("./P2068_1.in","r",stdin);
	freopen("./P2068_12.out","w",stdout);
    memset(tree,0,sizeof(tree));
    memset(arr,0,sizeof(arr));
    scanf("%d %d",&n,&w);
    buildtree(1,1,n);
    while(w--){
        string s;
        int a,b;
        cin >> s >> a >> b;
        if(s == "x"){
            updatetree(1,1,n,a,b);
        }
        else{
            printf("%lld\n",querytree(1,1,n,a,b));
        }
    }
}