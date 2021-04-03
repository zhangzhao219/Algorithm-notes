#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* lchild;
    node* rchild;
};
int inorder[32];
int preorder[32];
int postorder[32];
int countnum = 0;
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
    root->lchild = createtree(preL+1,preL + num,inL,inL + num - 1);
    root->rchild = createtree(preL + num + 1,preR,inL + num + 1,inR);
    return root;
}
void Print(node* root){
    if(root == NULL){
        return;
    }
    Print(root->lchild);
    Print(root->rchild);
    postorder[countnum++] = root->data;
}
int N;
int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d",&N);
    stack<int> st;
    int count1 = 0,count2 = 0;
    for(int i=0;i<2*N;i++){
        string s;
        cin >> s;
        if(s == "Push"){
            int temp;
            cin >> temp;
            preorder[count1++] = temp;
            st.push(temp);
        }
        else{
            inorder[count2++] = st.top();
            st.pop();
        }
    }
    node* root = createtree(0,N-1,0,N-1);
    Print(root);
    for(int i=0;i<N;i++){
        printf("%d",postorder[i]);
        if(i == N-1){
            printf("\n");
        }
        else{
            printf(" ");
        }
    }
    return 0;
}