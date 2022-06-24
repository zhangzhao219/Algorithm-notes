#include <bits/stdc++.h>
using namespace std;
int N,D;

struct Node{
    double ton;
    double price;
}node[1010];

bool cmp(Node a,Node b){
    return a.price > b.price;
}

int main(void){
    scanf("%d %d",&N,&D);
    double temp;
    for(int i=0;i<N;i++){
        scanf("%lf",&node[i].ton);
    }
    for(int i=0;i<N;i++){
        scanf("%lf",&temp);
        node[i].price = temp / node[i].ton;
    }
    sort(node,node + N,cmp);
    double sum = 0.0;
    int count1= 0;
    while(D > 0){
        if(D - node[count1].ton >= 0){
            D -= node[count1].ton;
            sum += node[count1].ton * node[count1].price;
        }
        else{
            sum += node[count1].price * D;
            D = 0;
        }
        count1++;
        if(count1 >= N){
            break;
        }
    }
    printf("%.2f\n",sum);
    return 0;
}