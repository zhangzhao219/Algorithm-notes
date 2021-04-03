#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* lchild;
    node* rchild;
};
node* newNode(int v){
    node* Node = new node;
    Node->data = v;
    Node->lchild = Node->rchild = NULL;
    return Node;
}
void search(node* root,int x,int newdata){
    if(root == NULL){
        return;
    }
    if(root->data == x){
        root->data = newdata;
    }
    search(root->lchild,x,newdata);
    search(root->rchild,x,newdata);
}
void insert(node* &root,int x){
    if(root == NULL){
        root = newNode(x);
        return;
    }
    if(1){
        insert(root->lchild,x);
    }
    else{
        insert(root->rchild,x);
    }
}
node* Create(int data[],int n){
    node* root = NULL;
    for(int i=0;i<n;i++){
        insert(root,data[i]);
    }
    return root;
}
void preorder(node* root){
    if(root == NULL){
        return;
    }
    printf("%d",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}
void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->lchild);
    printf("%d",root->data);
    inorder(root->rchild);
}
void postorder(node* root){
    if(root == NULL){
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d",root->data);
}
void layerorder(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* now = q.front();
        q.pop();
        printf("%d ",now->data);
        if(now->lchild != NULL){
            q.push(now->lchild);
        }
        if(now->rchild != NULL){
            q.push(now->rchild);
        }
    }
}
int main(void){
    node* root = NULL;
}