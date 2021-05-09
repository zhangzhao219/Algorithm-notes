#include <bits/stdc++.h>
using namespace std;
const int MAX_LEN = 1000; // 线段树的长度

int arr[] = {1,3,5,7,9,11}; // 原始数据
int size = 6; // 原始数据的长度
int tree[MAX_LEN] = {0}; // 线段树

void buildtree(int node,int start,int end){
    if(start == end){
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    int leftnode = 2 * node;
    int rightnode = 2 * node + 1;
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
    int leftnode = 2 * node;
    int rightnode = 2 * node + 1;
    if(idx <= mid){
        updatetree(leftnode,start,mid,idx,val);
    }
    else{
        updatetree(rightnode,mid+1,end,idx,val);
    }
    tree[node] = tree[leftnode] + tree[rightnode];
}

int querytree(int node,int start,int end,int L,int R){
    if(end < L || start > R){
        return 0;
    }
    else if(start == end || (start >= L && end <= R)){
        return tree[node];
    }
    else{
        int mid = (start + end) / 2;
        int leftnode = 2 * node;
        int rightnode = 2 * node + 1;
        int sumleft = querytree(leftnode,start,mid,L,R);
        int sumright = querytree(rightnode,mid+1,end,L,R);
        return sumleft + sumright;
    }
}

int main(void){
    buildtree(1,0,5);
    for(int i=0;i<20;i++){
        printf("%d ",tree[i]);
    }
    printf("\n");
    updatetree(1,0,5,4,6);
    for(int i=0;i<20;i++){
        printf("%d ",tree[i]);
    }
    printf("\n");
    printf("%d",querytree(1,0,5,0,5));
    return 0;
}