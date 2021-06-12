#include <bits/stdc++.h>
using namespace std;
int N;
struct node{
    int data;
    node* lchild;
    node* rchild;
};
int inorder[32];
int preorder[32];

node* createtree(int preL,int preR,int inL,int inR){
    if(preL > preR){
        return NULL;
    }
    node* root = new node;
    root->data = preorder[preL];
    int k;
    for(k=inL;k<=inR;k++){
        if(inorder[k] == root->data){
            break;
        }
    }
    int num = k - inL;
    root->lchild = createtree(preL + 1,preL + num,inL,inL + num - 1);
    root->rchild = createtree(preL + num + 1,preR,inL + num + 1,inR);
    return root;
}

int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d",&N);
    int temp;
    for(int i=0;i<N;i++){
        scanf("%d",&inorder[i]);
    }
    for(int i=0;i<N;i++){
        scanf("%d",&preorder[i]);
    }

    node* root = createtree(0,N-1,0,N-1);
    
    int count1 = 0;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* newnode = q.front();
        printf("%d",newnode->data);
        count1++;
        if(count1 == N){
            printf("\n");
        }
        else{
            printf(" ");
        }
        q.pop();
        if(newnode->rchild != NULL){
            q.push(newnode->rchild);
        }
        if(newnode->lchild != NULL){
            q.push(newnode->lchild);
        }

    }
    return 0;
}