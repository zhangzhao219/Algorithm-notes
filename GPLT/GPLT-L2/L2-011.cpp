#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* lchild;
    node* rchild;
};
int N;
int pre[32];
int in[32];
void createtree(node* &root,int preL,int preR,int inL,int inR){
    if(preR < preL){
        return;
    }
    root = new node;
    root->data = pre[preL];
    root->lchild = NULL;
    root->rchild = NULL;
    int index;
    for(int i=inL;i<=inR;i++){
        if(in[i] == root->data){
            index = i;
        }
    }
    int num = index - inL;
    createtree(root->lchild,preL+1,preL+num,inL,index-1);
    createtree(root->rchild,preL+num+1,preR,index+1,inR);
}
int main(void){
    freopen("./test.in","r",stdin);
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&in[i]);
    }
    for(int i=0;i<N;i++){
        scanf("%d",&pre[i]);
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
        if(top->rchild != NULL){
            q.push(top->rchild);
        }
        if(top->lchild != NULL){
            q.push(top->lchild);
        }
    }
    return 0;
}
