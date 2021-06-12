#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* lchild;
    node* rchild;
};
int N;
vector<int> original;

void createtree(node* &root,int x){
    if(root == NULL){
        root = new node;
        root->data = x;
        root->lchild = NULL;
        root->rchild = NULL;
        return;
    }
    if(root->data > x){
        createtree(root->lchild,x);
    }
    else{
        createtree(root->rchild,x);
    }
}
vector<int> preordervt;
void preorder(node* root){
    if(root == NULL){
        return;
    }
    preordervt.push_back(root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}

vector<int> preordervtM;
void preorderM(node* root){
    if(root == NULL){
        return;
    }
    preordervtM.push_back(root->data);
    preorderM(root->rchild);
    preorderM(root->lchild);
}

vector<int> postordervt;
void postorder(node* root){
    if(root == NULL){
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    postordervt.push_back(root->data);
}

vector<int> postordervtM;
void postorderM(node* root){
    if(root == NULL){
        return;
    }
    postorderM(root->rchild);
    postorderM(root->lchild);
    postordervtM.push_back(root->data);
}

int main(void){
    freopen("./test.in","r",stdin);
    scanf("%d",&N);
    node* root = NULL;
    int temp;
    for(int i=0;i<N;i++){
        scanf("%d",&temp);
        original.push_back(temp);
        createtree(root,temp);
    }
    preorder(root);
    if(preordervt == original){
        printf("YES\n");
        postorder(root);
        for(int i=0;i<postordervt.size();i++){
            printf("%d",postordervt[i]);
            if(i != postordervt.size()-1){
                printf(" ");
            }
            else{
                printf("\n");
            }
        }
    }
    else{
        preorderM(root);
        if(preordervtM == original){
            printf("YES\n");
            postorderM(root);
            for(int i=0;i<postordervtM.size();i++){
                printf("%d",postordervtM[i]);
                if(i != postordervtM.size()-1){
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
    }
    return 0;
}