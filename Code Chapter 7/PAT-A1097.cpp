#include <bits/stdc++.h>
using namespace std;
struct Node{
    int address;
    int data;
    int next;
    int sign;
}node[100010];

bool visit1[100010];

bool cmp(Node a,Node b){
    return a.sign < b.sign;
}

int main(void){
    freopen("../test.in","r",stdin);
    for(int i=0;i<100010;i++){
        node[i].sign = 2 * 100010;
    }
    memset(visit1,false,sizeof(visit1));
    int start,sum;
    scanf("%d %d",&start,&sum);
    for(int i=0;i<sum;i++){
        int t1,tdata,t2;
        scanf("%d %d %d",&t1,&tdata,&t2);
        node[t1].address = t1;
        node[t1].data = tdata;
        node[t1].next = t2;
    }
    int valid = 0;
    int error = 0;
    for(int p=start;p!=-1;p=node[p].next){
        if(visit1[abs(node[p].data)] == false){
            visit1[abs(node[p].data)] = true;
            node[p].sign = valid;
            valid++;
        }
        else{
            node[p].sign = 100010 + error++;
        }
    }
    sort(node,node + 100010,cmp);
    for(int i=0;i<valid + error;i++){
        if(i == valid - 1 || i == valid + error-1){
            printf("%05d %d -1\n",node[i].address,node[i].data);
        }
        else{
            printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
        }
    }
    return 0;
}