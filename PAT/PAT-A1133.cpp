#include <bits/stdc++.h>
using namespace std;
int start,N,K;
struct node{
    int address;
    int data;
    int next;
    int sign;
    int index;
    node(){
        sign = 1;
        index = 100000000;
    }
}Node[100010];

bool cmp(node a,node b){
    if(a.sign != b.sign){
        return a.sign < b.sign;
    }
    return a.index < b.index;
}

int main(void){
    scanf("%d %d %d",&start,&N,&K);
    int t1,t2,t3;
    for(int i=0;i<N;i++){
        scanf("%d %d %d",&t1,&t2,&t3);
        Node[t1].address = t1;
        Node[t1].data = t2;
        Node[t1].next = t3;
        if(t2 < 0){
            Node[t1].sign = -1;
        }
        if(t2 >= 0 && t2 <= K){
            Node[t1].sign = 0;
        }
    }
    if(N == 1){
        printf("%05d %d -1\n",Node[start].address,Node[start].data);
        return 0;
    }
    int count1 = 0;
    for(int i=start;i != -1;i = Node[i].next){
        Node[i].index = count1;
        count1++;
    }
    sort(Node,Node + 100010,cmp);
    for(int i=0;i<N;i++){
        printf("%05d %d ",Node[i].address,Node[i].data);
        if(i != N-1){
            printf("%05d\n",Node[i+1].address);
        }
        else{
            printf("-1\n");
        }
    }
    return 0;
}