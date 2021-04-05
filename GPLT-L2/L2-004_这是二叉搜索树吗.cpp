#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* lchild;
    node* rchild;
};

vector<int> origin;

void inserttree(node* &root,int x){
    if(root == NULL){
        root = new node;
        root->lchild = NULL;
        root->rchild = NULL;
        root->data = x;
        return;
    }
    if(x < root->data){
        inserttree(root->lchild,x);
    }
    else{
        inserttree(root->rchild,x);
    }
}

vector<int> preorder;
void preprint(node* root){
    if(root == NULL){
        return;
    }
    preorder.push_back(root->data);
    preprint(root->lchild);
    preprint(root->rchild);
}

vector<int> preorderM;
void preprintM(node* root){
    if(root == NULL){
        return;
    }
    preorderM.push_back(root->data);
    preprintM(root->rchild);
    preprintM(root->lchild);
}

vector<int> postorder;
void postprint(node* root){
    if(root == NULL){
        return;
    }
    postprint(root->lchild);
    postprint(root->rchild);
    postorder.push_back(root->data);
}

vector<int> postorderM;
void postprintM(node* root){
    if(root == NULL){
        return;
    }
    postprintM(root->rchild);
    postprintM(root->lchild);
    postorderM.push_back(root->data);
}


int main(void){
    // freopen("../test.in","r",stdin);
    int N;
    node* root = NULL;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int temp;
        scanf("%d",&temp);
        origin.push_back(temp);
        inserttree(root,temp);
    }
    preprint(root);
    preprintM(root);
    postprint(root);
    postprintM(root);

    if(origin == preorder){
        printf("YES\n");
        for(int i=0;i<postorder.size();i++){
            printf("%d",postorder[i]);
            if(i != postorder.size() - 1){
                printf(" ");
            }
            else{
                printf("\n");
            }
        }
    }
    else if(origin == preorderM){
        printf("YES\n");
        for(int i=0;i<postorderM.size();i++){
            printf("%d",postorderM[i]);
            if(i != postorderM.size() - 1){
                printf(" ");
            }
            else{
                printf("\n");
            }
        }
    }
    else{
        printf("NO\n");
    }
    
    return 0;
}