#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* lchild;
    node* rchild;
};
int N;

int preorder[1010];
int inorder[1010];

node* createtree(int preL,int preR,int inL,int inR){
    
}

int main(void){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&preorder[i]);
        inorder[i] = preorder[i];
    }
    sort(inorder + 1,inorder + N + 1);
    for(int i=1;i<=N;i++){
        printf("%d ",inorder[i]);
    }
    node* root = NULL;
    root = createtree(1,N,1,N);
    return 0;
}