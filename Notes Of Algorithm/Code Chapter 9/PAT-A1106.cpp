#include <bits/stdc++.h>
using namespace std;
int N;
double p,r;
double minsum = 10000000001.0;
int maxsumcount = 0;
struct node{
    int sign;
    vector<int> child;
}Node[100010];

vector<int> father[100010];

void DFS(int index,int layer){
    if(Node[index].child.size() == 0){
        double price = p * pow(1 + double(r) / 100,double(layer));
        if(price < minsum){
            minsum = price;
            maxsumcount = 1;
        }
        else if(price == minsum){
            maxsumcount++;
        }
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
        scanf("%d",&tempnum);
        for(int j=0;j<tempnum;j++){
            int tempchild;
            scanf("%d",&tempchild);
            Node[i].child.push_back(tempchild);
        }
    }
    DFS(0,0);
    printf("%.4f %d\n",minsum,maxsumcount);
    return 0;
}