#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    int layer;
    node* lchild;
    node* rchild;
};

int N;
int sign;
queue<node*> q;

void Inserttree(node* &root,int x){
    if(root == NULL){
        root = new node;
        root->data = x;
        root->lchild = NULL;
        root->rchild = NULL;
        return;
    }
    if(root->data < x){
        Inserttree(root->rchild,x);
    }
    else{
        Inserttree(root->lchild,x);
    }
}

void BFS(node* root){
    q.push(root);
    root->layer = 1;
    while(!q.empty()){
        node* top = q.front();
        q.pop();
        if(top->lchild != NULL){
            q.push(top->lchild);
            top->lchild->layer = top->layer + 1;
        }
        if(top->rchild != NULL){
            q.push(top->rchild);
            top->rchild->layer = top->layer + 1;
        }
    }
}

int BFS1(node* root,int t1,int t2){
    q.push(root);
    while(!q.empty()){
        node* top = q.front();
        q.pop();
        if(top->lchild != NULL && top->rchild != NULL && top->lchild->data == t1 && root->rchild->data == t2){
            return 1;
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

int BFS2(node* root,int t1,int t2){
    q.push(root);
    int t1layer = 0,t2layer = 0;
    while(!q.empty()){
        node* top = q.front();
        q.pop();
        if(top->data == t1){
            t1layer = top->layer;
        }
        if(top->data == t2){
            t2layer = top->layer;
        }
        if(top->lchild != NULL){
            q.push(top->lchild);
        }
        if(top->rchild != NULL){
            q.push(top->rchild);
        }
    }
    if(t1layer == t2layer && t1layer != 0){
        return 1;
    }
    return 0;
}

int BFS3(node* root,int t1,int t2){
    q.push(root);
    while(!q.empty()){
        node* top = q.front();
        q.pop();
        if(top->data == t2 && top->lchild != NULL && top->lchild->data == t1){
            return 1;
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

int BFS4(node* root,int t1,int t2){
    q.push(root);
    while(!q.empty()){
        node* top = q.front();
        q.pop();
        if(top->data == t2 && top->rchild != NULL && top->rchild->data == t1){
            return 1;
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

int BFS5(node* root,int t1,int t2){
    q.push(root);
    while(!q.empty()){
        node* top = q.front();
        q.pop();
        if(top->data == t1 && ((top->lchild != NULL && top->lchild->data == t2) || (top->rchild != NULL && top->rchild->data == t2))){
            return 1;
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

int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d",&N);
    node* root = NULL;
    int temp;
    for(int i=0;i<N;i++){
        scanf("%d",&temp);
        Inserttree(root,temp);
    }
    int times;
    scanf("%d",&times);
    int t1,t2;
    string s1,s2,s3,s4,s5;
    BFS(root);
    while(times--){
        sign = 0;
        cin >> t1 >> s1;
        if(s1 == "and"){
            cin >> t2 >> s2 >> s3;
            if(s3 == "siblings"){
                if(t1 > t2){
                    swap(t1,t2);
                }
                sign = BFS1(root,t1,t2);
            }
            else{
                cin >> s3 >> s4 >> s5;
                if(t1 > t2){
                    swap(t1,t2);
                }
                sign = BFS2(root,t1,t2);
            }
        }
        else{
            cin >> s2 >> s3;
            if(s3 == "root"){
                if(root->data == t1){
                    sign = 1;
                }
            }
            else if(s3 == "left"){
                cin >> s4 >> s5 >> t2;
                sign = BFS3(root,t1,t2);
            }
            else if(s3 == "right"){
                cin >> s4 >> s5 >> t2;
                sign = BFS4(root,t1,t2);
            }
            else{
                cin >> s4 >> t2;
                sign = BFS5(root,t1,t2);
            }
        }
        if(sign == 1){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}