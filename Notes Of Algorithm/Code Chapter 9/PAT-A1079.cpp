#include <bits/stdc++.h>
using namespace std;
int N;
double p,r;
double totalsum = 0.0;
struct node{
    int sign;
    vector<int> child;
}Node[100010];

void DFS(int index,int layer){
    if(Node[index].sign == 0){
        double price = p * pow(1 + double(r) / 100,double(layer)) * Node[index].child[0];
        totalsum += price;
        return;
    }
    for(int i=0;i<Node[index].child.size();i++){
        int child = Node[index].child[i];
        DFS(child,layer + 1);
    }
    return;
}
int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d %lf %lf",&N,&p,&r);
    for(int i=0;i<N;i++){
        int tempnum;
        int tempchild;
        scanf("%d",&tempnum);
        if(tempnum == 0){
            scanf("%d",&tempchild);
            Node[i].child.push_back(tempchild);
            Node[i].sign = 0;
        }
        else{
            for(int j=0;j<tempnum;j++){
                scanf("%d",&tempchild);
                Node[i].child.push_back(tempchild);
                Node[i].sign = 1;
            }
        } 
    }
    DFS(0,0);
    printf("%.1f\n",totalsum);
    return 0;
}