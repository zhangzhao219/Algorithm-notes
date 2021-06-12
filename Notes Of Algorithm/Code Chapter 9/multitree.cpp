#include <bits/stdc++.h>
#define maxn 100000
using namespace std;
struct node{
    int data;
    int layer;
    vector<int> child;
}Node[100000];
int index = 0;
int newNode(int v){
    Node[index].data= v;
    Node[index].child.clear();
    return index++;
}
void preOrder(int root){
    printf("%d ",Node[root].data);
    for(int i=0;i<Node[root].child.size();i++){
        preOrder(Node[root].child[i]);
    }
}
void layerOrder(int root){
    queue<int> q;
    q.push(root);
    Node[root].layer = 0;
    while(!q.empty()){
        int now = q.front();
        printf("%d ",Node[now].data);
        q.pop();
        for(int i=0;i<Node[now].child.size();i++){
            int child = Node[now].child[i];
            Node[child].layer = Node[now].layer + 1;
            q.push(child);
        }
    }
}
int main(void){
    


}