#include<bits/stdc++.h>
using namespace std;
struct mouse{
    int weight;
    int rank;
}mouse[1010];
int main(){
    freopen("../test.in","r",stdin);
    int np,ng,order;
    scanf("%d %d",&np,&ng);
    int i;
    for(i=0;i<np;i++){
        scanf("%d",&mouse[i].weight);
    }
    queue<int> q;
    for(i=0;i<np;i++){
        scanf("%d",&order);
        q.push(order);
    }
    int temp = np,group;
    while(q.size() != 1){
        if(temp % ng == 0){
            group = temp / ng;
        }
        else{
            group = temp / ng + 1;
        }
        for(i=0;i<group;i++){
            int k = q.front();
            for(int j = 0;j < ng;j++){
                if(i * ng + j >= temp){
                    break;
                }
                int front = q.front();
                if(mouse[front].weight > mouse[k].weight){
                    k = front;
                }
                mouse[front].rank = group + 1;
                q.pop();
            }
            q.push(k);
        }
        temp = group;
    }
    mouse[q.front()].rank = 1;
    for(i=0;i<np;i++){
        printf("%d",mouse[i].rank);
        if(i != np-1){
            printf(" ");
        }
    }
    return 0;
}