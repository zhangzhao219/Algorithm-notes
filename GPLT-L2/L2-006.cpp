#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* lchild;
    node* rchild;
};
int N;
int post[32];
int in[32];
void createtree(node* &root,int postL,int postR,int inL,int inR){
    if(postR < postL){
        return;
    }
    root = new node;
    root->data = post[postR];
    root->lchild = NULL;
    root->rchild = NULL;
    int index = 0;
    for(int i=inL;i<=inR;i++){
        if(in[i] == root->data){
            index = i;
            break;
        }
    }
    int num = index - inL;
    createtree(root->lchild,postL,postL + num - 1,inL,index - 1);
    createtree(root->rchild,postL + num,postR-1,index + 1,inR);
}
int main(void){
    freopen("./test.in","r",stdin);
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&post[i]);
    }
    for(int i=0;i<N;i++){
        scanf("%d",&in[i]);
    }
    node* root = NULL;
    createtree(root,0,N-1,0,N-1);
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* top = q.front();
        q.pop();
        printf("%d",top->data);
        N--;
        if(N == 0){
            printf("\n");
            return 0;
        }
        else{
            printf(" ");
        }
        if(top->lchild != NULL){
            q.push(top->lchild);
        }
        if(top->rchild != NULL){
            q.push(top->rchild);
        }
    }
    return 0;
}