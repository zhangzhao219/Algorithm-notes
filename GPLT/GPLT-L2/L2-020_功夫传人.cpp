#include <bits/stdc++.h>
using namespace std;
struct node{
    double kung;
    int times;
    vector<int> child;
}Node[100010];

int N;
double Z,r;

int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d %lf %lf",&N,&Z,&r);
    r = (100 - r) / 100.0;
    int temp,temp2;
    for(int i=0;i<N;i++){
        scanf("%d",&temp);
        if(temp == 0){
            scanf("%d",&Node[i].times);
        }
        else{
            Node[i].times = 1;
            for(int j=0;j<temp;j++){
                scanf("%d",&temp2);
                Node[i].child.push_back(temp2);
            }
        }
    }
    double sum = 0.0;
    Node[0].kung = Z;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int f = q.front();
        if(Node[f].times != 1){
            sum += Node[f].kung * Node[f].times;
        }
        q.pop();
        for(int i=0;i<Node[f].child.size();i++){
            int tempchild = Node[f].child[i];
            Node[tempchild].kung = Node[f].kung * r;
            q.push(tempchild);
        }

    }
    printf("%d\n",int(sum));
    return 0;
}