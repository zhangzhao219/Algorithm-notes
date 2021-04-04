#include <bits/stdc++.h>
using namespace std;
int N,M;
struct node{
    vector<int> child;
}Node[110];

int hashtable[110];
int maxlevel = 0;

void DFS(int index,int level){
    if(level > maxlevel){
        maxlevel = level;
    }
    if(Node[index].child.size() == 0){
        hashtable[level]++;
        return;
    }
    for(int i=0;i<Node[index].child.size();i++){
        int child = Node[index].child[i];
        DFS(child,level+1);
    }
    return;
}

int main(void){
    freopen("../test.in","r",stdin);
    memset(hashtable,0,sizeof(hashtable));
    scanf("%d %d",&N,&M);
    for(int i=0;i<M;i++){
        int tempnum,tempcount;
        scanf("%d %d",&tempnum,&tempcount);
        for(int j=0;j<tempcount;j++){
            int tempchild;
            scanf("%d",&tempchild);
            Node[tempnum].child.push_back(tempchild);
        }
    }
    DFS(1,0);
    for(int i=0;i<=maxlevel;i++){
        printf("%d",hashtable[i]);
        if(i != maxlevel){
            printf(" ");
        }
        else{
            printf("\n");
        }
    }
    return 0;
}