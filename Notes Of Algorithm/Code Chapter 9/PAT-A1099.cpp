#include <bits/stdc++.h>
using namespace std;
int N;
struct node{
    int data;
    int lchild;
    int rchild;
}Node[110];
vector<int> vi;

int count1 = 0;
void inorder(int root){
    if(root == -1){
        return;
    }
    inorder(Node[root].lchild);
    Node[root].data = vi[count1++];
    inorder(Node[root].rchild);
}

int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d",&N);
    int root = 0;
    for(int i=0;i<N;i++){
        int t1,t2;
        scanf("%d %d",&t1,&t2);
        Node[i].lchild = t1;
        Node[i].rchild = t2;
    }
    for(int i=0;i<N;i++){
        int temp;
        scanf("%d",&temp);
        vi.push_back(temp);
    }
    sort(vi.begin(),vi.end());
    inorder(root);
    int count2 = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int t = q.front();
        printf("%d",Node[t].data);
        count2++;
        if(count2 != N){
            printf(" ");
        }
        else{
            printf("\n");
        }
        q.pop();
        if(Node[t].lchild != -1){
            q.push(Node[t].lchild);
        }
        if(Node[t].rchild != -1){
            q.push(Node[t].rchild);
        }
    }
    return 0;
}