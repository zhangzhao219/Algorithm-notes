#include <bits/stdc++.h>
using namespace std;
struct node{
    int layer;
    vector<int> child;
}Node[10010];
int father[10010];
bool vis[10010];
int root;

vector<int> vt;
vector<int> vttemp;
void DFS(int t){
    if(t == -1){
        return;
    }
    DFS(father[t]);
    vttemp.push_back(t);
}

int N;
int main(void){
    freopen("./test.in","r",stdin);
    scanf("%d",&N);
    if(N == 1){
        printf("1\n0");
        return 0;
    }
    memset(vis,false,sizeof(vis));
    memset(father,-1,sizeof(father));
    int tempsum;
    int tempchild;
    for(int i=0;i<N;i++){
        scanf("%d",&tempsum);
        while(tempsum--){
            scanf("%d",&tempchild);
            Node[i].child.push_back(tempchild);
            father[tempchild] = i;
            vis[tempchild] = true;
        }
    }
    for(int i=0;i<N;i++){
        if(vis[i] == false){
            root = i;
            break;
        }
    }
    int maxlayer = -1;
    queue<int> q;
    q.push(root);
    Node[root].layer = 1;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i=0;i<Node[t].child.size();i++){
            q.push(Node[t].child[i]);
            Node[Node[t].child[i]].layer = Node[t].layer + 1;
            maxlayer = max(Node[Node[t].child[i]].layer,maxlayer);
        }
    }
    printf("%d\n",maxlayer);
    
    for(int i=0;i<N;i++){
        if(Node[i].layer == maxlayer){
            DFS(i);
            if(vt.size() == 0 || vttemp < vt){
                vt = vttemp;
            }
            vttemp.clear();
        }
    }
    for(int i=0;i <vt.size();i++){
        printf("%d",vt[i]);
        if(i == vt.size() - 1){
            printf("\n");
        }
        else{
            printf(" ");
        }
    }
    return 0;
}