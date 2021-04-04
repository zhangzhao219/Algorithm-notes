#include <bits/stdc++.h>
using namespace std;

int N,M,S;
int path[110];

struct node{
    int weight;
    vector<int> child;
}Node[110];

bool cmp(int a,int b){
    return Node[a].weight > Node[b].weight;
}

void DFS(int root,int numNode,int sumweight){
    // printf("%d ",sumweight);
    if(sumweight > S){
        return;
    }
    if(sumweight == S){
        if(Node[root].child.size() != 0){
            return;
        }
        for(int i=0;i<numNode;i++){
            printf("%d",Node[path[i]].weight);
            if(i == numNode - 1){
                printf("\n");
            }
            else{
                printf(" ");
            }
        }
        return;
    }
    for(int i=0;i<Node[root].child.size();i++){
        int child = Node[root].child[i];
        path[numNode] = child;
        DFS(child,numNode+1,sumweight+Node[child].weight);
    }
}



int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d %d %d",&N,&M,&S);
    for(int i=0;i<N;i++){
        scanf("%d",&Node[i].weight);
    }
    for(int i=0;i<M;i++){
        int temp,si;
        scanf("%d %d",&temp,&si);
        for(int j=0;j<si;j++){
            int temp2;
            scanf("%d",&temp2);
            Node[temp].child.push_back(temp2);
            sort(Node[temp].child.begin(),Node[temp].child.end(),cmp);
        }
    }
    path[0] = 0;
    
    DFS(0,1,Node[0].weight);
    return 0;
}