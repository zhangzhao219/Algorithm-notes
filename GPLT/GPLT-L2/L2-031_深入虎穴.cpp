#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    vector<int> child;
}Node[100010];
int N;
bool vis[100010];
int main(void){
    freopen("../test.in","r",stdin);
    memset(vis,false,sizeof(vis));
    scanf("%d",&N);
    int tempnum;
    for(int i=1;i<=N;i++){
        scanf("%d",&tempnum);
        Node[i].data = i;
        int temp2;
        for(int j=0;j<tempnum;j++){
            scanf("%d",&temp2);
            Node[i].child.push_back(temp2);
            vis[temp2] = true;
        }
    }
    int root;
    for(int i=1;i<=N;i++){
        if(vis[i] == false){
            root = i;
            break;
        }
    }
    queue<int> q;
    q.push(root);
    int result;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        result = t;
        if(Node[t].child.size() != 0){
            for(int i=0;i<Node[t].child.size();i++){
                q.push(Node[t].child[i]);
            }
        }
    }
    printf("%d\n",result);
    return 0;
}