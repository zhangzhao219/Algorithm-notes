#include <bits/stdc++.h>
using namespace std;
int N,M;
struct node{
    int level;
    vector<int> child;
}Node[110];

int hashtable[110];

int main(void){
    freopen("../test.in","r",stdin);
    memset(hashtable,0,sizeof(hashtable));
    scanf("%d %d",&N,&M);
    for(int i=0;i<M;i++){
        int tempnum,tempcount;
        scanf("%d %d",&tempnum,&tempcount);
        for(int j=0;j<tempcount;j++){
            int temp2;
            scanf("%d",&temp2);
            Node[tempnum].child.push_back(temp2);
        }
    }
    queue<int> q;
    q.push(1);
    Node[1].level= 1;
    while(!q.empty()){
        int t = q.front();
        hashtable[Node[t].level]++;
        q.pop();
        for(int i=0;i<Node[t].child.size();i++){
            int child = Node[t].child[i];
            q.push(child);
            Node[child].level = Node[t].level + 1;
        }
    }
    int maxchild = -1;
    int sign = 0;
    for(int i=0;i<110;i++){
        if(hashtable[i] > maxchild){
            sign = i;
            maxchild = hashtable[i];
        }
    }
    printf("%d %d\n",maxchild,sign);
    return 0;
}