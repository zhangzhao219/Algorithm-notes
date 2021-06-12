#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* lchild;
    node* rchild;
};
int N;
int rightchild[15];
int leftchild[15];
bool have[15];
int rootdata;
int countnum1 = 0;

node* createtree(int data){
    if(data == -1){
        return NULL;
    }
    node* root = new node;
    root->data = data;
    root->lchild = createtree(leftchild[data]);
    root->rchild = createtree(rightchild[data]);
    return root;
}

void printinorder(node* root){
    if(root == NULL){
        return;
    }
    printinorder(root->lchild);
    printf("%d",root->data);
    countnum1++;
    if(countnum1 == N){
        printf("\n");
    }
    else{
        printf(" ");
    }
    printinorder(root->rchild);
}

int main(void){
    freopen("../test.in","r",stdin);
    memset(have,false,sizeof(have));
    scanf("%d",&N);
    getchar();
    for(int i=0;i<N;i++){
        char c1,c2;
        scanf("%c %c\n",&c1,&c2);
        if(c1 <= '9' && c1 >= '0'){
            rightchild[i] = c1 - '0';
            have[rightchild[i]] = true;
        }
        else{
            rightchild[i] = -1;
        }
        if(c2 <= '9' && c2 >= '0'){
            leftchild[i] = c2 - '0';
            have[leftchild[i]] = true;
        }
        else{
            leftchild[i] = -1;
        }
    }
    for(int i=0;i<15;i++){
        if(have[i] == false){
            rootdata = i;
            break;
        }
    }
    node* root = createtree(rootdata);
    int countnu2 = 0;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* now = q.front();
        printf("%d",now->data);
        q.pop();
        countnu2++;
        if(countnu2 == N){
            printf("\n");
        }
        else{
            printf(" ");
        }
        if(now->lchild != NULL){
            q.push(now->lchild);
        }
        if(now->rchild != NULL){
            q.push(now->rchild);
        }
    }
    printinorder(root);

    return 0;

}