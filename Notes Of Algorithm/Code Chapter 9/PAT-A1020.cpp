#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* lchild;
    Node* rchild;
};

int sum;
int post[32];
int in[32];

Node* Createtree(int postL,int postR,int inL,int inR){
    if(postL > postR){
        return NULL;
    }
    Node* root = new Node;
    root->data = post[postR];
    int k;
    for(k = inL;k<=inR;k++){
        if(in[k] == root->data){
            break;
        }
    }
    int num = k - inL;
    root->lchild = Createtree(postL,postL + num - 1,inL,k-1);
    root->rchild = Createtree(postL + num,postR-1,k+1,inR);
    return root;
}

int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d",&sum);
    for(int i=1;i<=sum;i++){
        scanf("%d",&post[i]);
    }
    for(int i=1;i<=sum;i++){
        scanf("%d",&in[i]);
    }
    Node* root = Createtree(1,sum,1,sum);
    int count1 = 0;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* now = q.front();
        printf("%d",now->data);
        count1++;
        if(count1 == sum){
            printf("\n");
        }
        else{
            printf(" ");
        }
        q.pop();
        if(now->lchild != NULL){
            q.push(now->lchild);
        }
        if(now->rchild != NULL){
            q.push(now->rchild);
        }
    }
    return 0;
}