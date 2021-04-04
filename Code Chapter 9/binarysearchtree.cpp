#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* lchild;
    node* rchild;
};
void search(node* root,int x){
    if(root == NULL){
        printf("Failed!");
    }
    if(root->data== x){
        printf("OK");
    }
    else if(root->data < x){
        search(root->rchild,x);
    }
    else{
        search(root->lchild,x);
    }
    return;

}
void insert(node* &root,int x){
    if(root == NULL){
        root = new node;
        root->lchild = NULL;
        root->rchild = NULL;
        root->data = x;
        return;
    }
    if(root->data == x){
        return;
    }
    else if(x < root->data){
        insert(root->lchild,x);
    }
    else{
        insert(root->rchild,x);
    }
}
node* findmax(node* root){
    while(root->rchild != NULL){
        root = root->rchild;
    }
    return root;
}
node* findmin(node* root){
    while(root->lchild != NULL){
        root = root->lchild;
    }
    return root;
}
void deletenode(node* &root,int x){
    if(root == NULL){
        return;
    }
    if(root->data == x){
        if(root->lchild == NULL && root->rchild == NULL){
            root = NULL;
        }
        else if(root->lchild != NULL){
            node* pre = findmax(root->lchild);
            root->data = pre->data;
            deletenode(root->lchild,pre->data);
        }
        else{
            node* pre = findmin(root->rchild);
            root->data = pre->data;
            deletenode(root->rchild,pre->data);
        }
    }
    else if(x < root->data){
        deletenode(root->lchild,x);
    }
    else{
        deletenode(root->rchild,x);
    }
}
int main(void){
    printf("1");
    return 0;
}