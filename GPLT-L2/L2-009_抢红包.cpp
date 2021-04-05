#include <bits/stdc++.h>
using namespace std;
struct Node{
    int num;
    int money;
    int count1;
}node[10010];
bool cmp(Node a,Node b){
    if(a.money != b.money){
        return a.money > b.money;
    }
    else if(a.count1 != b.count1){
        return a.count1 > b.count1;
    }
    else{
        return a.num < b.num;
    }
}
int N;
int main(void){
    freopen("../test.in","r",stdin);
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        node[i].num = i;
        node[i].money = node[i].count1 = 0;
    }
    
    int tempsum,tempnum,tempmoney;
    for(int i=1;i<=N;i++){
        scanf("%d",&tempsum);
        for(int j=0;j<tempsum;j++){
            scanf("%d %d",&tempnum,&tempmoney);
            node[tempnum].money += tempmoney;
            node[tempnum].count1++;
            node[i].money -= tempmoney;
        }
    }

    
    sort(node + 1,node + N + 1,cmp);
    for(int i=1;i<=N;i++){
        printf("%d %.2f\n",node[i].num,double(node[i].money) / 100.0);
    }
    return 0;
}