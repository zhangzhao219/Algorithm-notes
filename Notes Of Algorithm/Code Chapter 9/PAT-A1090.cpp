#include <bits/stdc++.h>
using namespace std;
int N;
double p,r;
double maxsum = 0.0;
int maxsumcount = 0;
struct node{
    int sign;
    vector<int> child;
}Node[100010];

vector<int> father[100010];

void DFS(int index,int layer){
    if(Node[index].child.size() == 0){
        double price = p * pow(1 + double(r) / 100,double(layer));
        if(price > maxsum){
            maxsum = price;
            maxsumcount = 1;
        }
        else if(price == maxsum){
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
    int root = -1;
    for(int i=0;i<N;i++){
        int tempnum;
        scanf("%d",&tempnum);
        if(tempnum == -1){
            root = i;
        }
        else{
            father[tempnum].push_back(i);
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<father[i].size();j++){
            Node[i].child.push_back(father[i][j]);
        }
    }
    DFS(root,0);
    printf("%.2f %d\n",maxsum,maxsumcount);
    return 0;
}